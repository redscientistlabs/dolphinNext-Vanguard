#include "Core/Core.h"
#include "Core/System.h"
#include "Core/HW/Memmap.h"
#include "Core/PowerPC/Jit64Common/Jit64PowerPCState.h"
#include "Core/PowerPC/MMU.h"
#include "Core/HW/dsp.h"
#include "Core/State.h"
#include "Core/ConfigManager.h"
#include "Core/HW/dsp.h"
#include "Vanguard/VanguardHelpers.h"
#include "Vanguard/VanguardClientInitializer.h"
#include "DolphinQt/MainWindow.h"
#include <cstddef>


unsigned char Vanguard_peekbyte(long long addr, int selection)
{
  auto& system = Core::System::GetInstance();
  PowerPC::MMU& m_mmu = system.GetMMU();
  DSP::DSPManager& m_dsp = system.GetDSP();

  if (selection == 0)
    return m_mmu.Read_U8(static_cast<u32>(addr));
  else
    return m_dsp.ReadARAM(static_cast<u32>(addr));

}

void Vanguard_pokebyte(long long addr, unsigned char val, int selection)
{
  auto& system = Core::System::GetInstance();
  auto& m_mmu = system.GetMMU();
  auto& m_dsp = system.GetDSP();
  auto& ppc_State = system.GetPPCState();
  auto& memory = system.GetMemory();
  auto& jit_interface = system.GetJitInterface();
  if (selection == 0)
  {
    m_mmu.Write_U8(val, static_cast<u32>(addr));
    ppc_State.iCache.Invalidate(memory, jit_interface, addr);
    
  }
  else
  {
    m_dsp.WriteARAM(val, static_cast<u32>(addr));
  }
}

void Vanguard_savesavestate(BSTR filename, bool wait)
{
  if (Core::IsRunning(Core::System::GetInstance()))
  {
    //Convert the BSTR sent by Vanguard to std::string
    std::string filename_converted = BSTRToString(filename);
    State::SaveAs(Core::System::GetInstance(), filename_converted, wait);
  }
}

void Vanguard_loadsavestate(BSTR filename)
{
  // Convert the BSTR sent by Vanguard to std::string
  std::string filename_converted = BSTRToString(filename);
  State::LoadAs(Core::System::GetInstance(), filename_converted);
}

bool VanguardClient::loading = false;
void Vanguard_loadROM(BSTR filename)
{
  VanguardClient::loading = true;

  std::string converted_filename = BSTRToString(filename);

  SetState(Core::System::GetInstance(), Core::State::Paused);
  VanguardClientInitializer::win->StartGame(converted_filename, MainWindow::ScanForSecondDisc::No);

  MSG msg;
  // We have to do it this way to prevent deadlock due to synced calls. It sucks but it's required
  // at the moment
  while (VanguardClient::loading)
  {
    Sleep(20);
    //these lines of code perform the equivalent of the Application.DoEvents method
    ::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE);
    ::GetMessage(&msg, NULL, 0, 0);
    ::TranslateMessage(&msg);
    ::DispatchMessage(&msg);
  }

  Sleep(100);  // Give the emu thread a chance to recover
  
}

void Vanguard_finishLoading()
{
  VanguardClient::loading = false;
}

void Vanguard_prepShutdown()
{
  VanguardClientInitializer::win->m_exit_requested = true;
}

void Vanguard_forceStop()
{
  VanguardClientInitializer::win->MainWindow::ForceStopVanguard();
}

//converts a BSTR received from the Vanguard client to std::string
std::string BSTRToString(BSTR string)
{
  std::wstring ws(string, SysStringLen(string));
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string converted_string = converter.to_bytes(ws);
  return converted_string;
}

//bool VanguardClient::IsWii = false;
bool Vanguard_isWii()
{
  return Core::System::GetInstance().IsWii();
}

VanguardSettingsWrapper Vanguard_GetVanguardSettingsFromDolphin()
{
  return VanguardSettings::GetSettingsFromDolphin();
}

VanguardSettingsUnmanaged
Vanguard_GetVanguardSettingFromVanguardSettingsWrapper(VanguardSettingsWrapper vSettings)
{
  return VanguardSettings::GetSettingsFromSettingsWrapper(vSettings);
}

std::string getDirectory()
{
  char buffer[MAX_PATH] = {0};
  GetModuleFileNameA(NULL, buffer, MAX_PATH);
  std::string::size_type pos = std::string(buffer).find_last_of("\\/");
  return std::string(buffer).substr(0, pos);
}
