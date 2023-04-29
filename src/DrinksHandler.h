#ifndef MAINMATRIX_H
#define MAINMATRIX_H

#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <memory>

class PRODUCT_HANDLER
{
protected:
    int id;
    float liters;
    float price;
    std::string brand;

public:
    explicit PRODUCT_HANDLER(int id, float liters, float price, std::string brand)
        : id(id), liters(liters), price(price), brand(brand) {}

    virtual float getPrice() const = 0;
    virtual void displayInfo() const = 0;

    int getId() const
    {
        return id;
    }

    const std::string &getBrand() const
    {
        return brand;
    }
};

class WATER_HANDLER : public PRODUCT_HANDLER
{
protected:
    std::string origin;
    bool isSpring;

public:
    explicit WATER_HANDLER(int id, float liters, float price,
                           std::string brand, bool isSpring = false, std::string origin = "")
        : PRODUCT_HANDLER(id, liters, price, brand),
          isSpring(isSpring), origin(origin) {}

    float getPrice() const override
    {
        return price;
    }

    void displayInfo() const override
    {
        switch (isSpring)
        {
        case false:
            std::cout << "ID: " << id << " Liters: " << liters << " Price: " << price
                      << " Brand: " << brand << std::endl;
        case true:
            std::cout << "ID: " << id << " Liters: " << liters << " Price: " << price
                      << " Brand: " << brand << " Origin: " << origin << std::endl;
        }
    }
};

class SUGAR_HANDLER : public PRODUCT_HANDLER
{
protected:
    float sugarPercentage;
    bool promotion;

public:
    explicit SUGAR_HANDLER(int id, float liters, float price, std::string brand, float sugarPercentage, bool promotion)
        : PRODUCT_HANDLER(id, liters, price, brand), sugarPercentage(sugarPercentage), promotion(promotion) {}

    float getPrice() const override
    {
        return promotion ? price * 0.9 : price;
    }

    void displayInfo() const override
    {
        std::cout << "ID: " << id << " Liters: " << liters << " Price: " << getPrice()
                  << " Brand: " << brand << " Sugar Percentage: " << sugarPercentage
                  << " Promotion: " << (promotion ? "Yes" : "No") << std::endl;
    }
};

#endif // MAINMATRIX_H