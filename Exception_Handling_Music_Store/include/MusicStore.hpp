#ifndef MUSIC_STORE_HPP
#define MUSIC_STORE_HPP

#include "Product.hpp"

#include <cstddef>
#include <string>
#include <vector>

class MusicStore
{
private:
    std::vector<Product> products;

    Product* findProduct(const std::string& productCode);

public:
    void addProduct(const Product& product);
    std::size_t size() const;

    // checkout does not catch purchase errors. It lets them propagate to the
    // application layer, where a suitable user-facing response can be chosen.
    double checkout(const std::string& productCode, int quantity);
};

#endif
