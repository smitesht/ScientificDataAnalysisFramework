#include "CsvFileReader.h"
#include "FileException.h"

namespace SciFlow::Data
{
    CsvFileReader::~CsvFileReader()
    {

    }

    std::vector<std::string> CsvFileReader::getColumnHeaders(std::string line)
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

    FieldValue CsvFileReader::parseCell(const std::string& cell)
    {
        // Trim leading and trailing whitespace
        std::string value = cell;

        auto first = value.find_first_not_of(" \t\r\n");
        if (first == std::string::npos)
            return nullptr;

        auto last = value.find_last_not_of(" \t\r\n");
        value = value.substr(first, last - first + 1);

        // Boolean
        if (value == "true" || value == "TRUE")
            return true;

        if (value == "false" || value == "FALSE")
            return false;

        // Integer
        int64_t integerValue{};

        auto [intEnd, intError] = std::from_chars(
            value.data(),
            value.data() + value.size(),
            integerValue
        );

        if (intError == std::errc{} &&
            intEnd == value.data() + value.size())
        {
            return integerValue;
        }

        // Double
        double doubleValue{};

        auto [doubleEnd, doubleError] = std::from_chars(
            value.data(),
            value.data() + value.size(),
            doubleValue
        );

        if (doubleError == std::errc{} &&
            doubleEnd == value.data() + value.size())
        {
            return doubleValue;
        }

        // Everything else remains a string
        return value;
    }

    Records CsvFileReader::read_line()
    {
        Records records;
        //DataSet dataset;
        std::ifstream file(filePath);

        if(!file.is_open()){
            //std::cerr << "Error: Could not open file " << filePath <<"\n";
            throw SciFlow::Exception::FileException("SciFlow::Exception::FileException - File not found " + filePath);
            //return records;
        }

        // read file line by line
        std::string line;
        std::getline(file, line);
        
        std::vector<std::string> csvColumnHeaders = getColumnHeaders(line);
                        
        while(std::getline(file,line))
        {
            Record record;

            std::stringstream ss(line);
            std::string cell;
            int counter = 0;
            while (std::getline(ss, cell, ',')) {

                if(!cell.empty())
                {
                    if(cell[0] == '\"' && cell[cell.length()-1] == '\"')
                        cell = cell.substr(1,cell.length()-2);                   
                }

                FieldValue value = parseCell(cell);
                record.emplace(csvColumnHeaders[counter], value);
                ++counter;
            }

            records.push_back(std::move(record));
        }

        file.close();
        
        return records;
    }

    Records CsvFileReader::load()
    {
        return read_line();
    }
}