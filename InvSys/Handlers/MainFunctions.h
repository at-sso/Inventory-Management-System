#pragma once

#include <string>
#include <vector>
#include <memory>

class Functions
{
private:
    std::vector<std::vector<std::shared_ptr<Product>>> shelves;

public:
    Functions(int n_shelves)
    {
        shelves.resize(n_shelves);
    }

    void addProduct(std::shared_ptr<Product> product)
    {
        for (auto &shelf : shelves)
        {
            for (auto &item : shelf)
            {
                if (item->getId() == product->getId())
                {
                    return;
                }
            }
        }

        for (auto &shelf : shelves)
        {
            if (shelf.size() < 5)
            {
                shelf.push_back(product);
                return;
            }
        }
    }

    void removeProduct(int id)
    {
        for (auto &shelf : shelves)
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

    float getTotalPrice() const
    {
        float total = 0;
        for (const auto &shelf : shelves)
        {
            for (const auto &item : shelf)
            {
                total += item->getPrice();
            }
        }
        return total;
    }

    float getTotalPriceByBrand(const std::string &brand) const
    {
        float total = 0;
        for (const auto &shelf : shelves)
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

    float getTotalPriceByShelf(int shelfIndex) const
    {
        float total = 0;
        for (const auto &item : shelves[shelfIndex])
        {
            total += item->getPrice();
        }
        return total;
    }

    void displayInfo() const
    {
        for (const auto &shelf : shelves)
        {
            for (const auto &item : shelf)
            {
                item->displayInfo();
            }
        }
    }
};
