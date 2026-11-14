#include <numeric>
#include "StatisticsPlugin.h"

using AnalysisResult = SciFlow::AnalysisResults::AnalysisResult;
using ResultStatus = SciFlow::AnalysisResults::ResultStatus;

namespace SciFlow::Plugins
{
    extern "C" std::shared_ptr<IAnalysisPlugin> createPlugin()
    {
        return std::make_shared<StatisticsPlugin>();
    }

    std::optional<double> StatisticsPlugin::getNumericValue(const SciFlow::Data::FieldValue& value)
    {
        return std::visit([](const auto& v) -> std::optional<double>
        {
            using T = std::decay_t<decltype(v)>;

            if constexpr (std::is_same_v<T, int64_t> ||
                        std::is_same_v<T, double>)
            {
                return static_cast<double>(v);
            }
            else
            {
                return std::nullopt;
            }
        }, value);
    }

    void StatisticsPlugin::printValue(const SciFlow::Data::FieldValue& value)
    {
        std::visit([](const auto& v)
        {
            using T = std::decay_t<decltype(v)>;

            if constexpr (std::is_same_v<T, std::nullptr_t>)
            {
                std::cout << "NULL";
            }
            else if constexpr (std::is_same_v<T, bool>)
            {
                std::cout << (v ? "true" : "false");
            }
            else
            {
                std::cout << v;
            }

        }, value);
    }

    void StatisticsPlugin::printRecords(const SciFlow::Data::Records& records)
    {
        int row = 1;

        for (const auto& record : records)
        {
            std::cout << "\nRecord " << row++ << '\n';

            for (const auto& [key, value] : record)
            {
                std::cout << key << " : ";
                printValue(value);
                std::cout << '\n';
            }
        }
    }

    SciFlow::AnalysisResults::AnalysisResult StatisticsPlugin::execute(std::shared_ptr<SciFlow::Data::IDataLoader> dataLoader)
    {
        SciFlow::Data::Records records = dataLoader->load();
        
        //auto values = ds.getValues();
        if(records.size() <= 0)
        {
            return AnalysisResult{m_strPluginName,ResultStatus::Failure,"Empty dataset"};
        }
        
        AnalysisResult anaResult{m_strPluginName,ResultStatus::Success,""};

        SciFlow::Data::DataSet dataSet;

        for (const auto& record : records)
        {
            for (const auto& [key, value] : record)
            {
                if(auto val = getNumericValue(value))
                {
                    dataSet[key].push_back(*val); 
                }            
            }
        }

        for(const auto& columnData: dataSet)
        {
            const auto[colName, values] = columnData;
            
            double avg = m_statCalculator.average(values);
            anaResult.addColumnMetric("average", colName, avg);

            double min = m_statCalculator.min(values);
            anaResult.addColumnMetric("min", colName, min);

            double max = m_statCalculator.max(values);
            anaResult.addColumnMetric("max", colName, max);

            double var = m_statCalculator.variance(values);
            anaResult.addColumnMetric("variance", colName, var);
        }

        return anaResult;
    }
}