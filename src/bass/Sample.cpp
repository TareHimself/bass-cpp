#include <bass.h>
#include <bass/Sample.hpp>
#include "bass/Channel.hpp"
#include "bass/utils.hpp"

namespace bass
{
    Sample::Sample(DWORD handle)
    {
        _handle = handle;
    }
    
    Channel* Sample::GetChannel(const bool bCreateNew) const
    {
        if(const auto handle  = BASS_SampleGetChannel(_handle,bCreateNew ? BASS_SAMCHAN_NEW : 0))
        {
            return new Channel(handle);
        }
        
        return throwOrReturn(nullptr);
    }
    
    Sample* createSample(const void* data, const QWORD offset, const DWORD length, const DWORD max, const DWORD flags)
    {
        if(const auto sample = BASS_SampleLoad(true,data,offset,length,max,flags))
        {
            return new Sample(sample);
        }
    
        return throwOrReturn(nullptr);
    }
    
    FileSample::FileSample(const std::filesystem::path& file, DWORD handle) : Sample(handle)
    {
        _file = file;
    }
    
    FileSample* createFileSample(const std::filesystem::path& file, const DWORD offset, const DWORD length, const DWORD max, const DWORD flags)
    {
        if(const auto sample = BASS_SampleLoad(false,file.c_str(),offset,length,max,flags))
        {
            return new FileSample(file,sample);
        }
    
        return throwOrReturn(nullptr);
    }
}
