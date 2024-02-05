#pragma once
#include <filesystem>
#include "Channel.hpp"
#include "utils.hpp"

namespace bass
{
    class Sample
    {
        
        DWORD _handle{0};
    public:
        

        // Sample(DWORD handle);
        // Channel* GetChannel(bool bCreateNew = true) const;
        Sample(DWORD handle)
        {
            _handle = handle;
        }

        Channel* GetChannel(const bool bCreateNew) const
        {
            if(const auto handle  = BASS_SampleGetChannel(_handle,bCreateNew ? BASS_SAMCHAN_NEW : 0))
            {
                return new Channel(handle);
            }
        
            return throwOrReturn(nullptr);
        }
    };

    
    inline Sample* createSample(const void* data, const QWORD offset, const DWORD length, const DWORD max, const DWORD flags)
    {
        if(const auto sample = BASS_SampleLoad(true,data,offset,length,max,flags))
        {
            return new Sample(sample);
        }

        return throwOrReturn(nullptr);
    }
    
    class FileSample : public Sample
    {
        std::filesystem::path _file;
    public:
        FileSample(const std::filesystem::path& file, DWORD handle) : Sample(handle)
        {
            _file = file;
        }
    };

    
    
    inline FileSample* createFileSample(const std::filesystem::path& file, const DWORD offset, const DWORD length, const DWORD max, const DWORD flags)
    {
        if(const auto sample = BASS_SampleLoad(false,file.c_str(),offset,length,max,flags))
        {
            return new FileSample(file,sample);
        }

        return throwOrReturn(nullptr);
    }
}
