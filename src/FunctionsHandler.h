#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#pragma once

#include <string>
#include <vector>
#include <memory>

class FUNCTIONS_HANDLER
{
protected:
    size_t ModifyVectorSize;
    std::vector<std::vector<std::shared_ptr<PRODUCT_HANDLER>>> ShelvesMatrix;

public:
    FUNCTIONS_HANDLER(size_t size) : ModifyVectorSize(size)
    {
        ShelvesMatrix.resize(size);
    }

    void AddNewProduct(std::shared_ptr<PRODUCT_HANDLER> product)
    {
        for (auto &shelf : ShelvesMatrix)
        {
            for (auto &item : shelf)
            {
                if (item->getId() == product->getId())
                {
                    return;
                }
            }
        }

        for (auto &shelf : ShelvesMatrix)
        {
            if (shelf.size() < 5)
            {
                shelf.push_back(product);
                return;
            }
        }
    }

    void RemoveProduct(int id)
    {
        for (auto &shelf : ShelvesMatrix)
        {
            for (auto it = shelf.begin(); it != shelf.end(); ++it)
            {
                if ((*it)->getId() == id)
                {
                    shelf.erase(it);
                    return;
                }
            }
        }
    }

    float GetTotalPrice() const
    {
        float total = 0;
        for (const auto &shelf : ShelvesMatrix)
        {
            for (const auto &item : shelf)
            {
                total += item->getPrice();
            }
        }
        return total;
    }

    float GetTotalPriceByBrand(const std::string &brand) const
    {
        float total = 0;
        for (const auto &shelf : ShelvesMatrix)
        {
            for (const auto &item : shelf)
            {
                if (item->getBrand() == brand)
                {
                    total += item->getPrice();
                }
            }
        }
        return total;
    }

    float GetTotalPriceByShelf(int shelfIndex) const
    {
        float total = 0;
        for (const auto &item : ShelvesMatrix[shelfIndex])
        {
            total += item->getPrice();
        }
        return total;
    }

    void DisplayInfo() const
    {
        for (const auto &shelf : ShelvesMatrix)
        {
            for (const auto &item : shelf)
            {
                item->displayInfo();
            }
        }
    }
};

#endif // MAINFUNCTIONS_H