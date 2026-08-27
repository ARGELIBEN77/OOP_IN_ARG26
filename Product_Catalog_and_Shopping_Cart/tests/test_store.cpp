#include "Product.hpp"
#include "ProductCatalog.hpp"
#include "ShoppingCart.hpp"

#include <cassert>
#include <cmath>
#include <sstream>
#include <string>

namespace
{
bool approximatelyEqual(double first, double second)
{
    return std::fabs(first - second) < 0.0001;
}

void testProductEncapsulation()
{
    Product product("HP100", "Studio Headphones", "Audio", 129.90);

    assert(product.getCode() == "HP100");
    assert(product.changePrice(119.90));
    assert(approximatelyEqual(product.getPrice(), 119.90));

    assert(!product.changePrice(-5.0));
    assert(approximatelyEqual(product.getPrice(), 119.90));
}

void testCatalogSearchAndDuplicateProtection()
{
    ProductCatalog catalog;
    const Product headphones("HP100", "Studio Headphones", "Audio", 129.90);

    assert(catalog.addProduct(headphones));
    assert(!catalog.addProduct(headphones));
    assert(catalog.size() == 1);
    assert(catalog.findByCode("HP100") != nullptr);
    assert(catalog.findByCode("UNKNOWN") == nullptr);
}

void testCartCompositionAndTotals()
{
    const Product headphones("HP100", "Studio Headphones", "Audio", 100.00);
    const Product vinyl("VR300", "Classic Rock Vinyl", "Music", 25.00);

    ShoppingCart cart;
    assert(cart.addProduct(headphones, 1));
    assert(cart.addProduct(vinyl, 2));
    assert(cart.addProduct(vinyl, 1));

    assert(cart.getDifferentProductCount() == 2);
    assert(cart.getTotalQuantity() == 4);
    assert(approximatelyEqual(cart.getTotalPrice(), 175.00));
}

void testCartRejectsInvalidQuantity()
{
    const Product product("SP200", "Bluetooth Speaker", "Audio", 89.50);
    ShoppingCart cart;

    assert(!cart.addProduct(product, 0));
    assert(!cart.addProduct(product, -2));
    assert(cart.empty());
}

void testCartOwnsProductCopy()
{
    Product product("HP100", "Studio Headphones", "Audio", 100.00);
    ShoppingCart cart;
    cart.addProduct(product, 1);

    // Changing the original Product does not change the Product copy already
    // contained by CartItem.
    product.changePrice(80.00);
    assert(approximatelyEqual(cart.getTotalPrice(), 100.00));
}

void testDisplay()
{
    const Product product("VR300", "Classic Rock Vinyl", "Music", 25.00);
    ShoppingCart cart;
    cart.addProduct(product, 2);

    std::ostringstream output;
    cart.display(output);

    assert(output.str().find("Classic Rock Vinyl x 2") != std::string::npos);
    assert(output.str().find("Total price: $50.00") != std::string::npos);
}
}

int main()
{
    testProductEncapsulation();
    testCatalogSearchAndDuplicateProtection();
    testCartCompositionAndTotals();
    testCartRejectsInvalidQuantity();
    testCartOwnsProductCopy();
    testDisplay();
    return 0;
}
