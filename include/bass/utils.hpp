#pragma once
#include "types.hpp"
#include <stdexcept>
#include <string>
namespace bass
{
    std::string bassErrorToString(Error error);
    
    template <typename T>
    T throwOrReturn(T&& val)
    {
        const auto err = static_cast<Error>(BASS_ErrorGetCode());
        
        if(err == Error::OK)
        {
            return val;
        }
        
        throw std::runtime_error(bassErrorToString(err));
    }
}
