#include <bass.h>

#include <bass/utils.hpp>
#include <bass/types.hpp>

namespace bass
{
    std::string bassErrorToString(EBassError error)
    {
            switch (error)
            {
            case ErrorOK:
                return "All is OK, yet you saw this ?";
            case ErrorMemory:
                return "Memory error";
            case ErrorFileOpen:
                return "Can't open the file";
            case ErrorDriver:
                return "Can't find a free/valid driver";
            case ErrorBufferLost:
                return "The sample buffer was lost";
            case ErrorHandle:
                return "Invalid handle";
            case ErrorFormat:
                return "Unsupported sample format";
            case ErrorPosition:
                return "Invalid position";
            case ErrorInit:
                return "BASS_Init has not been successfully called";
            case ErrorStart:
                return "BASS_Start has not been successfully called";
            case ErrorSSL:
                return "SSL/HTTPS support isn't available";
            case ErrorReinit:
                return "Device needs to be reinitialized";
            case ErrorAlready:
                return "Already initialized/paused/whatever";
            case ErrorNotAudio:
                return "File does not contain audio";
            case ErrorNoChannel:
                return "Can't get a free channel";
            case ErrorIllegalType:
                return "An illegal type was specified";
            case ErrorIllegalParam:
                return "An illegal parameter was specified";
            case ErrorNo3D:
                return "No 3D support";
            case ErrorNoEAX:
                return "No EAX support";
            case ErrorDevice:
                return "Illegal device number";
            case ErrorNoPlay:
                return "Not playing";
            case ErrorFrequency:
                return "Illegal sample rate";
            case ErrorNotFile:
                return "The stream is not a file stream";
            case ErrorNoHardware:
                return "No hardware voices available";
            case ErrorEmpty:
                return "The file has no sample data";
            case ErrorNoInternet:
                return "No internet connection could be opened";
            case ErrorCreate:
                return "Couldn't create the file";
            case ErrorNoFX:
                return "Effects are not available";
            case ErrorNotAvailable:
                return "Requested data/action is not available";
            case ErrorDecode:
                return "The channel is/isn't a 'decoding channel'";
            case ErrorDX:
                return "A sufficient DirectX version is not installed";
            case ErrorTimeout:
                return "Connection timed out";
            case ErrorFileFormat:
                return "Unsupported file format";
            case ErrorSpeaker:
                return "Unavailable speaker";
            case ErrorVersion:
                return "Invalid BASS version (used by add-ons)";
            case ErrorCodec:
                return "Codec is not available/supported";
            case ErrorEnded:
                return "The channel/file has ended";
            case ErrorBusy:
                return "The device is busy";
            case ErrorUnstreamable:
                return "Unstreamable file";
            case ErrorProtocol:
                return "Unsupported protocol";
            case ErrorDenied:
                return "Access denied";
            case ErrorUnknown:
                return "Some other mystery problem";
            }

            return "Invalid error code";
        }
}
