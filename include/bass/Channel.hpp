#pragma once
#include <bass.h>
#include <functional>
#include <optional>

#include "types.hpp"

namespace bass
{
    class Channel
    {
        HCHANNEL _handle;
    public:
        Channel(HCHANNEL handle);
        ~Channel();
        double BytesToSeconds(std::size_t pos) const;
        std::size_t SecondsToBytes(double pos) const;
        bool Play(bool bRestart = true) const;
        bool Pause() const;
        bool Stop() const;
        bool Update(unsigned length) const;
        EBassState GetState() const;
        std::size_t GetPosition(EBassPos mode = PosByte) const;
        void SetPosition(QWORD pos,EBassPos mode = PosByte) const;
        std::size_t GetLength(EBassPos mode = PosByte) const;
        void SetAttribute(DWORD attribute,float val) const;

        float GetAttribute(DWORD attribute) const;

        void SetAttribute(EBassAttribute attribute,float val) const;

        float GetAttribute(EBassAttribute attribute) const;

        void SlideAttribute(const DWORD attribute, const float val, const DWORD time) const;
        void SlideAttribute(const EBassAttribute attribute, const float val, const DWORD time) const;

        bool IsSlidingAttribute(const DWORD attribute) const;
        bool IsSlidingAttribute(const EBassAttribute attribute) const;

        void Get3DPosition(Vector * position,Vector * orientation,Vector * velocity) const;
        void Set3DPosition(const std::optional<Vector> &position,const std::optional<Vector> &orientation,const std::optional<Vector> &velocity) const;
        void Set3DAttributes(EBass3DMode mode,float min,float max,int iAngle,int oAngle,float oVolume) const;

        void Link(const Channel * other) const;
        void UnLink(const Channel * other) const;
    };
}
