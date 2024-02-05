#pragma once
#include <bass.h>
#include <filesystem>

namespace bass
{
    class Plugin
    {
        HPLUGIN _handle;
        std::filesystem::path _file;
    public:
        Plugin(const std::filesystem::path &file,HPLUGIN handle);
        ~Plugin();
        void SetEnabled(bool bIsEnabled) const;
        
    };

    Plugin * loadPlugin(const std::filesystem::path &file);
}
