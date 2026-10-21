#pragma once
#include "DataSet.h"

namespace SciFlow::Data
{
    class IDataLoader
    {
        public:
            virtual ~IDataLoader() = default;
            virtual DataSet load() = 0;
    };
}