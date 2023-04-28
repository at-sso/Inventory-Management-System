#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <memory>

class Product
{
protected:
    int id;
    float liters;
    float price;
    std::string brand;

public:
    Product(int id, float liters, float price, std::string brand)
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

class IsWater : public Product
{
protected:
    std::string origin;

public:
    IsWater(int id, float liters, float price, std::string brand, std::string origin)
        : Product(id, liters, price, brand), origin(origin) {}

    float getPrice() const override
    {
        return price;
    }

    void displayInfo() const override
    {
        std::cout << "ID: " << id << " Liters: " << liters << " Price: " << price
                  << " Brand: " << brand << " Origin: " << origin << std::endl;
    }
};

class SugarDrink : public Product
{
protected:
    float sugarPercentage;
    bool promotion;

public:
    SugarDrink(int id, float liters, float price, std::string brand, float sugarPercentage, bool promotion)
        : Product(id, liters, price, brand), sugarPercentage(sugarPercentage), promotion(promotion) {}

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