#include <algorithm>
#include "StatisticsCalculator.h"


namespace SciFlow::Math
{
    double StatisticsCalculator::average(const std::vector<double>& data)
    {
        if(data.size() <= 0)
            return 0;
        
        return (std::accumulate(data.begin(), data.end(),0.0) / data.size());
    }

    double StatisticsCalculator::min(const std::vector<double>& data)
    {
        if(data.size() <= 0)
            return 0;
        
        auto it = std::ranges::min_element(data);
        return it != data.end() ? *it : 0;
    }

    double StatisticsCalculator::max(const std::vector<double>& data)
    {
        if(data.size() <= 0)
            return 0;
        
        auto it = std::ranges::max_element(data);
        return it != data.end() ? *it : 0;
    }

    /*
        var of sample = [sum(Xi - mean)^2] / N-1

        var of population = [sum(Xi - mean)^2] / N
    
    */
    double StatisticsCalculator::variance(const std::vector<double>& data, bool sample)
    {
        if(data.size() < 2)
            return 0.0; 

        double mean = average(data);

        // on each iteration of data, first calculate diff and than add to total.
        // The initial value of total = 0
        double sum_of_squares = std::accumulate(data.begin(), data.end(),0.0,
                    [mean](double total, double elem){
                        double diff = elem - mean;
                        return total + (diff * diff);
                    });
        
        double var = 0.0;

        if(sample == true)
            var = sum_of_squares / (data.size() - 1);
        else
            var = sum_of_squares / (data.size());

        return var;
    }
}