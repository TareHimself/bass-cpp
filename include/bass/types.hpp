#pragma once
#include <string>
#include "bass.h"

namespace bass
{
    using WindowHandle = HWND;
    using Vector = BASS_3DVECTOR;
    enum class Config
    {
        Buffer = BASS_CONFIG_BUFFER,
        UpdatePeriod = BASS_CONFIG_UPDATEPERIOD,
        GVolSample = BASS_CONFIG_GVOL_SAMPLE,
        GVolStream = BASS_CONFIG_GVOL_STREAM,
        GVolMusic = BASS_CONFIG_GVOL_MUSIC,
        CurveVol = BASS_CONFIG_CURVE_VOL,
        CurvePan = BASS_CONFIG_CURVE_PAN,
        FloatDSP = BASS_CONFIG_FLOATDSP,
        Algorithm3D = BASS_CONFIG_3DALGORITHM,
        NetTimeout = BASS_CONFIG_NET_TIMEOUT,
        NetBuffer = BASS_CONFIG_NET_BUFFER,
        PauseNoPlay = BASS_CONFIG_PAUSE_NOPLAY,
        NetPreBuf = BASS_CONFIG_NET_PREBUF,
        NetPassive = BASS_CONFIG_NET_PASSIVE,
        RecBuffer = BASS_CONFIG_REC_BUFFER,
        NetPlaylist = BASS_CONFIG_NET_PLAYLIST,
        MusicVirtual = BASS_CONFIG_MUSIC_VIRTUAL,
        Verify = BASS_CONFIG_VERIFY,
        UpdateThreads = BASS_CONFIG_UPDATETHREADS,
        DevBuffer = BASS_CONFIG_DEV_BUFFER,
        RecLoopback = BASS_CONFIG_REC_LOOPBACK,
        VistaTruePos = BASS_CONFIG_VISTA_TRUEPOS,
        IOSSession = BASS_CONFIG_IOS_SESSION,
        IOSMixAudio = BASS_CONFIG_IOS_MIXAUDIO,
        DevDefault = BASS_CONFIG_DEV_DEFAULT,
        NetReadTimeout = BASS_CONFIG_NET_READTIMEOUT,
        VistaSpeakers = BASS_CONFIG_VISTA_SPEAKERS,
        IOSSpeaker = BASS_CONFIG_IOS_SPEAKER,
        MFDisable = BASS_CONFIG_MF_DISABLE,
        Handles = BASS_CONFIG_HANDLES,
        Unicode = BASS_CONFIG_UNICODE,
        SRC = BASS_CONFIG_SRC,
        SRCSample = BASS_CONFIG_SRC_SAMPLE,
        AsyncFileBuffer = BASS_CONFIG_ASYNCFILE_BUFFER,
        OggPrescan = BASS_CONFIG_OGG_PRESCAN,
        MFVideo = BASS_CONFIG_MF_VIDEO,
        AirPlay = BASS_CONFIG_AIRPLAY,
        DevNonStop = BASS_CONFIG_DEV_NONSTOP,
        IOSNoCategory = BASS_CONFIG_IOS_NOCATEGORY,
        VerifyNet = BASS_CONFIG_VERIFY_NET,
        DevPeriod = BASS_CONFIG_DEV_PERIOD,
        FloatConfig = BASS_CONFIG_FLOAT,
        NetSeek = BASS_CONFIG_NET_SEEK,
        AMDisable = BASS_CONFIG_AM_DISABLE,
        NetPlaylistDepth = BASS_CONFIG_NET_PLAYLIST_DEPTH,
        NetPreBufWait = BASS_CONFIG_NET_PREBUF_WAIT,
        AndroidSessionID = BASS_CONFIG_ANDROID_SESSIONID,
        WASAPIPersist = BASS_CONFIG_WASAPI_PERSIST,
        RecWASAPI = BASS_CONFIG_REC_WASAPI,
        AndroidAAudio = BASS_CONFIG_ANDROID_AAUDIO,
        SampleOneHandle = BASS_CONFIG_SAMPLE_ONEHANDLE,
        NetMeta = BASS_CONFIG_NET_META,
        NetRestrRate = BASS_CONFIG_NET_RESTRATE,
        RecDefault = BASS_CONFIG_REC_DEFAULT,
        NoRamp = BASS_CONFIG_NORAMP,

        // BASS_SetConfigPtr options
        NetAgent = BASS_CONFIG_NET_AGENT,
        NetProxy = BASS_CONFIG_NET_PROXY,
        IOSNotify = BASS_CONFIG_IOS_NOTIFY,
        AndroidJavaVM = BASS_CONFIG_ANDROID_JAVAVM,
        LibSSL = BASS_CONFIG_LIBSSL,
        FileName = BASS_CONFIG_FILENAME,

