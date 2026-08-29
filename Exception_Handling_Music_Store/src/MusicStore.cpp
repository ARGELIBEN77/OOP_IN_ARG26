#include "MusicStore.hpp"

#include <stdexcept>

Product* MusicStore::findProduct(const std::string& productCode)
{
    for (Product& product : products)
    {
        if (product.getCode() == productCode)
            return &product;
    }

    return nullptr;
}

void MusicStore::addProduct(const Product& product)
{
    if (findProduct(product.getCode()) != nullptr)
        throw std::invalid_argument("Duplicate product code: " + product.getCode());

    products.push_back(product);
}

std::size_t MusicStore::size() const
{
    return products.size();
}

double MusicStore::checkout(const std::string& productCode, int quantity)
{
    Product* product = findProduct(productCode);

    if (product == nullptr)
        throw std::out_of_range("Unknown product code: " + productCode);

    // Product::purchase may throw invalid_argument or
    // InsufficientStockError. This function deliberately does not catch them.
    return product->purchase(quantity);
}
