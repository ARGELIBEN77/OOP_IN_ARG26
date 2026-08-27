#include "Product.hpp"
#include "ProductCatalog.hpp"
#include "ShoppingCart.hpp"

#include <iostream>

int main()
{
    std::cout << "Music Store Product Catalog and Shopping Cart\n\n";

    ProductCatalog catalog;
    catalog.addProduct(Product("HP100", "Studio Headphones", "Audio", 129.90));
    catalog.addProduct(Product("SP200", "Bluetooth Speaker", "Audio", 89.50));
    catalog.addProduct(Product("VR300", "Classic Rock Vinyl", "Music", 34.00));

    std::cout << "Product catalog\n";
    std::cout << "---------------\n";
    catalog.display(std::cout);

    ShoppingCart cart;

    // findByCode returns a non-owning pointer. We check it before dereferencing
    // and immediately pass the Product by const reference to the cart.
    const Product* headphones = catalog.findByCode("HP100");
    if (headphones != nullptr)
        cart.addProduct(*headphones, 1);

    const Product* vinyl = catalog.findByCode("VR300");
    if (vinyl != nullptr)
    {
        cart.addProduct(*vinyl, 2);
        cart.addProduct(*vinyl, 1); // Increases the existing quantity.
    }

    std::cout << '\n';
    cart.display(std::cout);

    return 0;
}
