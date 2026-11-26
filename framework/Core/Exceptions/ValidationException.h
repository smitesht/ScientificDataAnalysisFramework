#pragma once

#include "SciFlowException.h"

namespace SciFlow::Exception
{
    class ValidationException : public SciFlowException
    {
        public:
            explicit ValidationException(const std::string& message)
                :SciFlowException(message)
            {}
    };
}