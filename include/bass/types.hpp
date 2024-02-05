#pragma once
#include <string>
#include "bass.h"

namespace bass
{
    using WindowHandle = HWND;
    using Vector = BASS_3DVECTOR;
    enum EBassConfig
    {
        ConfigBuffer = BASS_CONFIG_BUFFER,
        ConfigUpdatePeriod = BASS_CONFIG_UPDATEPERIOD,
        ConfigGVolSample = BASS_CONFIG_GVOL_SAMPLE,
        ConfigGVolStream = BASS_CONFIG_GVOL_STREAM,
        ConfigGVolMusic = BASS_CONFIG_GVOL_MUSIC,
        ConfigCurveVol = BASS_CONFIG_CURVE_VOL,
        ConfigCurvePan = BASS_CONFIG_CURVE_PAN,
        ConfigFloatDSP = BASS_CONFIG_FLOATDSP,
        ConfigAlgorithm3D = BASS_CONFIG_3DALGORITHM,
        ConfigNetTimeout = BASS_CONFIG_NET_TIMEOUT,
        ConfigNetBuffer = BASS_CONFIG_NET_BUFFER,
        ConfigPauseNoPlay = BASS_CONFIG_PAUSE_NOPLAY,
        ConfigNetPreBuf = BASS_CONFIG_NET_PREBUF,
        ConfigNetPassive = BASS_CONFIG_NET_PASSIVE,
        ConfigRecBuffer = BASS_CONFIG_REC_BUFFER,
        ConfigNetPlaylist = BASS_CONFIG_NET_PLAYLIST,
        ConfigMusicVirtual = BASS_CONFIG_MUSIC_VIRTUAL,
        ConfigVerify = BASS_CONFIG_VERIFY,
        ConfigUpdateThreads = BASS_CONFIG_UPDATETHREADS,
        ConfigDevBuffer = BASS_CONFIG_DEV_BUFFER,
        ConfigRecLoopback = BASS_CONFIG_REC_LOOPBACK,
        ConfigVistaTruePos = BASS_CONFIG_VISTA_TRUEPOS,
        ConfigIOSSession = BASS_CONFIG_IOS_SESSION,
        ConfigIOSMixAudio = BASS_CONFIG_IOS_MIXAUDIO,
        ConfigDevDefault = BASS_CONFIG_DEV_DEFAULT,
        ConfigNetReadTimeout = BASS_CONFIG_NET_READTIMEOUT,
        ConfigVistaSpeakers = BASS_CONFIG_VISTA_SPEAKERS,
        ConfigIOSSpeaker = BASS_CONFIG_IOS_SPEAKER,
        ConfigMFDisable = BASS_CONFIG_MF_DISABLE,
        ConfigHandles = BASS_CONFIG_HANDLES,
        ConfigUnicode = BASS_CONFIG_UNICODE,
        ConfigSRC = BASS_CONFIG_SRC,
        ConfigSRCSample = BASS_CONFIG_SRC_SAMPLE,
        ConfigAsyncFileBuffer = BASS_CONFIG_ASYNCFILE_BUFFER,
        ConfigOggPrescan = BASS_CONFIG_OGG_PRESCAN,
        ConfigMFVideo = BASS_CONFIG_MF_VIDEO,
        ConfigAirPlay = BASS_CONFIG_AIRPLAY,
        ConfigDevNonStop = BASS_CONFIG_DEV_NONSTOP,
        ConfigIOSNoCategory = BASS_CONFIG_IOS_NOCATEGORY,
        ConfigVerifyNet = BASS_CONFIG_VERIFY_NET,
        ConfigDevPeriod = BASS_CONFIG_DEV_PERIOD,
        ConfigFloatConfig = BASS_CONFIG_FLOAT,
        ConfigNetSeek = BASS_CONFIG_NET_SEEK,
        ConfigAMDisable = BASS_CONFIG_AM_DISABLE,
        ConfigNetPlaylistDepth = BASS_CONFIG_NET_PLAYLIST_DEPTH,
        ConfigNetPreBufWait = BASS_CONFIG_NET_PREBUF_WAIT,
        ConfigAndroidSessionID = BASS_CONFIG_ANDROID_SESSIONID,
        ConfigWASAPIPersist = BASS_CONFIG_WASAPI_PERSIST,
        ConfigRecWASAPI = BASS_CONFIG_REC_WASAPI,
        ConfigAndroidAAudio = BASS_CONFIG_ANDROID_AAUDIO,
        ConfigSampleOneHandle = BASS_CONFIG_SAMPLE_ONEHANDLE,
        ConfigNetMeta = BASS_CONFIG_NET_META,
        ConfigNetRestrRate = BASS_CONFIG_NET_RESTRATE,
        ConfigRecDefault = BASS_CONFIG_REC_DEFAULT,
        ConfigNoRamp = BASS_CONFIG_NORAMP,

