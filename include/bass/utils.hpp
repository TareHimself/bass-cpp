#pragma once
#include "types.hpp"
#include <stdexcept>
#include <string>
namespace bass
{
    std::string bassErrorToString(EBassError error);
    template <typename T>
    T throwOrReturn(T&& val)
    {
        const auto err = static_cast<EBassError>(BASS_ErrorGetCode());
        
        if(err == ErrorOK)
        {
            return val;
        }
        
        throw std::runtime_error(bassErrorToString(err));
    }
}
