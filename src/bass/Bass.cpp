#include <bass/Bass.hpp>

#include "bass/utils.hpp"

namespace bass
{
    /*bool init(const int device, const DWORD sampleRate, const DWORD flags, const WindowHandle window)
    {
        return  BASS_Init(device,sampleRate,flags,window,nullptr) == TRUE;
    }

    bool free()
    {
        return BASS_Free() == TRUE;
    }

    void setConfig(const DWORD option, const DWORD val)
    {
        if(BASS_SetConfig(option,val) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    DWORD getConfig(const DWORD option)
    {
        if(const auto val = BASS_GetConfig(option); val != -1)
        {
            return val;
        }
        return throwOrReturn(-1);
    }

    void setConfig(const EBassConfig option, const DWORD val)
    {
        setConfig(static_cast<DWORD>(option),val);
    }

    DWORD getConfig(const EBassConfig option)
    {
        return getConfig(static_cast<DWORD>(option));
    }

    bool start()
    {
        return throwOrReturn(BASS_Start());
    }

    bool stop()
    {
        return throwOrReturn(BASS_Stop());
    }

    void apply3D()
    {
        BASS_Apply3D();
    }

    void set3DPosition(const std::optional<Vector>& position, const std::optional<Vector>& velocity,
        const std::optional<Vector>& front, const std::optional<Vector>& top)
    {
        if (BASS_Set3DPosition(position.has_value() ? &position.value() : nullptr,
                                      velocity.has_value() ? &velocity.value() : nullptr,
                                      front.has_value() ? &front.value() : nullptr,
                                      top.has_value() ? &top.value() : nullptr) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    void set3DFactors(const float distanceFactor, const float rolloffFactor, const float dopplerFactor)
    {
        if (BASS_Set3DFactors(distanceFactor,rolloffFactor,dopplerFactor) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    void get3DPosition(Vector* position, Vector* velocity, Vector* front, Vector* top)
    {
        if (BASS_Get3DPosition(position,velocity,front,top) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    void get3DFactors(float* distanceFactor, float* rolloffFactor, float* dopplerFactor)
    {
        if (BASS_Get3DFactors(distanceFactor,rolloffFactor,dopplerFactor) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    std::vector<BassDevice> getDevices()
    {
        std::vector<BassDevice> devices;
        BASS_DEVICEINFO currentInfo{};
        for(auto i = 1; BASS_GetDeviceInfo(i,&currentInfo); i++)
        {
            BassDevice device{};
            device.id = i;
            device = currentInfo;
            devices.push_back(device);
        }

        return devices;
    }*/
}
