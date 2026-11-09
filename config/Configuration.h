#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "ConfigConstant.h"

using json = nlohmann::ordered_json;

namespace SciFlow::Configuration
{
    struct DatasetConfig
    {
        std::string type;
        std::string path;
    };

    inline void to_json(json& j, const DatasetConfig& d)
    {
        j = json{ { Constant::DatasetConfig::type, d.type}, { Constant::DatasetConfig::path,d.path }};
    }

    inline void from_json(const json& j, DatasetConfig& d)
    {
        j.at(Constant::DatasetConfig::type).get_to(d.type);
        j.at(Constant::DatasetConfig::path).get_to(d.path);
    }

    struct PluginConfig
    {
        std::string name;
        bool enabled;
        std::string version;
        std::vector<DatasetConfig> inputDatasets;
    };

    inline void to_json(json& j, const PluginConfig& pl)
    {
        j = json{ 
                    { Constant::PluginConfig::name, pl.name }, 
                    { Constant::PluginConfig::enabled,pl.enabled },
                    { Constant::PluginConfig::version,pl.version },
                    { Constant::PluginConfig::inputDatasets,pl.inputDatasets }                
                };
    }

    inline void from_json(const json& j, PluginConfig& pl)
    {
        j.at(Constant::PluginConfig::name).get_to(pl.name);
        j.at(Constant::PluginConfig::enabled).get_to(pl.enabled);
        j.at(Constant::PluginConfig::version).get_to(pl.version);
        j.at(Constant::PluginConfig::inputDatasets).get_to(pl.inputDatasets);
    }

    struct OutputConfig
    {
        std::string directory;
        std::string format;
    };

    inline void to_json(json& j, const OutputConfig& out)
    {
        j = json{ 
                    { Constant::OutputConfig::directory, out.directory }, 
                    { Constant::OutputConfig::format,out.format }               
                };
    }

    inline void from_json(const json& j, OutputConfig& out)
    {
        j.at(Constant::OutputConfig::directory).get_to(out.directory);
        j.at(Constant::OutputConfig::format).get_to(out.format);
    }

    struct LoggingConfig
    {
        std::string level;
    };

    inline void to_json(json& j, const LoggingConfig& log)
    {
        j = json{ 
                    { Constant::LoggingConfig::level, log.level }       
                };
    }

    inline void from_json(const json& j, LoggingConfig& log)
    {
        j.at(Constant::LoggingConfig::level).get_to(log.level);
    }

    struct Configuration
    {
        std::string pluginDirectory;
        std::vector<PluginConfig> plugins;
        OutputConfig output;
        LoggingConfig logging;
    };

    inline void to_json(json& j, const Configuration& cfg)
    {
        j = json{ 
                    { Constant::Configuration::pluginDirectory, cfg.pluginDirectory},
                    { Constant::Configuration::plugins, cfg.plugins}, 
                    { Constant::Configuration::output, cfg.output}, 
                    { Constant::Configuration::logging, cfg.logging},    
                };
    }

    inline void from_json(const json& j, Configuration& cfg)
    {
        j.at(Constant::Configuration::pluginDirectory).get_to(cfg.pluginDirectory);
        j.at(Constant::Configuration::plugins).get_to(cfg.plugins);
        j.at(Constant::Configuration::output).get_to(cfg.output);
        j.at(Constant::Configuration::logging).get_to(cfg.logging);
    }
    
}
