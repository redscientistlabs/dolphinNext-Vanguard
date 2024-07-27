#include "Core/Core.h"
#include "Core/System.h"
#include "Core/HW/Memmap.h"
#include "Core/PowerPC/Jit64Common/Jit64PowerPCState.h"
#include "Core/State.h"
#include "Core/PowerPC/MMU.h"
#include "Core/HW/dsp.h"
#include "DolphinQt/Vanguard/VanguardHelpers.h"
#include "DolphinQt/Vanguard/VanguardClientInitializer.h"
#include <codecvt>


unsigned char Vanguard_peekbyte(long long addr, int selection)
{
  auto& system = Core::System::GetInstance();
  Memory::MemoryManager& memory = system.GetMemory();
  DSP::DSPManager& m_dsp = system.GetDSP();

  // choose the correct read function based on what memory domain is requesting it
  // this is chosen from the config file
  switch (selection)
  {
  case 0:
    return memory.Read_U8(static_cast<u32>(addr));
    break;
  case 1:
    return m_dsp.ReadARAM(static_cast<u32>(addr));
    break;
  }
  return 0;
}

void Vanguard_pokebyte(long long addr, unsigned char val, int selection)
{
  auto& system = Core::System::GetInstance();
  auto& memory = system.GetMemory();
  auto& m_dsp = system.GetDSP();
  auto& ppc_State = system.GetPPCState();
  auto& jit_interface = system.GetJitInterface();

  switch (selection)
  {
  case 0:
    memory.Write_U8(val, static_cast<u32>(addr));
    ppc_State.iCache.Invalidate(memory, jit_interface, addr);
    break;
  case 1:
    m_dsp.WriteARAM(val, static_cast<u32>(addr));
    break;
  }
}

// pauses the emulator. If we're applying a corruption from cold boot,
// make sure we don't resume the emulator after loading the game.
void Vanguard_pause(bool pauseUntilCorrupt)
{
  SetState(Core::System::GetInstance(), Core::State::Paused);
  VanguardClient::pauseUntilCorrupt = pauseUntilCorrupt;
}

void Vanguard_resume()
{
  SetState(Core::System::GetInstance(), Core::State::Running);
  VanguardClient::pauseUntilCorrupt = false;
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

std::string getDirectory()
{
  char buffer[MAX_PATH] = {0};
  GetModuleFileNameA(NULL, buffer, MAX_PATH);
  std::string::size_type pos = std::string(buffer).find_last_of("\\/");
  return std::string(buffer).substr(0, pos);
}
