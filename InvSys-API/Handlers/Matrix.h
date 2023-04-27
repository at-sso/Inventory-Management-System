#ifndef MATRIX_H
#define MATRIX_H

#pragma once

#include <string>
#include <vector>
#include <map>

class MATRIX_HANDLER
{
public:
    // It is recommended to not modify the values within this class.
    class GET_OPERATOR
    {
    public:
        // Get all main drinks.
        std::vector<std::string> Main;
        // Get main drink's price by index
        std::vector<double> MainPrice;
        // Get main drink's brand by index
        std::map<std::string, int> MainBrand;
        // Get main drink's shelves position.
        std::map<std::string, int> ShelvesMatrix;
    };

    // From all return the drink's price.
    const double &FROM_MAIN_GET_PRICE(const double &price)
    {
        op_get.MainPrice.emplace_back(price);
        return op_get.MainPrice.back();
    }

    // From all return the drink's brand.
    const std::string &FROM_MAIN_GET_BRAND(const std::string &_string, const int &brandIndex)
    {
        op_get.MainBrand[_string] = brandIndex;
        return _string;
    }

    // Fixes the shelves position.
    const std::map<std::string, int> &GET_MAIN_AND_FIX_SHELVES(const std::map<std::string, int> &_map)
    {
        op_get.ShelvesMatrix = _map;
        return op_get.ShelvesMatrix;
    }

    MATRIX_HANDLER::GET_OPERATOR op_get;
};

#endif // MATRIX_H