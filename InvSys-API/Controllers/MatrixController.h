#ifndef MATRIXCONTROLLER_H
#define MATRIXCONTROLLER_H

#pragma once

#include <random>
#include <string>
#include <iomanip>
#include <sstream>

class MATRIX_CONTROLLER : private MATRIX_HANDLER
{
protected:
    class MAIN_VARIABLE_CONTROLLER
    {
    public:
        bool SUGAR_DRINK;
        bool DISCOUNT_SUGAR_DRINK;
        bool WATER_DRINK;
        const int RANDOM_GEN(const int _x, const int _y)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(_x, _y);
            return dist(gen);
        }
    };
    MAIN_VARIABLE_CONTROLLER var_ctrl;

#define isSugar var_ctrl.SUGAR_DRINK
#define isWater var_ctrl.WATER_DRINK
#define hasDiscount var_ctrl.DISCOUNT_SUGAR_DRINK
#define getSugar var_ctrl.RANDOM_GEN(1, 20)

public:
    // Fix the string in the ALL vector
    void FIX_ALL_STRINGS(const std::string &brand, const std::string &name, const double &price)
    {
        std::stringstream sstream;
        sstream << std::fixed << std::setprecision(2) << price;
        std::string formatted_price = sstream.str();
        std::string fixed_string = brand + ", " + name + ". $" + formatted_price;
        return MATRIX_HANDLER::get.MAIN.push_back(fixed_string);
    }
};

#endif // MATRIXCONTROLLER_H