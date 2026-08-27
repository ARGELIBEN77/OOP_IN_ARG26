#ifndef CART_ITEM_HPP
#define CART_ITEM_HPP

#include "Product.hpp"

// CartItem is composed of a Product and a quantity. It stores its own Product
// copy, so the item remains valid independently of the catalog.
class CartItem
{
private:
    Product product;
    int quantity;

public:
    CartItem(const Product& product, int quantity);

    const Product& getProduct() const;
    int getQuantity() const;
    double getSubtotal() const;

    bool increaseQuantity(int amount);
};

#endif
