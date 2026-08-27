#include "CartItem.hpp"

#include <cassert>

CartItem::CartItem(const Product& selectedProduct, int itemQuantity)
    : product(selectedProduct),
      quantity(itemQuantity)
{
    assert(quantity > 0);
}

const Product& CartItem::getProduct() const
{
    // Return a const reference to avoid copying the contained Product and to
    // prevent clients from changing it without CartItem's involvement.
    return product;
}

int CartItem::getQuantity() const
{
    return quantity;
}

double CartItem::getSubtotal() const
{
    return product.getPrice() * quantity;
}

bool CartItem::increaseQuantity(int amount)
{
    if (amount <= 0)
        return false;

    quantity += amount;
    return true;
}
