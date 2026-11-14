#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include "PluginManager.h"
#include "StatisticsPlugin.h"
#include "Configuration.h"
#include "ConfigManager.h"
#include "FileReaderFactory.h"
#include "JsonFileReader.h"

int main()
{
    
    SciFlow::Configuration::ConfigureManager configManager;
    SciFlow::Configuration::Configuration conf = configManager.getConfig();

    SciFlow::Plugins::PluginManager pm(conf.pluginDirectory);
    SciFlow::Data::FileReaderFactory ft;

    //conf.logging.level = "DEBUG";
    //configManager.saveConfig(cong);

    for(const auto& pluginCfg: conf.plugins)
    {
        if(!pluginCfg.enabled)
        {
            std::cerr << pluginCfg.name << " plugin is not enable" << "\n";
            continue;
        }
            
        auto plugin = pm.getPlugin(pluginCfg.name);

        if(!plugin)
        {
            std::cerr << pluginCfg.name << " plugin is not found" << "\n";
            continue;
        }

        for(const auto& ds: pluginCfg.inputDatasets )
        {
            const auto fileReader = ft.getFileReader(ds.path,ds.type);

            if(!fileReader)
            {
                std::cerr << ds.type << " file Ext is not supported" << "\n";
                continue;
            }
            
            SciFlow::AnalysisResults::AnalysisResult anaResult = plugin->execute(fileReader);
            
            if(anaResult.isSuccess())
            {
                for(auto kv: anaResult.getColumnMetrics())
                {
                    auto[key, val] = kv;
                    std::cout<<key<<"\n";

                    for(auto col: val)
                    {
                        auto [colName, data] = col;
                        std::cout << colName<<"\t"<<data<<"\n";
                    }
                    std::cout <<"-----------------\n";
                }
            }
        }
    }
           
        
    return 0;
}