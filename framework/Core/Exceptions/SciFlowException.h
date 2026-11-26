#pragma once
#include <stdexcept>
#include <string>

namespace SciFlow::Exception
{
    class SciFlowException : public std::runtime_error
    {
        public:
            explicit SciFlowException(const std::string& message)
                :std::runtime_error(message)
            {}
    };

}