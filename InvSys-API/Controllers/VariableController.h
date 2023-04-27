#ifndef VARIABLECONTROLLER_H
#define VARIABLECONTROLLER_H

#pragma once

#include <random>
#include <stdexcept>

class VARIABLE_CONTROLLER : private MATRIX_HANDLER
{
protected:
    /*
     * [0] = "isSugar"
     * [1] = "CREATE_DISCOUNT"
     * [2] = "isWater"
     */
    bool DRINK_TYPE[3] = {0, 0, 0};
    // "isWaterFrom"
    std::string WATER_TYPE;
    // "getSugar" default = (1, 20)
    const int RANDOM_GEN(const int _x, const int _y)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(_x, _y);
        return dist(gen);
    }

    const bool CREATE_DISCOUNT(const double &percent, const int &index)
    {
        if (DRINK_TYPE[1] == true && index >= 0 && index < MATRIX_HANDLER::op_get.MainPrice.size())
        {
            double original_price = MATRIX_HANDLER::op_get.MainPrice[index];
            double discounted_price = original_price * (1 - percent / 100);
            MATRIX_HANDLER::op_get.MainPrice[index] = discounted_price;
            return true;
        }
        throw std::logic_error("Wrong parameters, the function couldn't be started.");
    }

public:
    bool isSugar()
    {
        return DRINK_TYPE[0];
    }

    int getDiscount(const int &index, const double &percent = 10)
    {
        return CREATE_DISCOUNT(percent, index);
    }

    int getSugar(const int _x, const int _y)
    {
        return RANDOM_GEN(_x, _y);
    }

    bool isWater()
    {
        return DRINK_TYPE[2];
    }

    std::string isWaterFrom()
    {
        return WATER_TYPE;
    }
};

#endif // VARIABLECONTROLLER_H