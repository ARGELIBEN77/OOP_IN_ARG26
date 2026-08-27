#include "ProductCatalog.hpp"

#include <ostream>

bool ProductCatalog::addProduct(const Product& product)
{
    if (findByCode(product.getCode()) != nullptr)
        return false;

    products.push_back(product);
    return true;
}

std::size_t ProductCatalog::size() const
{
    return products.size();
}

const Product* ProductCatalog::findByCode(const std::string& code) const
{
    for (const Product& product : products)
    {
        if (product.getCode() == code)
            return &product;
    }

    return nullptr;
}

void ProductCatalog::display(std::ostream& output) const
{
    for (const Product& product : products)
    {
        product.display(output);
        output << '\n';
    }
}
