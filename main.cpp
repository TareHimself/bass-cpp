

#include <iostream>
#include <thread>

#include "bass/bass.hpp"
#include "bass/Stream.hpp"
using namespace std::chrono_literals;
int main()
{
    try
    {
        // bass::init(-1, 44100, 0, nullptr);
        // if(const auto sample = bass::createFileStream(R"(D:\Github\vengine\test\audio\tokyo lofi hiphop.wav)"); sample->Play())
        // {
        //     while(true)
        //     {
        //         std::cout << "POSITION :" << sample->BytesToSeconds(sample->GetPosition(bass::BassPosByte)) << std::endl;
        //         std::this_thread::sleep_for(100ms);
        //     }
        // }
        bass::init(-1, 44100, 0, nullptr);
        if(const auto sample = bass::createFileStream(R"(D:\BH & Kirk Cosier - Slipping Away (ft. Cheney).wav)",0,bass::CreateFlag::SampleFloat | bass::CreateFlag::SampleMono); sample->Play())
        {
            sample->SetAttribute(bass::Attribute::Volume,0.1f);
            while(true)
            {
                std::cout << "Position:" << sample->BytesToSeconds(sample->GetPosition(bass::Position::Byte)) << "     " << "Volume: " << sample->GetAttribute(bass::Attribute::Volume) << std::endl;
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