        ThreadFlag = BASS_CONFIG_THREAD // flag: thread-specific setting
    };

    

    enum class CreateFlag : DWORD
    {
        // 8 bit
        SampleBits = BASS_SAMPLE_8BITS,
        // 32 bit floating-point
        SampleFloat = BASS_SAMPLE_FLOAT,
        // mono
        SampleMono = BASS_SAMPLE_MONO,
        // looped
        SampleLooped = BASS_SAMPLE_LOOP,
        // 3D functionality
        SampleSpatial = BASS_SAMPLE_3D,
        // unused
        SampleSoftware = BASS_SAMPLE_SOFTWARE,
        // mute at max distance (3D only)
        SampleMuteMax = BASS_SAMPLE_MUTEMAX,
        // unused
        SampleVAM = BASS_SAMPLE_VAM,
        // unused
        SampleFX = BASS_SAMPLE_FX,
        // override lowest volume
        SampleOverVol = BASS_SAMPLE_OVER_VOL,
        // override longest playing
        SampleOverPos = BASS_SAMPLE_OVER_POS,
        // override furthest from listener (3D only)
        SampleOverDist = BASS_SAMPLE_OVER_DIST,
        // scan file for accurate seeking and length
        StreamPreScan = BASS_STREAM_PRESCAN,
        // automatically free the stream when it stops/ends
        StreamAutoFree = BASS_STREAM_AUTOFREE,
        // restrict the download rate of internet file stream
        StreamRestrictRate = BASS_STREAM_RESTRATE,
        // download internet file stream in small blocks
        StreamBlock = BASS_STREAM_BLOCK,
        // don't play the stream, only decode
        StreamDecode = BASS_STREAM_DECODE,
        // give server status info (HTTP/ICY tags) in DOWNLOADPROC
        StreamStatus = BASS_STREAM_STATUS
    };

    inline CreateFlag operator |(CreateFlag a, CreateFlag b) {
        return static_cast<CreateFlag>(static_cast<DWORD>(a) | static_cast<DWORD>(b));
    }

    
    
    enum class State
    {
        // The channel is not active, or handle is not a valid channel.
        Stopped = BASS_ACTIVE_STOPPED,
        // The channel is playing (or recording).
        Playing = BASS_ACTIVE_PLAYING,
        // The channel is paused.
        Paused = BASS_ACTIVE_PAUSED,
        // The channel's device is paused.
        PausedDevice = BASS_ACTIVE_PAUSED_DEVICE,
        // Playback of the stream has been stalled due to a lack of sample data. Playback will automatically resume once there is sufficient data to do so.
        Stalled = BASS_ACTIVE_STALLED
    };

    enum class Position
    {
        // byte position
        Byte = BASS_POS_BYTE,
        // order.row position, MAKELONG(order,row)
        MusicOrder = BASS_POS_MUSIC_ORDER,
        // OGG bitstream number
        OGG = BASS_POS_OGG,
        // trimmed end position
        End = BASS_POS_END,
        // loop start position
        Loop = BASS_POS_LOOP,
        // flag: flush decoder/FX buffers
        Flush = BASS_POS_FLUSH,
        // flag: reset user file buffers
        Reset = BASS_POS_RESET,
        // flag: seek relative to the current position
        Relative = BASS_POS_RELATIVE,
        // flag: allow seeking to an inexact position
        Inexact = BASS_POS_INEXACT,
        // flag: get the decoding (not playing) position
        Decode = BASS_POS_DECODE,
        // flag: decode to the position instead of seeking
        DecodeTo = BASS_POS_DECODETO,
        // flag: scan to the position
        Scan = BASS_POS_SCAN
    };

