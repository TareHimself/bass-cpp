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
         Channel(const HCHANNEL handle)
    {
        _handle = handle;
    }

    ~Channel()
    {
        BASS_ChannelFree(_handle);
    }

    double BytesToSeconds(const unsigned long long pos) const
    {
        if (const auto size = BASS_ChannelBytes2Seconds(_handle, pos); size != -1)
        {
            return size;
        }

        return throwOrReturn(0);
    }

    size_t SecondsToBytes(const double pos) const
    {
        if (const auto size = BASS_ChannelSeconds2Bytes(_handle, pos); size != -1)
        {
            return size;
        }

        return throwOrReturn(0);
    }

    bool Play(bool bRestart = true) const
    {
        return throwOrReturn(BASS_ChannelPlay(_handle, bRestart));
    }

    bool Pause() const
    {
        return throwOrReturn(BASS_ChannelPause(_handle));
    }

    bool Stop() const
    {
        return throwOrReturn(BASS_ChannelStop(_handle));
    }

    bool Update(const unsigned length) const
    {
        return throwOrReturn(BASS_ChannelUpdate(_handle,length));
    }

    EBassState GetState() const
    {
        return static_cast<EBassState>(BASS_ChannelIsActive(_handle));
    }

    std::size_t GetPosition(const EBassPos mode) const
    {
        if (const auto size = BASS_ChannelGetPosition(_handle, static_cast<uint32_t>(mode)); size != -1)
        {
            return size;
        }

        return throwOrReturn(0);
    }

    void SetPosition(const QWORD pos, const EBassPos mode) const
    {
        if (BASS_ChannelSetPosition(_handle, pos, mode) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    std::size_t GetLength(const EBassPos mode) const
    {
        if (const auto size = BASS_ChannelGetLength(_handle, static_cast<uint32_t>(mode)); size != -1)
        {
            return size;
        }

        return throwOrReturn(0);
    }

    void SetAttribute(const DWORD attribute, const float val) const
    {
        if (BASS_ChannelSetAttribute(_handle, attribute, val) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    float GetAttribute(const DWORD attribute) const
    {
        float result = 0;

        if (BASS_ChannelGetAttribute(_handle, attribute, &result) == FALSE)
        {
            throwOrReturn(nullptr);
        }

        return result;
    }

    void SetAttribute(const EBassAttribute attribute, const float val) const
    {
        return SetAttribute(static_cast<uint32_t>(attribute), val);
    }

    float GetAttribute(const EBassAttribute attribute) const
    {
        return GetAttribute(static_cast<uint32_t>(attribute));
    }

    void SlideAttribute(const DWORD attribute, const float val, const DWORD time) const
    {
        if (BASS_ChannelSlideAttribute(_handle, attribute, val, time) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    void SlideAttribute(const EBassAttribute attribute, const float val, const DWORD time) const
    {
        SlideAttribute(static_cast<DWORD>(attribute), val, time);
    }

    bool IsSlidingAttribute(const DWORD attribute) const
    {
        return BASS_ChannelIsSliding(_handle, attribute) == TRUE;
    }

    bool IsSlidingAttribute(const EBassAttribute attribute) const
    {
        return IsSlidingAttribute(static_cast<DWORD>(attribute));
    }

    void Get3DPosition(Vector* position, Vector* orientation, Vector* velocity) const
    {
        if (BASS_ChannelGet3DPosition(_handle,position,orientation,velocity) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    void Set3DPosition(const std::optional<Vector>& position,
                                const std::optional<Vector>& orientation, const std::optional<Vector>& velocity) const
    {
        if (BASS_ChannelSet3DPosition(_handle, position.has_value() ? &position.value() : nullptr,
                                      orientation.has_value() ? &orientation.value() : nullptr,
                                      velocity.has_value() ? &velocity.value() : nullptr) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    auto Set3DAttributes(const EBass3DMode mode, const float min, const float max, const int iAngle,
                                  const int oAngle,
                                  const float oVolume) const -> void
    {
        if (BASS_ChannelSet3DAttributes(_handle, mode, min, max, iAngle, oAngle, oVolume) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    void Link(const Channel* other) const
    {
        if (BASS_ChannelSetLink(_handle, other->_handle) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }

    void UnLink(const Channel* other) const
    {
        if (BASS_ChannelRemoveLink(_handle, other->_handle) == FALSE)
        {
            throwOrReturn(nullptr);
        }
        
    }
        // Channel(HCHANNEL handle);
        // ~Channel();
        // double BytesToSeconds(std::size_t pos) const;
        // std::size_t SecondsToBytes(double pos) const;
        // bool Play(bool bRestart = true) const;
        // bool Pause() const;
        // bool Stop() const;
        // bool Update(unsigned length) const;
        // EBassState GetState() const;
        // std::size_t GetPosition(EBassPos mode = PosByte) const;
        // void SetPosition(QWORD pos,EBassPos mode = PosByte) const;
        // std::size_t GetLength(EBassPos mode = PosByte) const;
        // void SetAttribute(DWORD attribute,float val) const;
        //
        // float GetAttribute(DWORD attribute) const;
        //
        // void SetAttribute(EBassAttribute attribute,float val) const;
        //
        // float GetAttribute(EBassAttribute attribute) const;
        //
        // void SlideAttribute(const DWORD attribute, const float val, const DWORD time) const;
        // void SlideAttribute(const EBassAttribute attribute, const float val, const DWORD time) const;
        //
        // bool IsSlidingAttribute(const DWORD attribute) const;
        // bool IsSlidingAttribute(const EBassAttribute attribute) const;
        //
        // void Get3DPosition(Vector * position,Vector * orientation,Vector * velocity) const;
        // void Set3DPosition(const std::optional<Vector> &position,const std::optional<Vector> &orientation,const std::optional<Vector> &velocity) const;
        // void Set3DAttributes(EBass3DMode mode,float min,float max,int iAngle,int oAngle,float oVolume) const;
        //
        // void Link(const Channel * other) const;
        // void UnLink(const Channel * other) const;
    };
}
