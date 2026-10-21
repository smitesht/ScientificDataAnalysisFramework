#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <string_view>
#include "IDataLoader.h"

namespace SciFlow::Data
{

    class NumberFileReader : public IDataLoader
    {
        private:
            std::string filePath;

            // Method to read the file line-by-line into a vector
            DataSet read_line();
            
            std::vector<std::string> getColumnHeaders(std::string line);

            std::vector<double> getRowValues(std::string line);

            inline std::string getCellValue(std::string cell)
            {
                if(!cell.empty())
                {
                    if(cell[0] == '\"' && cell[cell.length()-1] == '\"')
                        cell = cell.substr(1,cell.length()-2);                   
                }

                return cell;
            }

        public:

            explicit NumberFileReader(std::string_view path)
                :filePath(path){}
            
            DataSet load() override;       
    };

}