#pragma once

#include "SciFlowException.h"

namespace SciFlow::Exception
{
    class FileException : public SciFlowException
    {
        public:
            explicit FileException(const std::string& message)
                :SciFlowException(message)
            {}
    };
}