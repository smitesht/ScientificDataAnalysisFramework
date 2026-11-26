#include "FileReaderFactory.h"
#include "NumberFileReader.h"
#include "CsvFileReader.h"
#include "JsonFileReader.h"
#include "FileException.h"

namespace SciFlow::Data
{
    std::shared_ptr<SciFlow::Data::IDataLoader> FileReaderFactory::getFileReader(const std::string& filePath,const std::string& fileExt)
    {
        if(fileExt == "csv")
        {
            return std::make_shared<CsvFileReader>(filePath);
        }
        else if(fileExt == "json")
        {
            return std::make_shared<JsonFileReader>(filePath);
        }
        else
        {
            throw SciFlow::Exception::FileException("SciFlow::Exception::FileException - File Extension is not supported " + fileExt);
           // return nullptr;
        }
    }
    
}