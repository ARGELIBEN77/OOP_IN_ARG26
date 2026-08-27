#include "Product.hpp"

#include <cassert>
#include <iomanip>
#include <ostream>
#include <utility>

Product::Product(std::string productCode,
                 std::string productName,
                 std::string productCategory,
                 double productPrice)
    : code(std::move(productCode)),
      name(std::move(productName)),
      category(std::move(productCategory)),
      price(productPrice)
{
    // Exception handling belongs to a later unit, so constructor requirements
    // are expressed as preconditions in this introductory project.
    assert(!code.empty());
    assert(!name.empty());
    assert(!category.empty());
    assert(price >= 0.0);
}

const std::string& Product::getCode() const
{
    return code;
}

const std::string& Product::getName() const
{
    return name;
}

const std::string& Product::getCategory() const
{
    return category;
}

double Product::getPrice() const
{
    return price;
}

bool Product::changePrice(double newPrice)
{
    if (newPrice < 0.0)
        return false;

    price = newPrice;
    return true;
}

void Product::display(std::ostream& output) const
{
    output << code << " | " << name
           << " | " << category
           << " | $" << std::fixed << std::setprecision(2) << price;
}
