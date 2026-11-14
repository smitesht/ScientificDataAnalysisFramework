#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Records.h"
//#include "Column.h"

namespace SciFlow::Data
{
    /*class DataSet
    {
        public:
            DataSet() = default;
            void addColumn(const std::string& columnName, Column values){
                m_values[columnName] = std::move(values);
            }

            void fromRecords(const Records& records)
            {
                for (const auto& record : records)
                {
                    for (const auto& [key, value] : record)
                    {
                        m_values[key].push_back(value);
                        /std::visit(
                            [&](const auto& v)
                            {
                                using T = std::decay_t<decltype(v)>;

                                if constexpr (std::is_arithmetic_v<T>)
                                {
                                    m_values[key].push_back(
                                        static_cast<double>(v));
                                }
                                 else if constexpr (std::is_same_v<T, std::string>)
                                {
                                    std::cout << "Non-numeric value found!"
                                            << "\nColumn: " << key
                                            << "\nValue: " << v << '\n';
                                }
                                else if constexpr (std::is_same_v<T, std::nullptr_t>)
                                {
                                    std::cout << "Null value found!"
                                            << "\nColumn: " << key << '\n';
                                }
                            },
                            value);/
                    }
                }
            }

            std::unordered_map<std::string, Column> getValues(){
                return m_values;
            }
        private:
            std::unordered_map<std::string, Column> m_values;
    };*/
}