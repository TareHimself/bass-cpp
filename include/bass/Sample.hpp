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
        Sample(DWORD handle);

        Channel* GetChannel(const bool bCreateNew) const;
    };

    Sample* createSample(const void* data, const QWORD offset, const DWORD length, const DWORD max, const DWORD flags);
    
    class FileSample : public Sample
    {
        std::filesystem::path _file;
    public:
        FileSample(const std::filesystem::path& file, DWORD handle);
    };

    FileSample* createFileSample(const std::filesystem::path& file, const DWORD offset, const DWORD length, const DWORD max, const DWORD flags);
}
