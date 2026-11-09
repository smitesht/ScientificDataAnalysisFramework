#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include "PluginManager.h"
#include "StatisticsPlugin.h"
#include "Configuration.h"
#include "ConfigManager.h"

int main()
{

    //readJson();
    SciFlow::Configuration::ConfigureManager configManager;
    SciFlow::Configuration::Configuration cong = configManager.getConfig();

    cong.logging.level = "DEBUG";
    configManager.saveConfig(cong);
    
    SciFlow::Data::NumberFileReader fileTxt("../datasets/vector.txt");
    SciFlow::Plugins::PluginManager pm;
    pm.loadPlugin("./plugins/libStatisticsPluginLib.so");

    for(auto str: pm.availablePlugins())
    {
        auto statisticPlugin = pm.getPlugin(str);
        SciFlow::AnalysisResults::AnalysisResult anaResult = statisticPlugin->execute(fileTxt);
    
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
        
    return 0;
}