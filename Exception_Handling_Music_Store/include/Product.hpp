#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product
{
private:
    std::string code;
    std::string name;
    double price;
    int stock;

public:
    Product(std::string code,
            std::string name,
            double price,
            int stock);

    const std::string& getCode() const;
    const std::string& getName() const;
    double getPrice() const;
    int getStock() const;

    // Purchase either completes fully or throws before changing stock.
    // Returning the price keeps the successful path simple for the caller.
    double purchase(int quantity);
};

#endif
