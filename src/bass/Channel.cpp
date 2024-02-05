#include <bass/Channel.hpp>

#include "bass/utils.hpp"

namespace bass
{
    Channel::Channel(const HCHANNEL handle)
    {
        _handle = handle;
    }
    
    Channel::~Channel()
    {
        BASS_ChannelFree(_handle);
    }
    
    double Channel::BytesToSeconds(const unsigned long long pos) const
    {
        if (const auto size = BASS_ChannelBytes2Seconds(_handle, pos); size != -1)
        {
            return size;
        }
    
        return throwOrReturn(0);
    }
    
    size_t Channel::SecondsToBytes(const double pos) const
    {
        if (const auto size = BASS_ChannelSeconds2Bytes(_handle, pos); size != -1)
        {
            return size;
        }
    
        return throwOrReturn(0);
    }
    
    bool Channel::Play(bool bRestart) const
    {
        return throwOrReturn(BASS_ChannelPlay(_handle, bRestart));
    }
    
    bool Channel::Pause() const
    {
        return throwOrReturn(BASS_ChannelPause(_handle));
    }
    
    bool Channel::Stop() const
    {
        return throwOrReturn(BASS_ChannelStop(_handle));
    }
    
    bool Channel::Update(const unsigned length) const
    {
        return throwOrReturn(BASS_ChannelUpdate(_handle,length));
    }
    
    EBassState Channel::GetState() const
    {
        return static_cast<EBassState>(BASS_ChannelIsActive(_handle));
    }
    
    std::size_t Channel::GetPosition(const EBassPos mode) const
    {
        if (const auto size = BASS_ChannelGetPosition(_handle, static_cast<uint32_t>(mode)); size != -1)
        {
            return size;
        }
    
        return throwOrReturn(0);
    }
    
    void Channel::SetPosition(const QWORD pos, const EBassPos mode) const
    {
        if (BASS_ChannelSetPosition(_handle, pos, mode) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }
    
    std::size_t Channel::GetLength(const EBassPos mode) const
    {
        if (const auto size = BASS_ChannelGetLength(_handle, static_cast<uint32_t>(mode)); size != -1)
        {
            return size;
        }
    
        return throwOrReturn(0);
    }
    
    void Channel::SetAttribute(const DWORD attribute, const float val) const
    {
        if (BASS_ChannelSetAttribute(_handle, attribute, val) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }
    
    float Channel::GetAttribute(const DWORD attribute) const
    {
        float result = 0;
    
        if (BASS_ChannelGetAttribute(_handle, attribute, &result) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    
        return result;
    }
    
    void Channel::SetAttribute(const EBassAttribute attribute, const float val) const
    {
        return SetAttribute(static_cast<uint32_t>(attribute), val);
    }
    
    float Channel::GetAttribute(const EBassAttribute attribute) const
    {
        return GetAttribute(static_cast<uint32_t>(attribute));
    }
    
    void Channel::SlideAttribute(const DWORD attribute, const float val, const DWORD time) const
    {
        if (BASS_ChannelSlideAttribute(_handle, attribute, val, time) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }
    
    void Channel::SlideAttribute(const EBassAttribute attribute, const float val, const DWORD time) const
    {
        SlideAttribute(static_cast<DWORD>(attribute), val, time);
    }
    
    bool Channel::IsSlidingAttribute(const DWORD attribute) const
    {
        return BASS_ChannelIsSliding(_handle, attribute) == TRUE;
    }
    
    bool Channel::IsSlidingAttribute(const EBassAttribute attribute) const
    {
        return IsSlidingAttribute(static_cast<DWORD>(attribute));
    }
    
    void Channel::Get3DPosition(Vector* position, Vector* orientation, Vector* velocity) const
    {
        if (BASS_ChannelGet3DPosition(_handle,position,orientation,velocity) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }
    
    void Channel::Set3DPosition(const std::optional<Vector>& position,
                                const std::optional<Vector>& orientation, const std::optional<Vector>& velocity) const
    {
        if (BASS_ChannelSet3DPosition(_handle, position.has_value() ? &position.value() : nullptr,
                                      orientation.has_value() ? &orientation.value() : nullptr,
                                      velocity.has_value() ? &velocity.value() : nullptr) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }
    
    auto Channel::Set3DAttributes(const EBass3DMode mode, const float min, const float max, const int iAngle,
                                  const int oAngle,
                                  const float oVolume) const -> void
    {
        if (BASS_ChannelSet3DAttributes(_handle, mode, min, max, iAngle, oAngle, oVolume) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }
    
    void Channel::Link(const Channel* other) const
    {
        if (BASS_ChannelSetLink(_handle, other->_handle) == FALSE)
        {
            throwOrReturn(nullptr);
        }
    }
    
    void Channel::UnLink(const Channel* other) const
    {
        if (BASS_ChannelRemoveLink(_handle, other->_handle) == FALSE)
        {
            throwOrReturn(nullptr);
        }
        
    }
}
