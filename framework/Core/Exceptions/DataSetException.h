#pragma once

#include "SciFlowException.h"

namespace SciFlow::Exception
{
    class DataSetException : public SciFlowException
    {
        public:
            explicit DataSetException(const std::string& message)
                :SciFlowException(message)
            {}
    };
}