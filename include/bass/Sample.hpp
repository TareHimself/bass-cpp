#pragma once
#include <filesystem>

#include "types.hpp"

namespace bass
{
    class Channel;

    class Sample
    {
        
        DWORD _handle{0};
    public:
        

        Sample(DWORD handle);
        Channel* GetChannel(bool bCreateNew = true) const;
    };

    Sample * createSample(const void * data,QWORD offset = 0,DWORD length = 0,DWORD max = 0,DWORD flags = 0);

    class FileSample : public Sample
    {
        std::filesystem::path _file;
    public:
        FileSample(const std::filesystem::path& file,DWORD handle);
    };

    
    
    FileSample * createFileSample(const std::filesystem::path& file,DWORD offset = 0,DWORD length = 0,DWORD max = 0,DWORD flags = 0);
}
