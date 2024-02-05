#pragma once
#include <bass.h>
#include <filesystem>

#include "utils.hpp"

namespace bass
{
    class Plugin
    {
        HPLUGIN _handle;
        std::filesystem::path _file;
    public:
        // Plugin(const std::filesystem::path &file,HPLUGIN handle);
        // ~Plugin();
        // void SetEnabled(bool bIsEnabled) const;

        Plugin(const std::filesystem::path& file, const HPLUGIN handle)
        {
            _file = file;
            _handle = handle;
        }

        ~Plugin()
        {
            BASS_PluginFree(_handle);
        }

        void SetEnabled(const bool bIsEnabled) const
        {
            if(BASS_PluginEnable(_handle,bIsEnabled) == FALSE)
            {
                throwOrReturn(nullptr);
            }
        }

        
        
    };

    inline Plugin* loadPlugin(const std::filesystem::path& file)
    {
        if(const auto plugin = BASS_PluginLoad(file.c_str(),BASS_UNICODE))
        {
            return new Plugin(file,plugin);
        }

        return throwOrReturn(nullptr);
    }
}
