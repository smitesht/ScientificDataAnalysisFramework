#pragma once
#include <string>

namespace SciFlow::Configuration::Constant
{
    struct DatasetConfig
    {
        const static std::string type;
        const static std::string path;
    };

    struct PluginConfig
    {
        const static std::string name;
        const static std::string enabled;
        const static std::string version;
        const static std::string inputDatasets;
    };

    struct OutputConfig
    {
        const static std::string directory;
        const static std::string format;
    };

    struct LoggingConfig
    {
        const static std::string level;
    };

    struct Configuration
    {
        const static std::string pluginDirectory;
        const static std::string plugins;
        const static std::string output;
        const static std::string logging;
    };
}