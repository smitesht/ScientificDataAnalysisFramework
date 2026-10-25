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

    SciFlow::AnalysisResults::AnalysisResult StatisticsPlugin::execute(SciFlow::Data::IDataLoader& dataLoader)
    {
        SciFlow::Data::DataSet ds = dataLoader.load();
        auto values = ds.getValues();
        if(values.size() <= 0)
        {
            return AnalysisResult{m_strPluginName,ResultStatus::Failure,"Empty dataset"};
        }
        
        AnalysisResult anaResult{m_strPluginName,ResultStatus::Success,""};

        for(const auto& columnData: ds.getValues() )
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