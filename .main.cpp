#include <iostream>
#include "InventorySystem.h"

int main()
{
    // Create some products
    auto water1 = InvSys.CreateWater(1, 1.0, 0.5, "ClearWater");
    auto water2 = InvSys.CreateWater(2, 0.5, 0.7, "SpringWater", true, "Mountains");
    auto soda1 = InvSys.CreateSugar(3, 1.5, 1.2, "Coca-Cola", 10.0, false);
    auto soda2 = InvSys.CreateSugar(4, 2.0, 1.5, "Fanta", 12.0, true);

    // Add products to the inventory system
    InvSys.AddNewProduct(water1);
    InvSys.AddNewProduct(water2);
    InvSys.AddNewProduct(soda1);
    InvSys.AddNewProduct(soda2);

    // Display information about all products
    std::cout << "Products in the inventory system:" << std::endl;
    InvSys.DisplayInfo();

    // Calculate and display total price of all products
    std::cout << "Total price of all products: " << InvSys.GetTotalPrice() << std::endl;

    // Calculate and display total price of a specific brand
    std::string brand = "Coca-Cola";
    std::cout << "Total price of " << brand << " products: " << InvSys.GetTotalPriceByBrand(brand) << std::endl;

    // Calculate and display total price of a specific shelf
    int shelfIndex = 0;
    std::cout << "Total price of shelf " << shelfIndex << ": " << InvSys.GetTotalPriceByShelf(shelfIndex) << std::endl;

    // Remove a product from the inventory system
    int idToRemove = 3;
    InvSys.RemoveProduct(idToRemove);
    std::cout << "Removed product with ID " << idToRemove << std::endl;

    // Display information about all products after removing one
    std::cout << "Products in the inventory system after removing product with ID " << idToRemove << ":" << std::endl;
    InvSys.DisplayInfo();

    return 0;
}
