#include "ConfigConstant.h"

namespace SciFlow::Configuration::Constant
{
    const std::string DatasetConfig::type = "type";
    const std::string DatasetConfig::path = "path";

    const std::string PluginConfig::name = "name";
    const std::string PluginConfig::enabled = "enabled";
    const std::string PluginConfig::version = "version";
    const std::string PluginConfig::inputDatasets = "inputDatasets";
    
    const std::string OutputConfig::directory = "directory";
    const std::string OutputConfig::format = "format";

    const std::string LoggingConfig::level = "level";

    const std::string Configuration::pluginDirectory = "pluginDirectory";
    const std::string Configuration::plugins = "plugins";
    const std::string Configuration::output = "output";
    const std::string Configuration::logging = "logging";
}