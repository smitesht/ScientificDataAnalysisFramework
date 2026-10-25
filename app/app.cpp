#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <dlfcn.h>
#include "DataSet.h"
#include "PluginManager.h"
#include "StatisticsPlugin.h"


int main()
{
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
    


    /*void* handle = dlopen("./plugins/libStatisticsPluginLib.so",RTLD_LAZY);
   
    if(!handle)
    {
        std::cerr << "dlopen failed: " << dlerror() << "\n";
        return 0;
    }

    dlerror();
    
    

    auto createPlugin = reinterpret_cast<CreatePluginFunc>(dlsym(handle, "createPlugin"));
    const char* error = dlerror();

    if(error)
    {
        std::cerr << "dlsym failed: "<<errno<< "\n";
        return 0;
    }

    auto sp = createPlugin("Statistics");

    //SciFlow::Plugins::StatisticsPlugin sp;
    //SciFlow::Plugins::PluginManager mp;
    
    //mp.registerPlugin()
    SciFlow::AnalysisResults::AnalysisResult anaResult = sp->execute(fileTxt);
    
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
    }*/
    
    
    return 0;
}