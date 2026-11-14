#pragma once
#include <iostream>
#include <memory>
#include <optional>
#include "NumberFileReader.h"
#include "Records.h"
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
                
            }

            SciFlow::AnalysisResults::AnalysisResult execute(std::shared_ptr<SciFlow::Data::IDataLoader> dataset) override;

            std::string name() override { return m_strPluginName; }

        private:
            const std::string m_strPluginName = "Statistics";
            SciFlow::Math::StatisticsCalculator m_statCalculator;

            void printValue(const SciFlow::Data::FieldValue& value);
            void printRecords(const SciFlow::Data::Records& records);
            std::optional<double> getNumericValue(const SciFlow::Data::FieldValue& value);
    };
}