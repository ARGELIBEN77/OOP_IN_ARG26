#include "Product.hpp"

#include "InsufficientStockError.hpp"

#include <stdexcept>
#include <utility>

Product::Product(std::string productCode,
                 std::string productName,
                 double productPrice,
                 int initialStock)
    : code(std::move(productCode)),
      name(std::move(productName)),
      price(productPrice),
      stock(initialStock)
{
    // Constructors throw when they cannot create a valid object.
    if (code.empty())
        throw std::invalid_argument("Product code must not be empty");

    if (name.empty())
        throw std::invalid_argument("Product name must not be empty");

    if (price < 0.0)
        throw std::invalid_argument("Product price must not be negative");

    if (stock < 0)
        throw std::invalid_argument("Initial stock must not be negative");
}

const std::string& Product::getCode() const
{
    return code;
}

const std::string& Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}

int Product::getStock() const
{
    return stock;
}

double Product::purchase(int quantity)
{
    if (quantity <= 0)
        throw std::invalid_argument("Purchase quantity must be positive");

    if (quantity > stock)
        throw InsufficientStockError(code, quantity, stock);

    // State changes only after every validation succeeds. Failed purchases
    // therefore leave the Product unchanged.
    stock -= quantity;
    return price * quantity;
}