        // BASS_SetConfigPtr options
        ConfigNetAgent = BASS_CONFIG_NET_AGENT,
        ConfigNetProxy = BASS_CONFIG_NET_PROXY,
        ConfigIOSNotify = BASS_CONFIG_IOS_NOTIFY,
        ConfigAndroidJavaVM = BASS_CONFIG_ANDROID_JAVAVM,
        ConfigLibSSL = BASS_CONFIG_LIBSSL,
        ConfigFileName = BASS_CONFIG_FILENAME,

        ConfigThreadFlag = BASS_CONFIG_THREAD // flag: thread-specific setting
    };

    enum EBassCreate
    {
        // 8 bit
        CreateSampleBits = BASS_SAMPLE_8BITS,
        // 32 bit floating-point
        CreateSampleFloat = BASS_SAMPLE_FLOAT,
        // mono
        CreateSampleMono = BASS_SAMPLE_MONO,
        // looped
        CreateSampleLooped = BASS_SAMPLE_LOOP,
        // 3D functionality
        CreateSampleSpatial = BASS_SAMPLE_3D,
        // unused
        CreateSampleSoftware = BASS_SAMPLE_SOFTWARE,
        // mute at max distance (3D only)
        CreateSampleMuteMax = BASS_SAMPLE_MUTEMAX,
        // unused
        CreateSampleVAM = BASS_SAMPLE_VAM,
        // unused
        CreateSampleFX = BASS_SAMPLE_FX,
        // override lowest volume
        CreateSampleOverVol = BASS_SAMPLE_OVER_VOL,
        // override longest playing
        CreateSampleOverPos = BASS_SAMPLE_OVER_POS,
        // override furthest from listener (3D only)
        CreateSampleOverDist = BASS_SAMPLE_OVER_DIST,
        // scan file for accurate seeking and length
        CreateStreamPreScan = BASS_STREAM_PRESCAN,
        // automatically free the stream when it stops/ends
        CreateStreamAutoFree = BASS_STREAM_AUTOFREE,
        // restrict the download rate of internet file stream
        CreateStreamRestrictRate = BASS_STREAM_RESTRATE,
        // download internet file stream in small blocks
        CreateStreamBlock = BASS_STREAM_BLOCK,
        // don't play the stream, only decode
        CreateStreamDecode = BASS_STREAM_DECODE,
        // give server status info (HTTP/ICY tags) in DOWNLOADPROC
        CreateStreamStatus = BASS_STREAM_STATUS
    };

    enum EBassState
    {
        // The channel is not active, or handle is not a valid channel.
        StateStopped = BASS_ACTIVE_STOPPED,
        // The channel is playing (or recording).
        StatePlaying = BASS_ACTIVE_PLAYING,
        // The channel is paused.
        StatePaused = BASS_ACTIVE_PAUSED,
        // The channel's device is paused.
        StatePausedDevice = BASS_ACTIVE_PAUSED_DEVICE,
        // Playback of the stream has been stalled due to a lack of sample data. Playback will automatically resume once there is sufficient data to do so.
        StateStalled = BASS_ACTIVE_STALLED
    };

