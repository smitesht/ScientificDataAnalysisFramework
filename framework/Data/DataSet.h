#pragma once
#include <vector>
#include <unordered_map>
//#include "Column.h"

namespace SciFlow::Data
{
    class DataSet
    {
        public:
            DataSet() = default;
            void addColumn(const std::string& columnName, std::vector<double> values){
                m_values[columnName] = values;
            }

            std::unordered_map<std::string, std::vector<double>> getValues(){
                return m_values;
            }
        private:
            std::unordered_map<std::string, std::vector<double>> m_values;
    };
}