    enum class Error
    {
        // All is OK
        OK = BASS_OK,
        // Memory error
        Memory = BASS_ERROR_MEM,
        // Can't open the file
        FileOpen = BASS_ERROR_FILEOPEN,
        // Can't find a free/valid driver
        Driver = BASS_ERROR_DRIVER,
        // The sample buffer was lost
        BufferLost = BASS_ERROR_BUFLOST,
        // Invalid handle
        Handle = BASS_ERROR_HANDLE,
        // Unsupported sample format
        Format = BASS_ERROR_FORMAT,
        // Invalid position
        Position = BASS_ERROR_POSITION,
        // BASS_Init has not been successfully called
        Init = BASS_ERROR_INIT,
        // BASS_Start has not been successfully called
        Start = BASS_ERROR_START,
        // SSL/HTTPS support isn't available
        SSL = BASS_ERROR_SSL,
        // Device needs to be reinitialized
        Reinit = BASS_ERROR_REINIT,
        // Already initialized/paused/whatever
        Already = BASS_ERROR_ALREADY,
        // File does not contain audio
        NotAudio = BASS_ERROR_NOTAUDIO,
        // Can't get a free channel
        NoChannel = BASS_ERROR_NOCHAN,
        // An illegal type was specified
        IllegalType = BASS_ERROR_ILLTYPE,
        // An illegal parameter was specified
        IllegalParam = BASS_ERROR_ILLPARAM,
        // No 3D support
        No3D = BASS_ERROR_NO3D,
        // No EAX support
        NoEAX = BASS_ERROR_NOEAX,
        // Illegal device number
        Device = BASS_ERROR_DEVICE,
        // Not playing
        NoPlay = BASS_ERROR_NOPLAY,
        // Illegal sample rate
        Frequency = BASS_ERROR_FREQ,
        // The stream is not a file stream
        NotFile = BASS_ERROR_NOTFILE,
        // No hardware voices available
        NoHardware = BASS_ERROR_NOHW,
        // The file has no sample data
        Empty = BASS_ERROR_EMPTY,
        // No internet connection could be opened
        NoInternet = BASS_ERROR_NONET,
        // Couldn't create the file
        Create = BASS_ERROR_CREATE,
        // Effects are not available
        NoFX = BASS_ERROR_NOFX,
        // Requested data/action is not available
        NotAvailable = BASS_ERROR_NOTAVAIL,
        // The channel is/isn't a "decoding channel"
        Decode = BASS_ERROR_DECODE,
        // A sufficient DirectX version is not installed
        DX = BASS_ERROR_DX,
        // Connection timed out
        Timeout = BASS_ERROR_TIMEOUT,
        // Unsupported file format
        FileFormat = BASS_ERROR_FILEFORM,
        // Unavailable speaker
        Speaker = BASS_ERROR_SPEAKER,
        // Invalid BASS version (used by add-ons)
        Version = BASS_ERROR_VERSION,
        // Codec is not available/supported
        Codec = BASS_ERROR_CODEC,
        // The channel/file has ended
        Ended = BASS_ERROR_ENDED,
        // The device is busy
        Busy = BASS_ERROR_BUSY,
        // Unstreamable file
        Unstreamable = BASS_ERROR_UNSTREAMABLE,
        // Unsupported protocol
        Protocol = BASS_ERROR_PROTOCOL,
        // Access denied
        Denied = BASS_ERROR_DENIED,
        // Some other mystery problem
        Unknown = BASS_ERROR_UNKNOWN
    };

    enum class Attribute
    {
        Frequency = BASS_ATTRIB_FREQ,
        Volume = BASS_ATTRIB_VOL,
        Pan = BASS_ATTRIB_PAN,
        EAXMix = BASS_ATTRIB_EAXMIX,
        NoBuffer = BASS_ATTRIB_NOBUFFER,
        VBR = BASS_ATTRIB_VBR,
        CPU = BASS_ATTRIB_CPU,
        SRC = BASS_ATTRIB_SRC,
        NetResume = BASS_ATTRIB_NET_RESUME,
        ScanInfo = BASS_ATTRIB_SCANINFO,
        NoRamp = BASS_ATTRIB_NORAMP,
        Bitrate = BASS_ATTRIB_BITRATE,
        Buffer = BASS_ATTRIB_BUFFER,
        Granule = BASS_ATTRIB_GRANULE,
        User = BASS_ATTRIB_USER,
        Tail = BASS_ATTRIB_TAIL,
        PushLimit = BASS_ATTRIB_PUSH_LIMIT,
        DownloadProc = BASS_ATTRIB_DOWNLOADPROC,
        VolDSP = BASS_ATTRIB_VOLDSP,
        VolDSPPriority = BASS_ATTRIB_VOLDSP_PRIORITY,
        MusicAmplify = BASS_ATTRIB_MUSIC_AMPLIFY,
        MusicPanSep = BASS_ATTRIB_MUSIC_PANSEP,
        MusicPScaler = BASS_ATTRIB_MUSIC_PSCALER,
        MusicBPM = BASS_ATTRIB_MUSIC_BPM,
        MusicSpeed = BASS_ATTRIB_MUSIC_SPEED,
        MusicVolGlobal = BASS_ATTRIB_MUSIC_VOL_GLOBAL,
        MusicActive = BASS_ATTRIB_MUSIC_ACTIVE,
        MusicVolChan = BASS_ATTRIB_MUSIC_VOL_CHAN,
        // + channel #
        MusicVolInst = BASS_ATTRIB_MUSIC_VOL_INST // + instrument #
    };

    enum class SpatialMode
    {
        Normal = BASS_3DMODE_NORMAL,
        Relative = BASS_3DMODE_RELATIVE,
        Off = BASS_3DMODE_OFF
    };

    struct Device
    {
        DWORD id;
        std::string name;
        std::string driver;
        DWORD flags;

        Device& operator=(const BASS_DEVICEINFO& other)
        {
            name = other.name;
            driver = other.driver;
            flags = other.flags;
            return *this;
        }
    };
}
