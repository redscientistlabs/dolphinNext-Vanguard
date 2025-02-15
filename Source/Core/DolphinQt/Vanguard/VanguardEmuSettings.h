#pragma once
#include "Core/Config/MainSettings.h"
#include "Core/Config/SYSCONFSettings.h"
#include "Core/Config/GraphicsSettings.h"
#include "DolphinQt/Vanguard/VanguardJsonParser.h"
#include <string>
#include <variant>

#define VAR_NAME(Variable) (#Variable)

using SettingsTypes = std::variant<bool, int, float>;
using SettingsArray = std::vector< std::pair<std::string, SettingsTypes>>;

class VanguardSettings
{
public:
  SettingsArray array;
  std::pair<std::string, int> MAIN_GC_LANGUAGE;
  std::pair<std::string, bool> MAIN_OVERRIDE_REGION_SETTINGS;
  std::pair<std::string, bool> MAIN_OVERCLOCK_ENABLE;
  std::pair<std::string, float> MAIN_OVERCLOCK;
  std::pair<std::string, bool> MAIN_ALLOW_SD_WRITES;
  std::pair<std::string, bool> MAIN_FPRF;
  std::pair<std::string, bool> MAIN_ACCURATE_NANS;
  std::pair<std::string, bool> MAIN_SYNC_ON_SKIP_IDLE;
  std::pair<std::string, bool> MAIN_SYNC_GPU;
  std::pair<std::string, int> MAIN_SYNC_GPU_MAX_DISTANCE;
  std::pair<std::string, int> MAIN_SYNC_GPU_MIN_DISTANCE;
  std::pair<std::string, float> MAIN_SYNC_GPU_OVERCLOCK;
  std::pair<std::string, bool> MAIN_JIT_FOLLOW_BRANCH;
  std::pair<std::string, bool> MAIN_FAST_DISC_SPEED;
  std::pair<std::string, bool> MAIN_MMU;
  std::pair<std::string, bool> MAIN_FASTMEM;

  std::pair<std::string, bool> SYSCONF_PROGRESSIVE_SCAN;
  std::pair<std::string, bool> SYSCONF_PAL60;

  std::pair<std::string, bool> GFX_HACK_EFB_ACCESS_ENABLE;
  std::pair<std::string, bool> GFX_HACK_BBOX_ENABLE;
  std::pair<std::string, bool> GFX_HACK_FORCE_PROGRESSIVE;
  std::pair<std::string, bool> GFX_HACK_SKIP_EFB_COPY_TO_RAM;
  std::pair<std::string, bool> GFX_HACK_SKIP_XFB_COPY_TO_RAM;
  std::pair<std::string, bool> GFX_HACK_DISABLE_COPY_TO_VRAM;
  std::pair<std::string, bool> GFX_HACK_IMMEDIATE_XFB;
  std::pair<std::string, bool> GFX_HACK_EFB_EMULATE_FORMAT_CHANGES;
  std::pair<std::string, int> GFX_SAFE_TEXTURE_CACHE_COLOR_SAMPLES;
  std::pair<std::string, bool> GFX_PERF_QUERIES_ENABLE;
  std::pair<std::string, bool> GFX_HACK_DEFER_EFB_COPIES;
  std::pair<std::string, int> GFX_HACK_EFB_ACCESS_TILE_SIZE;
  std::pair<std::string, bool> GFX_HACK_EFB_DEFER_INVALIDATION;
  std::pair<std::string, int> GFX_ASPECT_RATIO;
  std::pair<std::string, bool> GFX_HACK_VERTEX_ROUNDING;
  std::pair<std::string, bool> GFX_HACK_COPY_EFB_SCALED;
  std::pair<std::string, bool> GFX_FAST_DEPTH_CALC;
  std::pair<std::string, bool> GFX_ENABLE_PIXEL_LIGHTING;
  std::pair<std::string, bool> GFX_WIDESCREEN_HACK;
  std::pair<std::string, int> GFX_ENHANCE_FORCE_TEXTURE_FILTERING;
  std::pair<std::string, bool> GFX_ENHANCE_FORCE_TRUE_COLOR;
  std::pair<std::string, bool> GFX_ENHANCE_DISABLE_COPY_FILTER;
  std::pair<std::string, bool> GFX_DISABLE_FOG;
  std::pair<std::string, bool> GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION;
  std::pair<std::string, float> GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION_THRESHOLD;
  std::pair<std::string, bool> GFX_ENABLE_GPU_TEXTURE_DECODING;

