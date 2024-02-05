#include <bass.h>
#include <bass/Stream.hpp>
#include "bass/utils.hpp"

namespace bass
{
    Stream::Stream(const DWORD& handle) : Channel(handle)
    {
        _handle = handle;
    }

    Stream::~Stream()
    {
        BASS_StreamFree(_handle);
    }

    FileStream::FileStream(const std::filesystem::path& file, const DWORD& handle) : Stream(handle)
    {
        _file = file;
    }

    FileStream* createFileStream(const std::filesystem::path& file, const DWORD offset, const DWORD flags)
    {
        if(const auto stream = BASS_StreamCreateFile(false,file.c_str(),offset,0,flags))
        {
            return new FileStream(file,stream);
        }

        return throwOrReturn(nullptr);
    }

    UrlStream::UrlStream(const std::string& url, const DWORD& handle)  : Stream(handle)
    {
        _url = url;
    }

    UrlStream* createUrlStream(const std::string& url, const DWORD offset, const DWORD flags)
    {
        if(const auto stream = BASS_StreamCreateURL(url.c_str(),offset,flags,nullptr,nullptr))
        {
            return new UrlStream(url,stream);
        }

        return throwOrReturn(nullptr);
    }
}
