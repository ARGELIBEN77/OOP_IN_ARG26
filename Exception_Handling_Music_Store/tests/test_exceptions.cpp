#include "InsufficientStockError.hpp"
#include "MusicStore.hpp"
#include "Product.hpp"

#include <cassert>
#include <cmath>
#include <stdexcept>
#include <string>

namespace
{
bool approximatelyEqual(double first, double second)
{
    return std::fabs(first - second) < 0.0001;
}

void testSuccessfulPurchase()
{
    Product product("HP100", "Studio Headphones", 100.00, 5);

    const double total = product.purchase(2);

    assert(approximatelyEqual(total, 200.00));
    assert(product.getStock() == 3);
}

void testInvalidQuantity()
{
    Product product("HP100", "Studio Headphones", 100.00, 5);
    bool caught = false;

    try
    {
        product.purchase(0);
    }
    catch (const std::invalid_argument&)
    {
        caught = true;
    }

    assert(caught);
    assert(product.getStock() == 5);
}

void testCustomExceptionData()
{
    Product product("VR300", "Classic Rock Vinyl", 25.00, 2);
    bool caught = false;

    try
    {
        product.purchase(5);
    }
    catch (const InsufficientStockError& error)
    {
        caught = true;
        assert(error.getProductCode() == "VR300");
        assert(error.getRequestedQuantity() == 5);
        assert(error.getAvailableQuantity() == 2);
        assert(std::string(error.what()).find("Insufficient stock") !=
               std::string::npos);
    }

    assert(caught);
    assert(product.getStock() == 2);
}

void testUnknownProductPropagation()
{
    MusicStore store;
    store.addProduct(Product("HP100", "Studio Headphones", 100.00, 5));
    bool caught = false;

    try
    {
        store.checkout("UNKNOWN", 1);
    }
    catch (const std::out_of_range& error)
    {
        caught = true;
        assert(std::string(error.what()).find("UNKNOWN") != std::string::npos);
    }

    assert(caught);
}

void testDuplicateCode()
{
    MusicStore store;
    store.addProduct(Product("HP100", "Studio Headphones", 100.00, 5));
    bool caught = false;

    try
    {
        store.addProduct(Product("HP100", "Different Product", 20.00, 1));
    }
    catch (const std::invalid_argument&)
    {
        caught = true;
    }

    assert(caught);
    assert(store.size() == 1);
}

void testCatchByBaseReference()
{
    Product product("VR300", "Classic Rock Vinyl", 25.00, 1);
    bool caught = false;

    try
    {
        product.purchase(3);
    }
    catch (const std::exception& error)
    {
        // InsufficientStockError derives from runtime_error, which derives
        // from exception, so a base reference can catch it polymorphically.
        caught = true;
        assert(std::string(error.what()).find("VR300") != std::string::npos);
    }

    assert(caught);
}
}

int main()
{
    testSuccessfulPurchase();
    testInvalidQuantity();
    testCustomExceptionData();
    testUnknownProductPropagation();
    testDuplicateCode();
    testCatchByBaseReference();
    return 0;
}