  // save the current value of required settings
  void SaveSettings()
  {
    save_setting<int>(VAR_NAME(MAIN_GC_LANGUAGE), MAIN_GC_LANGUAGE, Config::MAIN_GC_LANGUAGE);

    save_setting<bool>(VAR_NAME(MAIN_OVERRIDE_REGION_SETTINGS), MAIN_OVERRIDE_REGION_SETTINGS,
                      Config::MAIN_OVERRIDE_REGION_SETTINGS);

    save_setting<bool>(VAR_NAME(MAIN_OVERCLOCK_ENABLE), MAIN_OVERCLOCK_ENABLE,
                      Config::MAIN_OVERCLOCK_ENABLE);

    save_setting<float>(VAR_NAME(MAIN_OVERCLOCK), MAIN_OVERCLOCK, Config::MAIN_OVERCLOCK);

    save_setting<bool>(VAR_NAME(MAIN_ALLOW_SD_WRITES), MAIN_ALLOW_SD_WRITES,
                       Config::MAIN_ALLOW_SD_WRITES);

    save_setting<bool>(VAR_NAME(MAIN_FPRF), MAIN_FPRF, Config::MAIN_FPRF);

    save_setting<bool>(VAR_NAME(MAIN_ACCURATE_NANS), MAIN_ACCURATE_NANS,
                       Config::MAIN_ACCURATE_NANS);

    save_setting<bool>(VAR_NAME(MAIN_SYNC_ON_SKIP_IDLE), MAIN_SYNC_ON_SKIP_IDLE,
                       Config::MAIN_SYNC_ON_SKIP_IDLE);

    save_setting<bool>(VAR_NAME(MAIN_SYNC_GPU), MAIN_SYNC_GPU, Config::MAIN_SYNC_GPU);

    save_setting<int>(VAR_NAME(MAIN_SYNC_GPU_MAX_DISTANCE), MAIN_SYNC_GPU_MAX_DISTANCE,
                       Config::MAIN_SYNC_GPU_MAX_DISTANCE);

    save_setting<int>(VAR_NAME(MAIN_SYNC_GPU_MIN_DISTANCE), MAIN_SYNC_GPU_MIN_DISTANCE,
                      Config::MAIN_SYNC_GPU_MIN_DISTANCE);

    save_setting<float>(VAR_NAME(MAIN_SYNC_GPU_OVERCLOCK), MAIN_SYNC_GPU_OVERCLOCK,
                      Config::MAIN_SYNC_GPU_OVERCLOCK);

    save_setting<bool>(VAR_NAME(MAIN_JIT_FOLLOW_BRANCH), MAIN_JIT_FOLLOW_BRANCH,
                       Config::MAIN_JIT_FOLLOW_BRANCH);

    save_setting<bool>(VAR_NAME(MAIN_FAST_DISC_SPEED), MAIN_FAST_DISC_SPEED,
                       Config::MAIN_FAST_DISC_SPEED);

    save_setting<bool>(VAR_NAME(MAIN_MMU), MAIN_MMU, Config::MAIN_MMU);

    save_setting<bool>(VAR_NAME(MAIN_FASTMEM), MAIN_FASTMEM, Config::MAIN_FASTMEM);




    save_setting<bool>(VAR_NAME(SYSCONF_PROGRESSIVE_SCAN), SYSCONF_PROGRESSIVE_SCAN,
                       Config::SYSCONF_PROGRESSIVE_SCAN);

    save_setting<bool>(VAR_NAME(SYSCONF_PAL60), SYSCONF_PAL60, Config::SYSCONF_PAL60);




    save_setting<bool>(VAR_NAME(GFX_HACK_EFB_ACCESS_ENABLE), GFX_HACK_EFB_ACCESS_ENABLE,
                       Config::GFX_HACK_EFB_ACCESS_ENABLE);

    save_setting<bool>(VAR_NAME(GFX_HACK_BBOX_ENABLE), GFX_HACK_BBOX_ENABLE,
                       Config::GFX_HACK_BBOX_ENABLE);

    save_setting<bool>(VAR_NAME(GFX_HACK_FORCE_PROGRESSIVE), GFX_HACK_FORCE_PROGRESSIVE,
                       Config::GFX_HACK_FORCE_PROGRESSIVE);

    save_setting<bool>(VAR_NAME(GFX_HACK_SKIP_EFB_COPY_TO_RAM), GFX_HACK_SKIP_EFB_COPY_TO_RAM,
                       Config::GFX_HACK_SKIP_EFB_COPY_TO_RAM);

    save_setting<bool>(VAR_NAME(GFX_HACK_SKIP_XFB_COPY_TO_RAM), GFX_HACK_SKIP_XFB_COPY_TO_RAM,
                       Config::GFX_HACK_SKIP_XFB_COPY_TO_RAM);

    save_setting<bool>(VAR_NAME(GFX_HACK_DISABLE_COPY_TO_VRAM), GFX_HACK_DISABLE_COPY_TO_VRAM,
                       Config::GFX_HACK_DISABLE_COPY_TO_VRAM);

    save_setting<bool>(VAR_NAME(GFX_HACK_IMMEDIATE_XFB), GFX_HACK_IMMEDIATE_XFB,
                       Config::GFX_HACK_IMMEDIATE_XFB);

    save_setting<bool>(VAR_NAME(GFX_HACK_EFB_EMULATE_FORMAT_CHANGES),
                       GFX_HACK_EFB_EMULATE_FORMAT_CHANGES,
                       Config::GFX_HACK_EFB_EMULATE_FORMAT_CHANGES);

    save_setting<int>(VAR_NAME(GFX_SAFE_TEXTURE_CACHE_COLOR_SAMPLES),
                       GFX_SAFE_TEXTURE_CACHE_COLOR_SAMPLES,
                       Config::GFX_SAFE_TEXTURE_CACHE_COLOR_SAMPLES);

    save_setting<bool>(VAR_NAME(GFX_PERF_QUERIES_ENABLE), GFX_PERF_QUERIES_ENABLE,
                      Config::GFX_PERF_QUERIES_ENABLE);

    save_setting<bool>(VAR_NAME(GFX_HACK_DEFER_EFB_COPIES), GFX_HACK_DEFER_EFB_COPIES,
                       Config::GFX_HACK_DEFER_EFB_COPIES);

    save_setting<int>(VAR_NAME(GFX_HACK_EFB_ACCESS_TILE_SIZE), GFX_HACK_EFB_ACCESS_TILE_SIZE,
                       Config::GFX_HACK_EFB_ACCESS_TILE_SIZE);

    save_setting<bool>(VAR_NAME(GFX_HACK_EFB_DEFER_INVALIDATION), GFX_HACK_EFB_DEFER_INVALIDATION,
                      Config::GFX_HACK_EFB_DEFER_INVALIDATION);

    save_setting<int>(VAR_NAME(GFX_ASPECT_RATIO), GFX_ASPECT_RATIO, Config::GFX_ASPECT_RATIO);

    save_setting<bool>(VAR_NAME(GFX_HACK_VERTEX_ROUNDING), GFX_HACK_VERTEX_ROUNDING,
                       Config::GFX_HACK_VERTEX_ROUNDING);

    save_setting<bool>(VAR_NAME(GFX_HACK_COPY_EFB_SCALED), GFX_HACK_COPY_EFB_SCALED,
                       Config::GFX_HACK_COPY_EFB_SCALED);

    save_setting<bool>(VAR_NAME(GFX_FAST_DEPTH_CALC), GFX_FAST_DEPTH_CALC,
                       Config::GFX_FAST_DEPTH_CALC);

    save_setting<bool>(VAR_NAME(GFX_ENABLE_PIXEL_LIGHTING), GFX_ENABLE_PIXEL_LIGHTING,
                       Config::GFX_ENABLE_PIXEL_LIGHTING);

    save_setting<bool>(VAR_NAME(GFX_WIDESCREEN_HACK), GFX_WIDESCREEN_HACK,
                       Config::GFX_WIDESCREEN_HACK);

    save_setting<int>(VAR_NAME(GFX_ENHANCE_FORCE_TEXTURE_FILTERING),
                       GFX_ENHANCE_FORCE_TEXTURE_FILTERING,
                       Config::GFX_ENHANCE_FORCE_TEXTURE_FILTERING);

    save_setting<bool>(VAR_NAME(GFX_ENHANCE_FORCE_TRUE_COLOR), GFX_ENHANCE_FORCE_TRUE_COLOR,
                      Config::GFX_ENHANCE_FORCE_TRUE_COLOR);

    save_setting<bool>(VAR_NAME(GFX_ENHANCE_DISABLE_COPY_FILTER), GFX_ENHANCE_DISABLE_COPY_FILTER,
                       Config::GFX_ENHANCE_DISABLE_COPY_FILTER);

    save_setting<bool>(VAR_NAME(GFX_DISABLE_FOG), GFX_DISABLE_FOG, Config::GFX_DISABLE_FOG);

    save_setting<bool>(VAR_NAME(GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION),
                       GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION,
                       Config::GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION);

    save_setting<float>(VAR_NAME(GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION_THRESHOLD),
                       GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION_THRESHOLD,
                       Config::GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION_THRESHOLD);

    save_setting<bool>(VAR_NAME(GFX_ENABLE_GPU_TEXTURE_DECODING), GFX_ENABLE_GPU_TEXTURE_DECODING,
                        Config::GFX_ENABLE_GPU_TEXTURE_DECODING);

  }

