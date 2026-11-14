#pragma once

#include <variant>
#include <cstdint>
#include <vector>
#include <string>
#include <unordered_map>

namespace SciFlow::Data
{

    using FieldValue = std::variant<
        std::nullptr_t,
        bool,
        int64_t,
        double,
        std::string
    >;

    using Record = std::unordered_map<std::string, FieldValue>;
    using Records = std::vector<Record>;
    using Column = std::vector<FieldValue>;

    using DataSet = std::unordered_map<std::string, std::vector<double>>;

}