    enum EBassPos
    {
        // byte position
        PosByte = BASS_POS_BYTE,
        // order.row position, MAKELONG(order,row)
        PosMusicOrder = BASS_POS_MUSIC_ORDER,
        // OGG bitstream number
        PosOGG = BASS_POS_OGG,
        // trimmed end position
        PosEnd = BASS_POS_END,
        // loop start position
        PosLoop = BASS_POS_LOOP,
        // flag: flush decoder/FX buffers
        PosFlush = BASS_POS_FLUSH,
        // flag: reset user file buffers
        PosReset = BASS_POS_RESET,
        // flag: seek relative to the current position
        PosRelative = BASS_POS_RELATIVE,
        // flag: allow seeking to an inexact position
        PosInexact = BASS_POS_INEXACT,
        // flag: get the decoding (not playing) position
        PosDecode = BASS_POS_DECODE,
        // flag: decode to the position instead of seeking
        PosDecodeTo = BASS_POS_DECODETO,
        // flag: scan to the position
        PosScan = BASS_POS_SCAN
    };

    enum EBassError
    {
        // All is OK
        ErrorOK = BASS_OK,
        // Memory error
        ErrorMemory = BASS_ERROR_MEM,
        // Can't open the file
        ErrorFileOpen = BASS_ERROR_FILEOPEN,
        // Can't find a free/valid driver
        ErrorDriver = BASS_ERROR_DRIVER,
        // The sample buffer was lost
        ErrorBufferLost = BASS_ERROR_BUFLOST,
        // Invalid handle
        ErrorHandle = BASS_ERROR_HANDLE,
        // Unsupported sample format
        ErrorFormat = BASS_ERROR_FORMAT,
        // Invalid position
        ErrorPosition = BASS_ERROR_POSITION,
        // BASS_Init has not been successfully called
        ErrorInit = BASS_ERROR_INIT,
        // BASS_Start has not been successfully called
        ErrorStart = BASS_ERROR_START,
        // SSL/HTTPS support isn't available
        ErrorSSL = BASS_ERROR_SSL,
        // Device needs to be reinitialized
        ErrorReinit = BASS_ERROR_REINIT,
        // Already initialized/paused/whatever
        ErrorAlready = BASS_ERROR_ALREADY,
        // File does not contain audio
        ErrorNotAudio = BASS_ERROR_NOTAUDIO,
        // Can't get a free channel
        ErrorNoChannel = BASS_ERROR_NOCHAN,
        // An illegal type was specified
        ErrorIllegalType = BASS_ERROR_ILLTYPE,
        // An illegal parameter was specified
        ErrorIllegalParam = BASS_ERROR_ILLPARAM,
        // No 3D support
        ErrorNo3D = BASS_ERROR_NO3D,
        // No EAX support
        ErrorNoEAX = BASS_ERROR_NOEAX,
        // Illegal device number
        ErrorDevice = BASS_ERROR_DEVICE,
        // Not playing
        ErrorNoPlay = BASS_ERROR_NOPLAY,
        // Illegal sample rate
        ErrorFrequency = BASS_ERROR_FREQ,
        // The stream is not a file stream
        ErrorNotFile = BASS_ERROR_NOTFILE,
        // No hardware voices available
        ErrorNoHardware = BASS_ERROR_NOHW,
        // The file has no sample data
        ErrorEmpty = BASS_ERROR_EMPTY,
        // No internet connection could be opened
        ErrorNoInternet = BASS_ERROR_NONET,
        // Couldn't create the file
        ErrorCreate = BASS_ERROR_CREATE,
        // Effects are not available
        ErrorNoFX = BASS_ERROR_NOFX,
        // Requested data/action is not available
        ErrorNotAvailable = BASS_ERROR_NOTAVAIL,
        // The channel is/isn't a "decoding channel"
        ErrorDecode = BASS_ERROR_DECODE,
        // A sufficient DirectX version is not installed
        ErrorDX = BASS_ERROR_DX,
        // Connection timed out
        ErrorTimeout = BASS_ERROR_TIMEOUT,
        // Unsupported file format
        ErrorFileFormat = BASS_ERROR_FILEFORM,
        // Unavailable speaker
        ErrorSpeaker = BASS_ERROR_SPEAKER,
        // Invalid BASS version (used by add-ons)
        ErrorVersion = BASS_ERROR_VERSION,
        // Codec is not available/supported
        ErrorCodec = BASS_ERROR_CODEC,
        // The channel/file has ended
        ErrorEnded = BASS_ERROR_ENDED,
        // The device is busy
        ErrorBusy = BASS_ERROR_BUSY,
        // Unstreamable file
        ErrorUnstreamable = BASS_ERROR_UNSTREAMABLE,
        // Unsupported protocol
        ErrorProtocol = BASS_ERROR_PROTOCOL,
        // Access denied
        ErrorDenied = BASS_ERROR_DENIED,
        // Some other mystery problem
        ErrorUnknown = BASS_ERROR_UNKNOWN
    };

