#include "PluginManager.h"
#include <iostream>
#include <memory>


namespace SciFlow::Plugins
{
    
    void PluginManager::loadPlugin(const std::string& path)
    {
        auto library = std::make_shared<SharedLibrary>(path);
        auto createFunction = library->getSymbol<CreatePluginFunc>("createPlugin");

        auto plugin = createFunction();
        auto pluginName = plugin->name();

        m_registeredPluginList[pluginName] = {
            library,
            createFunction
        };

    }
    
    std::vector<std::string> PluginManager::availablePlugins()
    {
        std::vector<std::string> ret;
        for(const auto& plugin: m_registeredPluginList)
        {
            const auto[pluginName, pPlugin] = plugin;
            ret.push_back(pluginName);
        }

        return ret;
    }
            
    std::shared_ptr<IAnalysisPlugin> PluginManager::getPlugin(const std::string& strPluginName)
    {
        auto plugin = m_registeredPluginList.find(strPluginName);
        if( plugin != m_registeredPluginList.end())
            return plugin->second.createFunction();

        return nullptr;
    }
}