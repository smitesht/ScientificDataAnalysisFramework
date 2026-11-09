#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <nlohmann/json.hpp>
#include "ConfigManager.h"

namespace SciFlow::Configuration
{

    void ConfigureManager::loadConfig()
    {
        std::ifstream file("../config/config.json");

        if(!file)
        {
            std::cerr << "Unable to open config.json file. " << std::endl;
        }

        json config;
        file >> config;
        config.get_to(m_config);
        //std::cout<<m_config.pluginDirectory<<"\n";
    }

    ConfigureManager::ConfigureManager()
    {
        loadConfig();
    }

    Configuration& ConfigureManager::getConfig()
    {
        return m_config;
    }

    void ConfigureManager::saveConfig(const Configuration& config)
    {
        std::ofstream file("../config/config.json");

        if(file.is_open())
        {
            json j = config;
            file << j.dump(4);
        }
    }

    
}