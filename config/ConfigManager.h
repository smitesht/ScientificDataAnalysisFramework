#pragma once
#include "Configuration.h"

namespace SciFlow::Configuration
{
    class ConfigureManager
    {
        private:
            Configuration m_config;
            void loadConfig();

        public:
            ConfigureManager();
            Configuration& getConfig();
            void saveConfig(const Configuration& config);
    };
}