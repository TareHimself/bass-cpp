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
        Stream(const DWORD& handle);

        ~Stream();
    };

    class FileStream : public Stream
    {
        std::filesystem::path _file;
    public:
        
        FileStream(const std::filesystem::path& file, const DWORD& handle);
    };

    FileStream* createFileStream(const std::filesystem::path& file,DWORD offset,DWORD flags);

    class UrlStream : public  Stream
    {
        std::string _url;
    public:
        
        UrlStream(const std::string& url, const DWORD& handle);
    };
    
    UrlStream* createUrlStream(const std::string& url,DWORD offset,DWORD flags);
    
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