  // load the settings values sent from the dll hook into the emulator's settings
  void LoadSettings(JsonParser::JsonValue settings)
  {
    load_setting<int>(VAR_NAME(MAIN_GC_LANGUAGE), (*settings.json)[VAR_NAME(MAIN_GC_LANGUAGE)],
                      Config::MAIN_GC_LANGUAGE);

    load_setting<bool>(VAR_NAME(MAIN_OVERRIDE_REGION_SETTINGS),
                       (*settings.json)[VAR_NAME(MAIN_OVERRIDE_REGION_SETTINGS)],
                       Config::MAIN_OVERRIDE_REGION_SETTINGS);

    load_setting<bool>(VAR_NAME(MAIN_OVERCLOCK_ENABLE),
                       (*settings.json)[VAR_NAME(MAIN_OVERCLOCK_ENABLE)],
                       Config::MAIN_OVERCLOCK_ENABLE);

    load_setting<float>(VAR_NAME(MAIN_OVERCLOCK), (*settings.json)[VAR_NAME(MAIN_OVERCLOCK)],
                        Config::MAIN_OVERCLOCK);

    load_setting<bool>(VAR_NAME(MAIN_ALLOW_SD_WRITES),
                       (*settings.json)[VAR_NAME(MAIN_ALLOW_SD_WRITES)],
                       Config::MAIN_ALLOW_SD_WRITES);

    load_setting<bool>(VAR_NAME(MAIN_FPRF), (*settings.json)[VAR_NAME(MAIN_FPRF)],
                       Config::MAIN_FPRF);

    load_setting<bool>(VAR_NAME(MAIN_ACCURATE_NANS), (*settings.json)[VAR_NAME(MAIN_ACCURATE_NANS)],
                       Config::MAIN_ACCURATE_NANS);

    load_setting<bool>(VAR_NAME(MAIN_SYNC_ON_SKIP_IDLE),
                       (*settings.json)[VAR_NAME(MAIN_SYNC_ON_SKIP_IDLE)],
                       Config::MAIN_SYNC_ON_SKIP_IDLE);

    load_setting<bool>(VAR_NAME(MAIN_SYNC_GPU), (*settings.json)[VAR_NAME(MAIN_SYNC_GPU)],
                       Config::MAIN_SYNC_GPU);

    load_setting<int>(VAR_NAME(MAIN_SYNC_GPU_MAX_DISTANCE),
                       (*settings.json)[VAR_NAME(MAIN_SYNC_GPU_MAX_DISTANCE)],
                       Config::MAIN_SYNC_GPU_MAX_DISTANCE);

    load_setting<int>(VAR_NAME(MAIN_SYNC_GPU_MIN_DISTANCE),
                      (*settings.json)[VAR_NAME(MAIN_SYNC_GPU_MIN_DISTANCE)],
                      Config::MAIN_SYNC_GPU_MIN_DISTANCE);

    load_setting<float>(VAR_NAME(MAIN_SYNC_GPU_OVERCLOCK),
                      (*settings.json)[VAR_NAME(MAIN_SYNC_GPU_OVERCLOCK)],
                      Config::MAIN_SYNC_GPU_OVERCLOCK);

    load_setting<bool>(VAR_NAME(MAIN_JIT_FOLLOW_BRANCH),
                        (*settings.json)[VAR_NAME(MAIN_JIT_FOLLOW_BRANCH)],
                        Config::MAIN_JIT_FOLLOW_BRANCH);

    load_setting<bool>(VAR_NAME(MAIN_FAST_DISC_SPEED),
                       (*settings.json)[VAR_NAME(MAIN_FAST_DISC_SPEED)],
                       Config::MAIN_FAST_DISC_SPEED);

    load_setting<bool>(VAR_NAME(MAIN_MMU), (*settings.json)[VAR_NAME(MAIN_MMU)], Config::MAIN_MMU);

    load_setting<bool>(VAR_NAME(MAIN_FASTMEM), (*settings.json)[VAR_NAME(MAIN_FASTMEM)],
                       Config::MAIN_FASTMEM);




    load_setting<bool>(VAR_NAME(SYSCONF_PROGRESSIVE_SCAN),
                       (*settings.json)[VAR_NAME(SYSCONF_PROGRESSIVE_SCAN)],
                       Config::SYSCONF_PROGRESSIVE_SCAN);

    load_setting<bool>(VAR_NAME(SYSCONF_PAL60), (*settings.json)[VAR_NAME(SYSCONF_PAL60)],
                       Config::SYSCONF_PAL60);




    load_setting<bool>(VAR_NAME(GFX_HACK_EFB_ACCESS_ENABLE),
                       (*settings.json)[VAR_NAME(GFX_HACK_EFB_ACCESS_ENABLE)],
                       Config::GFX_HACK_EFB_ACCESS_ENABLE);

    load_setting<bool>(VAR_NAME(GFX_HACK_BBOX_ENABLE),
                       (*settings.json)[VAR_NAME(GFX_HACK_BBOX_ENABLE)],
                       Config::GFX_HACK_BBOX_ENABLE);

    load_setting<bool>(VAR_NAME(GFX_HACK_FORCE_PROGRESSIVE),
                       (*settings.json)[VAR_NAME(GFX_HACK_FORCE_PROGRESSIVE)],
                       Config::GFX_HACK_FORCE_PROGRESSIVE);

    load_setting<bool>(VAR_NAME(GFX_HACK_SKIP_EFB_COPY_TO_RAM),
                       (*settings.json)[VAR_NAME(GFX_HACK_SKIP_EFB_COPY_TO_RAM)],
                       Config::GFX_HACK_SKIP_EFB_COPY_TO_RAM);

    load_setting<bool>(VAR_NAME(GFX_HACK_SKIP_XFB_COPY_TO_RAM),
                       (*settings.json)[VAR_NAME(GFX_HACK_SKIP_XFB_COPY_TO_RAM)],
                       Config::GFX_HACK_SKIP_XFB_COPY_TO_RAM);

    load_setting<bool>(VAR_NAME(GFX_HACK_DISABLE_COPY_TO_VRAM),
                       (*settings.json)[VAR_NAME(GFX_HACK_DISABLE_COPY_TO_VRAM)],
                       Config::GFX_HACK_DISABLE_COPY_TO_VRAM);

    load_setting<bool>(VAR_NAME(GFX_HACK_IMMEDIATE_XFB),
                       (*settings.json)[VAR_NAME(GFX_HACK_IMMEDIATE_XFB)],
                       Config::GFX_HACK_IMMEDIATE_XFB);

    load_setting<bool>(VAR_NAME(GFX_HACK_EFB_EMULATE_FORMAT_CHANGES),
                       (*settings.json)[VAR_NAME(GFX_HACK_EFB_EMULATE_FORMAT_CHANGES)],
                       Config::GFX_HACK_EFB_EMULATE_FORMAT_CHANGES);

    load_setting<int>(VAR_NAME(GFX_SAFE_TEXTURE_CACHE_COLOR_SAMPLES),
                       (*settings.json)[VAR_NAME(GFX_SAFE_TEXTURE_CACHE_COLOR_SAMPLES)],
                       Config::GFX_SAFE_TEXTURE_CACHE_COLOR_SAMPLES);

    load_setting<bool>(VAR_NAME(GFX_PERF_QUERIES_ENABLE),
                       (*settings.json)[VAR_NAME(GFX_PERF_QUERIES_ENABLE)],
                       Config::GFX_PERF_QUERIES_ENABLE);

    load_setting<bool>(VAR_NAME(GFX_HACK_DEFER_EFB_COPIES),
                       (*settings.json)[VAR_NAME(GFX_HACK_DEFER_EFB_COPIES)],
                       Config::GFX_HACK_DEFER_EFB_COPIES);

    load_setting<int>(VAR_NAME(GFX_HACK_EFB_ACCESS_TILE_SIZE),
                       (*settings.json)[VAR_NAME(GFX_HACK_EFB_ACCESS_TILE_SIZE)],
                       Config::GFX_HACK_EFB_ACCESS_TILE_SIZE);

    load_setting<bool>(VAR_NAME(GFX_HACK_EFB_DEFER_INVALIDATION),
                       (*settings.json)[VAR_NAME(GFX_HACK_EFB_DEFER_INVALIDATION)],
                       Config::GFX_HACK_EFB_DEFER_INVALIDATION);

    load_setting<int>(VAR_NAME(GFX_ASPECT_RATIO), (*settings.json)[VAR_NAME(GFX_ASPECT_RATIO)],
                       Config::GFX_ASPECT_RATIO);

    load_setting<bool>(VAR_NAME(GFX_HACK_VERTEX_ROUNDING),
                      (*settings.json)[VAR_NAME(GFX_HACK_VERTEX_ROUNDING)],
                      Config::GFX_HACK_VERTEX_ROUNDING);

    load_setting<bool>(VAR_NAME(GFX_HACK_COPY_EFB_SCALED),
                       (*settings.json)[VAR_NAME(GFX_HACK_COPY_EFB_SCALED)],
                       Config::GFX_HACK_COPY_EFB_SCALED);

    load_setting<bool>(VAR_NAME(GFX_FAST_DEPTH_CALC),
                       (*settings.json)[VAR_NAME(GFX_FAST_DEPTH_CALC)],
                       Config::GFX_FAST_DEPTH_CALC);

    load_setting<bool>(VAR_NAME(GFX_ENABLE_PIXEL_LIGHTING),
                       (*settings.json)[VAR_NAME(GFX_ENABLE_PIXEL_LIGHTING)],
                       Config::GFX_ENABLE_PIXEL_LIGHTING);

    load_setting<bool>(VAR_NAME(GFX_WIDESCREEN_HACK),
                       (*settings.json)[VAR_NAME(GFX_WIDESCREEN_HACK)],
                       Config::GFX_WIDESCREEN_HACK);

    load_setting<int>(VAR_NAME(GFX_ENHANCE_FORCE_TEXTURE_FILTERING),
                       (*settings.json)[VAR_NAME(GFX_ENHANCE_FORCE_TEXTURE_FILTERING)],
                       Config::GFX_ENHANCE_FORCE_TEXTURE_FILTERING);

    load_setting<bool>(VAR_NAME(GFX_ENHANCE_FORCE_TRUE_COLOR),
                      (*settings.json)[VAR_NAME(GFX_ENHANCE_FORCE_TRUE_COLOR)],
                      Config::GFX_ENHANCE_FORCE_TRUE_COLOR);

    load_setting<bool>(VAR_NAME(GFX_ENHANCE_DISABLE_COPY_FILTER),
                       (*settings.json)[VAR_NAME(GFX_ENHANCE_DISABLE_COPY_FILTER)],
                       Config::GFX_ENHANCE_DISABLE_COPY_FILTER);

    load_setting<bool>(VAR_NAME(GFX_DISABLE_FOG), (*settings.json)[VAR_NAME(GFX_DISABLE_FOG)],
                       Config::GFX_DISABLE_FOG);

    load_setting<bool>(VAR_NAME(GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION),
                       (*settings.json)[VAR_NAME(GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION)],
                       Config::GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION);

    load_setting<float>(VAR_NAME(GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION_THRESHOLD),
                       (*settings.json)[VAR_NAME(GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION_THRESHOLD)],
                       Config::GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION_THRESHOLD);

    load_setting<bool>(VAR_NAME(GFX_ENABLE_GPU_TEXTURE_DECODING),
                        (*settings.json)[VAR_NAME(GFX_ENABLE_GPU_TEXTURE_DECODING)],
                        Config::GFX_ENABLE_GPU_TEXTURE_DECODING);
  }

  // Visits the variant value in a pair, determines the correct data type and returns it as a string
  std::string to_string(SettingsTypes var)
  {
    return std::visit([](auto arg) { return std::format("{}", arg); }, var);
  }

private:
  // saves the name and value of the setting to a pair, then push it onto the array
  template<typename T>
  void save_setting(std::string name, std::pair<std::string, SettingsTypes> variable, Config::Info<T> setting)
  {
    variable.first = name;
    variable.second = Get(setting);
    array.push_back(variable);
  }

  // loads the value of the parsed setting based on the requested data type
  template<typename T>
  void load_setting(std::string name, JsonParser::JsonValue value, Config::Info<T> setting)
  {
    Config::LayerType layer = Config::GetActiveLayerForConfig(setting);

    if (typeid(T) == typeid(bool))
      Set<T>(layer, setting, value.b);

    else if (typeid(T) == typeid(int))
      Set<T>(layer, setting, value.i);

    else if (typeid(T) == typeid(float))
      Set<T>(layer, setting, value.d);
  }
};
