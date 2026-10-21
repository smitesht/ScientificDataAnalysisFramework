#pragma once
#include <string>
#include <vector>
#include <unordered_map>

using ColumnMatricValue = std::unordered_map<std::string, double>; 

namespace SciFlow::AnalysisResults
{
    enum class ResultStatus
    {
        Success,
        Failure
    };

    class AnalysisResult
    {
        protected:
            std::string m_algorithmName;
            std::unordered_map<std::string, ColumnMatricValue> m_columnMetrics;
            std::unordered_map<std::string, double> m_datasetMetrics;
            ResultStatus m_resultStatus {ResultStatus::Success};
            std::string m_errorMessage;

        public:
            explicit AnalysisResult(std::string algorithmName, 
                ResultStatus resultStatus, std::string errorMessage)
                : m_algorithmName(algorithmName),m_resultStatus(resultStatus),
                  m_errorMessage(errorMessage)
                { }
            void addColumnMetric(const std::string& metricName, const std::string& columnName, const double& value)
            {
                m_columnMetrics[columnName].insert({metricName, value});
            }

            void addDatasetMetric(const std::string& metricName, const double& value)
            {
                m_datasetMetrics.insert({metricName, value});
            }

            std::unordered_map<std::string, ColumnMatricValue> getColumnMetrics() const
            {
                return m_columnMetrics;
            }

            std::unordered_map<std::string, double> getDatasetMetrics() const
            {
                return m_datasetMetrics;
            }

            bool isSuccess() const
            {
                return m_resultStatus == ResultStatus::Success;
            }
    };
}