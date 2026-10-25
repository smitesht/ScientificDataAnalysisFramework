#pragma once
#include <string>

namespace SciFlow::Data
{
    class DataSet;
    class IDataLoader;
}

namespace SciFlow::AnalysisResults
{
    class AnalysisResult;
}

namespace SciFlow::Interfaces
{
    
    struct IAnalysisPlugin
    {
        virtual ~IAnalysisPlugin() = default;

        virtual std::string name() = 0;

        virtual SciFlow::AnalysisResults::AnalysisResult execute(SciFlow::Data::IDataLoader& dataset) = 0;
    };
}