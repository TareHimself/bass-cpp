#include <bass.h>

#include <bass/utils.hpp>
#include <bass/types.hpp>

namespace bass
{
    std::string bassErrorToString(Error error)
    {
            switch (error)
            {
            case Error::OK:
                return "All is OK, yet you saw this ?";
            case Error::Memory:
                return "Memory error";
            case Error::FileOpen:
                return "Can't open the file";
            case Error::Driver:
                return "Can't find a free/valid driver";
            case Error::BufferLost:
                return "The sample buffer was lost";
            case Error::Handle:
                return "Invalid handle";
            case Error::Format:
                return "Unsupported sample format";
            case Error::Position:
                return "Invalid position";
            case Error::Init:
                return "BASS_Init has not been successfully called";
            case Error::Start:
                return "BASS_Start has not been successfully called";
            case Error::SSL:
                return "SSL/HTTPS support isn't available";
            case Error::Reinit:
                return "Device needs to be reinitialized";
            case Error::Already:
                return "Already initialized/paused/whatever";
            case Error::NotAudio:
                return "File does not contain audio";
            case Error::NoChannel:
                return "Can't get a free channel";
            case Error::IllegalType:
                return "An illegal type was specified";
            case Error::IllegalParam:
                return "An illegal parameter was specified";
            case Error::No3D:
                return "No 3D support";
            case Error::NoEAX:
                return "No EAX support";
            case Error::Device:
                return "Illegal device number";
            case Error::NoPlay:
                return "Not playing";
            case Error::Frequency:
                return "Illegal sample rate";
            case Error::NotFile:
                return "The stream is not a file stream";
            case Error::NoHardware:
                return "No hardware voices available";
            case Error::Empty:
                return "The file has no sample data";
            case Error::NoInternet:
                return "No internet connection could be opened";
            case Error::Create:
                return "Couldn't create the file";
            case Error::NoFX:
                return "Effects are not available";
            case Error::NotAvailable:
                return "Requested data/action is not available";
            case Error::Decode:
                return "The channel is/isn't a 'decoding channel'";
            case Error::DX:
                return "A sufficient DirectX version is not installed";
            case Error::Timeout:
                return "Connection timed out";
            case Error::FileFormat:
                return "Unsupported file format";
            case Error::Speaker:
                return "Unavailable speaker";
            case Error::Version:
                return "Invalid BASS version (used by add-ons)";
            case Error::Codec:
                return "Codec is not available/supported";
            case Error::Ended:
                return "The channel/file has ended";
            case Error::Busy:
                return "The device is busy";
            case Error::Unstreamable:
                return "Unstreamable file";
            case Error::Protocol:
                return "Unsupported protocol";
            case Error::Denied:
                return "Access denied";
            case Error::Unknown:
                return "Some other mystery problem";
            }
    
            return "Invalid error code";
        }
}
