#include "ShoppingCart.hpp"

#include <iomanip>
#include <ostream>

CartItem* ShoppingCart::findItem(const std::string& productCode)
{
    for (CartItem& item : items)
    {
        if (item.getProduct().getCode() == productCode)
            return &item;
    }

    return nullptr;
}

bool ShoppingCart::addProduct(const Product& product, int quantity)
{
    if (quantity <= 0)
        return false;

    CartItem* existingItem = findItem(product.getCode());

    if (existingItem != nullptr)
        return existingItem->increaseQuantity(quantity);

    items.emplace_back(product, quantity);
    return true;
}

std::size_t ShoppingCart::getDifferentProductCount() const
{
    return items.size();
}

int ShoppingCart::getTotalQuantity() const
{
    int total = 0;

    for (const CartItem& item : items)
        total += item.getQuantity();

    return total;
}

double ShoppingCart::getTotalPrice() const
{
    double total = 0.0;

    for (const CartItem& item : items)
        total += item.getSubtotal();

    return total;
}

bool ShoppingCart::empty() const
{
    return items.empty();
}

void ShoppingCart::display(std::ostream& output) const
{
    output << "Shopping cart\n";
    output << "-------------\n";

    for (const CartItem& item : items)
    {
        output << item.getProduct().getName()
               << " x " << item.getQuantity()
               << " = $" << std::fixed << std::setprecision(2)
               << item.getSubtotal() << '\n';
    }

    output << "Total items: " << getTotalQuantity() << '\n';
    output << "Total price: $" << std::fixed << std::setprecision(2)
           << getTotalPrice() << '\n';
}
