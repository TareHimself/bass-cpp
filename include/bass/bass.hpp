#pragma once
#include <optional>
#include <vector>
#include "types.hpp"


namespace bass
{
    bool init(const int device, const DWORD sampleRate, const DWORD flags, const WindowHandle window);

    bool free();

    void setConfig(const DWORD option, const DWORD val);

    DWORD getConfig(const DWORD option);

    void setConfig(const Config option, const DWORD val);

    DWORD getConfig(const Config option);

    bool start();

    bool stop();

    void apply3D();

    void set3DPosition(const std::optional<Vector>& position, const std::optional<Vector>& velocity,
        const std::optional<Vector>& front, const std::optional<Vector>& top);

    void set3DFactors(const float distanceFactor, const float rolloffFactor, const float dopplerFactor);

    void get3DPosition(Vector* position, Vector* velocity, Vector* front, Vector* top);

    void get3DFactors(float* distanceFactor, float* rolloffFactor, float* dopplerFactor);

    std::vector<Device> getDevices();
}
