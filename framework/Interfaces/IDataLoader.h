#pragma once
#include "Records.h"

namespace SciFlow::Data
{
    class IDataLoader
    {
        public:
            virtual ~IDataLoader() = default;
            //virtual DataSet load() = 0;
            virtual Records load() = 0;
    };
}