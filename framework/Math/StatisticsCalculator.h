#pragma once
#include <numeric>
#include <vector>

namespace SciFlow::Math
{
    class StatisticsCalculator
    {
        public:
            double average(const std::vector<double>& data);
            double min(const std::vector<double>& data);
            double max(const std::vector<double>& data);
            double variance(const std::vector<double>& data, bool sample=true);
    };
}