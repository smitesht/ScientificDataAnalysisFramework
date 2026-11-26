#pragma once

#include "SciFlowException.h"

namespace SciFlow::Exception
{
    class ConfigException : public SciFlowException
    {
        public:
            explicit ConfigException(const std::string& message)
                :SciFlowException(message)
            {}
    };
}