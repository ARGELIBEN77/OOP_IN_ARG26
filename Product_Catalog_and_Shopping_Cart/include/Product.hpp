#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iosfwd>
#include <string>

// Product is a small value-like class. Its private data can be observed through
// getters, while changes must pass through controlled public operations.
class Product
{
private:
    std::string code;
    std::string name;
    std::string category;
    double price;

public:
    Product(std::string code,
            std::string name,
            std::string category,
            double price);

    const std::string& getCode() const;
    const std::string& getName() const;
    const std::string& getCategory() const;
    double getPrice() const;

    // Rejecting an invalid request keeps the object in its previous valid state.
    bool changePrice(double newPrice);

    void display(std::ostream& output) const;
};

#endif
