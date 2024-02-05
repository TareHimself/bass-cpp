#include <bass/Plugin.hpp>

#include "bass/utils.hpp"

namespace bass
{
    Plugin::Plugin(const std::filesystem::path& file, const HPLUGIN handle)
    {
        _file = file;
        _handle = handle;
    }

    Plugin::~Plugin()
    {
        BASS_PluginFree(_handle);
    }

    void Plugin::SetEnabled(const bool bIsEnabled) const
    {
        if(BASS_PluginEnable(_handle,bIsEnabled) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    Plugin* loadPlugin(const std::filesystem::path& file)
    {
        if(const auto plugin = BASS_PluginLoad(file.c_str(),BASS_UNICODE))
        {
            return new Plugin(file,plugin);
        }

        return throwOrReturn(nullptr);
    }
}
