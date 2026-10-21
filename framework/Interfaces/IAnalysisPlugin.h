#pragma once

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

        virtual SciFlow::AnalysisResults::AnalysisResult execute(SciFlow::Data::IDataLoader& dataset) = 0;
    };
}