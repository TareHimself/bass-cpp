#pragma once
#include <bass.h>
#include <functional>
#include <optional>

#include "types.hpp"
#include "utils.hpp"

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
        State GetState() const;
        std::size_t GetPosition(Position mode = Position::Byte) const;
        void SetPosition(QWORD pos,Position mode = Position::Byte) const;
        std::size_t GetLength(Position mode = Position::Byte) const;
        void SetAttribute(DWORD attribute,float val) const;
        
        float GetAttribute(DWORD attribute) const;
        
        void SetAttribute(Attribute attribute,float val) const;
        
        float GetAttribute(Attribute attribute) const;
        
        void SlideAttribute(const DWORD attribute, const float val, const DWORD time) const;
        void SlideAttribute(const Attribute attribute, const float val, const DWORD time) const;
        
        bool IsSlidingAttribute(const DWORD attribute) const;
        bool IsSlidingAttribute(const Attribute attribute) const;
        
        void Get3DPosition(Vector * position,Vector * orientation,Vector * velocity) const;
        void Set3DPosition(const std::optional<Vector> &position,const std::optional<Vector> &orientation,const std::optional<Vector> &velocity) const;
        void Set3DAttributes(SpatialMode mode,float min,float max,int iAngle,int oAngle,float oVolume) const;
        
        void Link(const Channel * other) const;
        void UnLink(const Channel * other) const;
    };
}
