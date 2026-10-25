#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>
#include <dlfcn.h>
#include "../Interfaces/IAnalysisPlugin.h"
#include "SharedLibrary.h"

namespace SciFlow::Plugins
{

    using IAnalysisPlugin = SciFlow::Interfaces::IAnalysisPlugin;
    using CreatePluginFunc = std::shared_ptr<IAnalysisPlugin>(*)();

    struct PluginInfo
    {
        std::shared_ptr<SharedLibrary> library;
        CreatePluginFunc createFunction;
    };
    
    class PluginManager
    {
        public:

            void loadPlugin(const std::string& path);

            std::vector<std::string> availablePlugins();
            
            std::shared_ptr<IAnalysisPlugin> getPlugin(const std::string& strPluginName);

        private:
            std::unordered_map<std::string, PluginInfo> m_registeredPluginList;
            
    };
}