#include "InventorySystem.h"
#include <iostream>

Functions func(3);

int main(int argc, char const *argv[])
{
    auto water = std::make_shared<IsWater>(1, 1.5, 1.0, "Evian", "French Alps");
    auto coke = std::make_shared<SugarDrink>(2, 2, 1.5, "Coca-Cola", 10, true);
    auto fanta = std::make_shared<SugarDrink>(3, 1.5, 1.2, "Fanta", 9, false);

    func.addProduct(water);
    func.addProduct(coke);
    func.addProduct(fanta);

    func.displayInfo();

    std::cout << "Total price: " << func.getTotalPrice() << std::endl;
    std::cout << "Total price of Coca-Cola: " << func.getTotalPriceByBrand("Coca-Cola") << std::endl;
    std::cout << "Total price of shelf 0: " << func.getTotalPriceByShelf(0) << std::endl;

    func.removeProduct(2);
    func.displayInfo();

    return 0;
}