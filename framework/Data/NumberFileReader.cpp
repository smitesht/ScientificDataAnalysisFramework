#include "NumberFileReader.h"


namespace SciFlow::Data
{
    std::vector<std::string> NumberFileReader::getColumnHeaders(std::string line)
    {
        std::vector<std::string> columnHeaders;
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            cell = getCellValue(cell);
            columnHeaders.push_back(cell);
        }    
        
        return columnHeaders;
    }

    std::vector<double> NumberFileReader::getRowValues(std::string line)
    {
        std::vector<double> cells;
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            cell = getCellValue(cell);
            cells.push_back(std::stod(cell));
        }    
        
        return cells;
    }

    DataSet NumberFileReader::read_line()
    {
        DataSet dataset;
        std::ifstream file(filePath);

        if(!file.is_open()){
            std::cerr << "Error: Could not open file " << filePath <<"\n";
            return dataset;
        }

        // read file line by line
        std::string line;
        std::getline(file, line);
        
        std::vector<std::string> csvColumnHeaders = getColumnHeaders(line);
        
        std::vector<std::vector<double>> csvColumnValues;
        while(std::getline(file, line))
        {
            std::vector<double> rowData = getRowValues(line);
            csvColumnValues.push_back(rowData);
        }
        
        for(size_t idx=0; idx < csvColumnHeaders.size(); idx++)
        {
            std::vector<double> colVal;
            for(size_t jdx=0; jdx < csvColumnValues.size(); jdx++)
            {
                colVal.push_back(csvColumnValues[jdx][idx]);
            }

            dataset.addColumn(csvColumnHeaders[idx],colVal);
        }

        file.close();

        return dataset;
    }

    DataSet NumberFileReader::load()
    {
        return read_line();
    }
}