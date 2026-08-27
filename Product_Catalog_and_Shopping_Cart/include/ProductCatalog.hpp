#ifndef PRODUCT_CATALOG_HPP
#define PRODUCT_CATALOG_HPP

#include "Product.hpp"

#include <cstddef>
#include <iosfwd>
#include <string>
#include <vector>

// ProductCatalog owns the Product values stored in its vector. It prevents two
// products from using the same identifying code.
class ProductCatalog
{
private:
    std::vector<Product> products;

public:
    bool addProduct(const Product& product);
    std::size_t size() const;

    // Return a pointer to the matching catalog object, or nullptr when no match
    // exists. The pointer is non-owning and must never be deleted by the caller.
    const Product* findByCode(const std::string& code) const;

    void display(std::ostream& output) const;
};

#endif
