

#include <iostream>

#include "bass/Bass.hpp"
#include "bass/Stream.hpp"
using namespace std::chrono_literals;
int main()
{
    try
    {
        // bass::init(-1, 44100, 0, nullptr);
        // if(const auto sample = bass::createFileStream(R"(D:\Github\vengine\test\a            udio\tokyo lofi hiphop.wav)"); sample->Play())
        // {
        //     while(true)
        //     {
        //         std::cout << "POSITION :" << sample->BytesToSeconds(sample->GetPosition(bass::BassPosByte)) << std::endl;
        //         std::this_thread::sleep_for(100ms);
        //     }
        // }
        bass::init(-1, 44100, 0, nullptr);
        if(const auto sample = bass::createFileStream(R"(D:\BH & Kirk Cosier - Slipping Away (ft. Cheney).wav)",0,bass::CreateSampleFloat | bass::CreateSampleMono); sample->Play())
        {
            sample->SetAttribute(bass::AttributeVolume,0.1f);
            while(true)
            {
                std::cout << "Position:" << sample->BytesToSeconds(sample->GetPosition(bass::PosByte)) << "     " << "Volume: " << sample->GetAttribute(bass::AttributeVolume) << std::endl;
                std::this_thread::sleep_for(100ms);
            }
        }
    }
    catch (const std::exception& err)
    {
        std::cerr << "ERROR: " << err.what() << std::endl;
    }
    return 0;
}
