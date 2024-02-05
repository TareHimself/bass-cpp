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
        Plugin(const std::filesystem::path& file, const HPLUGIN handle);

        ~Plugin();

        void SetEnabled(const bool bIsEnabled) const;
    };

    Plugin* loadPlugin(const std::filesystem::path& file);
}
