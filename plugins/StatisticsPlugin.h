#pragma once
#include <iostream>
#include <memory>
#include "NumberFileReader.h"
#include "DataSet.h"
#include "IAnalysisPlugin.h"
#include "../framework/Core/AnalysisResult.h"
#include "StatisticsCalculator.h"

namespace SciFlow::Plugins
{
    using IAnalysisPlugin = SciFlow::Interfaces::IAnalysisPlugin;

    extern "C" std::shared_ptr<IAnalysisPlugin> createPlugin();
        
    class StatisticsPlugin : public IAnalysisPlugin
    {
        public:
            StatisticsPlugin() = default;
            ~StatisticsPlugin(){
                std::cout<<"StatisticsPlugin dtor...\n";
            }

            SciFlow::AnalysisResults::AnalysisResult execute(SciFlow::Data::IDataLoader& dataset) override;

            std::string name() override { return m_strPluginName; }

        private:
            const std::string m_strPluginName = "StatisticsPlugin";
            SciFlow::Math::StatisticsCalculator m_statCalculator;
    };
}