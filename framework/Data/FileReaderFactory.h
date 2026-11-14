#pragma once

#include <string>
#include <memory>
#include "IDataLoader.h"

namespace SciFlow::Data
{
    class FileReaderFactory
    {
        public:
            FileReaderFactory() = default;

            std::shared_ptr<SciFlow::Data::IDataLoader>  getFileReader(const std::string& filePath,const std::string& fileExt);
    };
}