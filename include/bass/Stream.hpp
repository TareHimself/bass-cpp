#pragma once
#include <filesystem>
#include <functional>
#include "Channel.hpp"
#include "types.hpp"
#include "utils.hpp"

namespace bass
{
    class Stream : public Channel
    {
        DWORD _handle;
        
    public:
        Stream(const DWORD& handle) : Channel(handle)
        {
            _handle = handle;
        }

        ~Stream()
        {
            BASS_StreamFree(_handle);
        }
    };

    class FileStream : public Stream
    {
        std::filesystem::path _file;
    public:
        
        FileStream(const std::filesystem::path& file, const DWORD& handle) : Stream(handle)
        {
            _file = file;
        }
    };

    inline FileStream* createFileStream(const std::filesystem::path& file, const DWORD offset, const DWORD flags)
    {
        if(const auto stream = BASS_StreamCreateFile(false,file.c_str(),offset,0,flags))
        {
            return new FileStream(file,stream);
        }

        return throwOrReturn(nullptr);
    }

    class UrlStream : public  Stream
    {
        std::string _url;
    public:
        
        UrlStream(const std::string& url, const DWORD& handle)  : Stream(handle)
        {
            _url = url;
        }
    };
    
    inline UrlStream* createUrlStream(const std::string& url, const DWORD offset, const DWORD flags)
    {
        if(const auto stream = BASS_StreamCreateURL(url.c_str(),offset,flags,nullptr,nullptr))
        {
            return new UrlStream(url,stream);
        }

        return throwOrReturn(nullptr);
    }
    
    template<typename T>
    UrlStream* createUrlStream(const std::string& url, DWORD offset,
                               DWORD flags, const std::function<void(const void*, DWORD, T*)>& callback,
                               T* callbackData)
    {
        if(const auto stream = BASS_StreamCreateURL(url.c_str(),offset,flags,callback,callbackData))
        {
            return new UrlStream(url,stream);
        }

        return throwOrReturn(nullptr);
    }

    
}
