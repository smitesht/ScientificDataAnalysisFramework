#include "JsonFileReader.h"
#include <fstream>

namespace SciFlow::Data
{

    JsonFileReader::~JsonFileReader()
    {

    }

    FieldValue JsonFileReader::convertValue(const json& value)
    {
        if(value.is_null())
            return nullptr;

        if(value.is_boolean())
            return value.get<bool>();

        if(value.is_number_integer())
            return value.get<int64_t>();

        if(value.is_number_float())
            return value.get<double>();

        if(value.is_string())
            return value.get<std::string>();

        throw std::runtime_error("Unsupported JSON value type");
    }

    Records JsonFileReader::extractJsonTags(const json& data)
    {

        Records records;

        if(!data.is_array())
            throw std::runtime_error("Expected JSON array");

        for(const auto& object: data)
        {
            if(!object.is_object())
                throw std::runtime_error("Expected JSON object");

            Record record;

            for(auto it=object.begin(); it != object.end(); ++it)
            {
                record.emplace(it.key(), convertValue(it.value()));
            }

            records.push_back(std::move(record));
        }

        return records;        
    }

    Records JsonFileReader::load()
    {
        Records records;
        std::ifstream file(filePath);
        
        if(!file.is_open()){
            std::cerr << "Error: Could not open file " << filePath <<"\n";
            return records;
        }

        json document;
        file >> document;

        records = extractJsonTags(document);
              
        return records;
    }
}