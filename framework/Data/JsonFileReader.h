#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include "Records.h"
#include "IDataLoader.h"

using json = nlohmann::ordered_json;

namespace SciFlow::Data
{
    class JsonFileReader : public IDataLoader
    {
        private:
            std::string filePath;

            Records extractJsonTags(const json& data);
            FieldValue convertValue(const json& value);

        protected:
            Records load() override;

        public:
            JsonFileReader(std::string path):filePath(path) {}
            ~JsonFileReader();
    };
}