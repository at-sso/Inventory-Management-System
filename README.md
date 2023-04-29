<!-- @format -->

# Inventory System

A simple inventory management system to store and manage beverages, such as mineral water and sugar-based drinks (Coca-Cola, Fanta, etc.). The system allows the user to perform various operations, including adding products, removing products, calculating the total price, and displaying information.

## Features

- Manage beverages in an organized matrix (shelves)
- Store information about each beverage, such as ID, liters, price, and brand
- Track the origin of mineral water
- Store the sugar percentage and promotions for sugar-based drinks
- Perform operations like adding/removing products, calculating total prices, and displaying information

## Classes

The inventory system consists of the following classes:

1. `PRODUCT_HANDLER`: The base class for handling products. Stores common attributes like ID, liters, price, and brand.
2. `WATER_HANDLER`: Inherits from `PRODUCT_HANDLER`. Manages mineral water products with additional attributes like origin and whether it's spring water or not.
3. `SUGAR_HANDLER`: Inherits from `PRODUCT_HANDLER`. Manages sugar-based drinks with additional attributes like sugar percentage and whether there's a promotion or not.
4. `FUNCTIONS_HANDLER`: Handles various operations like adding/removing products, calculating total prices, and displaying information.
5. `INVENTORY_SYSTEM`: Inherits from `FUNCTIONS_HANDLER`. The main class for managing the inventory system, creating water and sugar-based drink products.

## Usage

To use the inventory system, first, create an instance of the `INVENTORY_SYSTEM` class, specifying the number of shelves you want to manage:

```cpp
INVENTORY_SYSTEM InvSys(5); // Create an inventory system with 5 shelves
```

Next, create some products:

```cpp
auto water1 = InvSys.CreateWater(1, 1.0, 0.5, "ClearWater");
auto water2 = InvSys.CreateWater(2, 0.5, 0.7, "SpringWater", true, "Mountains");
auto soda1 = InvSys.CreateSugar(3, 1.5, 1.2, "Coca-Cola", 10.0, false);
auto soda2 = InvSys.CreateSugar(4, 2.0, 1.5, "Fanta", 12.0, true);
```

Add the products to the inventory system:

```cpp
InvSys.AddNewProduct(water1);
InvSys.AddNewProduct(water2);
InvSys.AddNewProduct(soda1);
InvSys.AddNewProduct(soda2);
```

Perform various operations on the inventory system:

```cpp
// Calculate the total price of all products
float totalPrice = InvSys.GetTotalPrice();

// Calculate the total price of a specific brand
float brandTotalPrice = InvSys.GetTotalPriceByBrand("Coca-Cola");

// Calculate the total price of a specific shelf
float shelfTotalPrice = InvSys.GetTotalPriceByShelf(0);

// Remove a product by ID
InvSys.RemoveProduct(1);

// Display the information for all products
InvSys.DisplayInfo();
```

## License

MIT License

Feel free to use, modify, and distribute this code as you see fit.
