#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <string_view>
#include <charconv>
#include <variant>
#include <cstdint>
#include <algorithm>
#include <cctype>
#include "Records.h"
#include "IDataLoader.h"

namespace SciFlow::Data
{
    class CsvFileReader : public IDataLoader
    {
        private:
            std::string filePath;

            FieldValue parseCell(const std::string& cell);
            Records read_line();
            std::vector<std::string> getColumnHeaders(std::string line);

            inline std::string getCellValue(std::string cell)
            {
                if(!cell.empty())
                {
                    if(cell[0] == '\"' && cell[cell.length()-1] == '\"')
                        cell = cell.substr(1,cell.length()-2);                   
                }

                return cell;
            }

        protected:
            Records load() override;

        public:
            CsvFileReader(std::string path):filePath(path) {}
            ~CsvFileReader();
    };

}