    enum EBassAttribute
    {
        AttributeFrequency = BASS_ATTRIB_FREQ,
        AttributeVolume = BASS_ATTRIB_VOL,
        AttributePan = BASS_ATTRIB_PAN,
        AttributeEAXMix = BASS_ATTRIB_EAXMIX,
        AttributeNoBuffer = BASS_ATTRIB_NOBUFFER,
        AttributeVBR = BASS_ATTRIB_VBR,
        AttributeCPU = BASS_ATTRIB_CPU,
        AttributeSRC = BASS_ATTRIB_SRC,
        AttributeNetResume = BASS_ATTRIB_NET_RESUME,
        AttributeScanInfo = BASS_ATTRIB_SCANINFO,
        AttributeNoRamp = BASS_ATTRIB_NORAMP,
        AttributeBitrate = BASS_ATTRIB_BITRATE,
        AttributeBuffer = BASS_ATTRIB_BUFFER,
        AttributeGranule = BASS_ATTRIB_GRANULE,
        AttributeUser = BASS_ATTRIB_USER,
        AttributeTail = BASS_ATTRIB_TAIL,
        AttributePushLimit = BASS_ATTRIB_PUSH_LIMIT,
        AttributeDownloadProc = BASS_ATTRIB_DOWNLOADPROC,
        AttributeVolDSP = BASS_ATTRIB_VOLDSP,
        AttributeVolDSPPriority = BASS_ATTRIB_VOLDSP_PRIORITY,
        AttributeMusicAmplify = BASS_ATTRIB_MUSIC_AMPLIFY,
        AttributeMusicPanSep = BASS_ATTRIB_MUSIC_PANSEP,
        AttributeMusicPScaler = BASS_ATTRIB_MUSIC_PSCALER,
        AttributeMusicBPM = BASS_ATTRIB_MUSIC_BPM,
        AttributeMusicSpeed = BASS_ATTRIB_MUSIC_SPEED,
        AttributeMusicVolGlobal = BASS_ATTRIB_MUSIC_VOL_GLOBAL,
        AttributeMusicActive = BASS_ATTRIB_MUSIC_ACTIVE,
        AttributeMusicVolChan = BASS_ATTRIB_MUSIC_VOL_CHAN,
        // + channel #
        AttributeMusicVolInst = BASS_ATTRIB_MUSIC_VOL_INST // + instrument #
    };

    enum EBass3DMode
    {
        B3DModeNormal = BASS_3DMODE_NORMAL,
        B3DModeRelative = BASS_3DMODE_RELATIVE,
        B3DModeOff = BASS_3DMODE_OFF
    };

    struct BassDevice
    {
        DWORD id;
        std::string name;
        std::string driver;
        DWORD flags;

        BassDevice& operator=(const BASS_DEVICEINFO& other)
        {
            name = other.name;
            driver = other.driver;
            flags = other.flags;
            return *this;
        }
    };
}
