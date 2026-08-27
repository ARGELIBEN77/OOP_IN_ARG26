#ifndef SHOPPING_CART_HPP
#define SHOPPING_CART_HPP

#include "CartItem.hpp"

#include <cstddef>
#include <iosfwd>
#include <vector>

// ShoppingCart owns CartItem values. Each CartItem in turn owns a Product copy,
// forming a clear composition chain: ShoppingCart -> CartItem -> Product.
class ShoppingCart
{
private:
    std::vector<CartItem> items;

    CartItem* findItem(const std::string& productCode);

public:
    // If the Product already exists in the cart, addProduct increases its
    // quantity instead of creating a duplicate CartItem.
    bool addProduct(const Product& product, int quantity = 1);

    std::size_t getDifferentProductCount() const;
    int getTotalQuantity() const;
    double getTotalPrice() const;
    bool empty() const;

    void display(std::ostream& output) const;
};

#endif
