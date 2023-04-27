#ifndef MATRIXHANDLER_H
#define MATRIXHANDLER_H

#pragma once

#include <string>
#include <vector>
#include <map>

class MATRIX_HANDLER
{
protected:
    // It is recommended to not modify the values within this class.
    class GET_MATRIX
    {
    public:
        // Get all main drinks.
        std::vector<std::string> MAIN;
        // Get main drink's price by index
        std::vector<double> PRICE;
        // Get main drink's brand by index
        std::map<std::string, int> BRAND;
        // Get main drink's shelves position.
        std::map<std::string, int> SHELVES;
    };
    GET_MATRIX get;

public:
    // From all return the drink's price.
    const double &FROM_MAIN_GET_PRICE(const double &price)
    {
        get.PRICE.emplace_back(price);
        return get.PRICE.back();
    }

    // From all return the drink's brand.
    const std::string &FROM_MAIN_GET_BRAND(const std::string &_string, const int &brandIndex)
    {
        get.BRAND[_string] = brandIndex;
        return _string;
    }

    // Fixes the shelves position.
    const std::map<std::string, int> &GET_MAIN_AND_FIX_SHELVES(const std::map<std::string, int> &_map)
    {
        get.SHELVES = _map;
        return get.SHELVES;
    }
};

#endif // MATRIXHANDLER_H