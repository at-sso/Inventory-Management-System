<!-- @format -->

# Beverage Warehouse Management System

A simple C++ application to manage a beverage warehouse, storing and managing products such as mineral water and sugary drinks.

## Classes

- `Beverage`: Abstract base class for beverages.
- `MineralWater`: Derived class representing mineral water.
- `SugaryDrink`: Derived class representing sugary drinks.
- `Warehouse`: Class to manage the storage and operations of beverages.

## Features

- Add and remove products.
- Calculate total price of all beverages.
- Calculate total price of a specific brand.
- Calculate total price of beverages on a specific shelf.
- Display information for all beverages.

## Usage

1. Compile the program:

```sh
g++ main.cpp -o warehouse
```

2. Run the program:

```sh
./warehouse
```

3. The output will display the warehouse information, total prices, and updated warehouse information after removing a product.

## License

MIT License

Feel free to use, modify, and distribute this code as you see fit.
