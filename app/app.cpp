#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "DataSet.h"
#include "StatisticsPlugin.h"

std::vector<std::string> getColumnHeaders(std::string line)
{
    std::vector<std::string> columnHeaders;
    std::stringstream ss(line);
    std::string cell;
    while (std::getline(ss, cell, ',')) {
        if(!cell.empty())
        {
            if(cell[0] == '\"' && cell[cell.length()-1] == '\"')
                cell = cell.substr(1,cell.length()-2);

            columnHeaders.push_back(cell);
        }    
    }

    return columnHeaders;
}

std::vector<double> getRowValues(std::string line)
{
    std::vector<double> cells;
    std::stringstream ss(line);
    std::string cell;
    while (std::getline(ss, cell, ',')) {
        if(!cell.empty())
        {
            if(cell[0] == '\"' && cell[cell.length()-1] == '\"')
                cell = cell.substr(1,cell.length()-2);

            cells.push_back(std::stod(cell));
        }    
    }

    return cells;
}

int main()
{
   
    SciFlow::Data::NumberFileReader fileTxt("../datasets/vector.txt");
    SciFlow::Plugins::StatisticsPlugin sp;
    SciFlow::AnalysisResults::AnalysisResult anaResult = sp.execute(fileTxt);
    
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
    
    
    return 0;
}