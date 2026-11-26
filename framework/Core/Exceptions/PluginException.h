#pragma once

#include "SciFlowException.h"

namespace SciFlow::Exception
{
    class PluginException : public SciFlowException
    {
        public:
            explicit PluginException(const std::string& message)
                :SciFlowException(message)
            {}
    };
}