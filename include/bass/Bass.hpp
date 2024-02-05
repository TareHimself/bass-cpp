#include <optional>
#include <vector>

#include "types.hpp"

namespace bass
{
    bool init(int device,DWORD sampleRate,DWORD flags,WindowHandle window);

    bool free();
    void setConfig(DWORD option,DWORD val);
    DWORD getConfig(DWORD option);

    void setConfig(EBassConfig option,DWORD val);
    DWORD getConfig(EBassConfig option);

    bool start();
    bool stop();
    void apply3D();

    void set3DPosition(const std::optional<Vector> &position,const std::optional<Vector> &velocity,const std::optional<Vector> &front,const std::optional<Vector> &top);

    void set3DFactors(float distanceFactor,float rolloffFactor,float dopplerFactor);

    void get3DPosition(Vector * position,Vector * velocity,Vector * front,Vector * top);

    void get3DFactors(float * distanceFactor,float * rolloffFactor,float * dopplerFactor);
    
    std::vector<BassDevice> getDevices();
}
