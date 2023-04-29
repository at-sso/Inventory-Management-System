#pragma once

#include "InvSys/Handlers/DrinksHandler.h"
#include "InvSys/Handlers/FunctionsHandler.h"
FUNCTIONS_HANDLER HandleFuncs(5);

#include <memory>
#include <string>

class INVENTORY_SYSTEM : public FUNCTIONS_HANDLER
{
public:
    INVENTORY_SYSTEM(size_t size) : FUNCTIONS_HANDLER(size) {}

    std::shared_ptr<WATER_HANDLER> CreateWater(const int &ID, const float &LITERS,
                                               const float &PRICE, const std::string &BRAND, const bool &SPRING = false, const std::string &ORIGIN = "")
    {
        if (SPRING == false && ORIGIN.empty())
        {
            return std::make_shared<WATER_HANDLER>(ID, LITERS, PRICE, BRAND);
        }
        return std::make_shared<WATER_HANDLER>(ID, LITERS, PRICE, BRAND, SPRING, ORIGIN);
    }

    std::shared_ptr<SUGAR_HANDLER> CreateSugar(const int &ID, const float &LITERS,
                                               const float &PRICE, std::string BRAND, float SUGAR, bool PROMO)
    {
        return std::make_shared<SUGAR_HANDLER>(ID, LITERS, PRICE, BRAND, SUGAR, PROMO);
    }
};

INVENTORY_SYSTEM InvSys(5);
