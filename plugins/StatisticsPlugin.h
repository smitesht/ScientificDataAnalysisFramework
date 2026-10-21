#pragma once
#include <iostream>
#include "NumberFileReader.h"
#include "DataSet.h"
#include "../framework/Interfaces/IAnalysisPlugin.h"
#include "../framework/Core/AnalysisResult.h"
#include "StatisticsCalculator.h"


namespace SciFlow::Plugins
{
    using IAnalysisPlugin = SciFlow::Interfaces::IAnalysisPlugin;
    class StatisticsPlugin : public IAnalysisPlugin
    {
        public:
            StatisticsPlugin() = default;
            ~StatisticsPlugin(){
                std::cout<<"StatisticsPlugin dtor...\n";
            }

            SciFlow::AnalysisResults::AnalysisResult execute(SciFlow::Data::IDataLoader& dataset) override;
        private:
            const std::string m_strPluginName = "StatisticsPlugin";
            SciFlow::Math::StatisticsCalculator m_statCalculator;
    };
}