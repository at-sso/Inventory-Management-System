#ifndef MATRIXCONTROLLER_H
#define MATRIXCONTROLLER_H

#pragma once

#include <string>
#include <iomanip>
#include <sstream>

class MATRIX_CONTROLLER : private VARIABLE_CONTROLLER
{
public:
    const std::string &FIX_ALL_STRINGS(const std::string &brand, const std::string &name, const double &price)
    {
        std::stringstream sstream;
        sstream << std::fixed << std::setprecision(2) << price;
        std::string formatted_price = sstream.str();
        std::string fixed_string = brand + ", " + name + ". $" + formatted_price;
        FromMatrix.op_get.Main.emplace_back(fixed_string);
        return FromMatrix.op_get.Main.back();
    }
};

#endif // MATRIXCONTROLLER_H