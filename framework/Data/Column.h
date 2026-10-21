#pragma once
#include <string>
#include <vector>

namespace SciFlow::Data
{
    struct Column
    {
        std::string m_Name;
        std::vector<double> m_values;
    };
}