#ifndef INSUFFICIENT_STOCK_ERROR_HPP
#define INSUFFICIENT_STOCK_ERROR_HPP

#include <stdexcept>
#include <string>

// A custom exception can carry structured information that a general
// std::runtime_error does not provide.
class InsufficientStockError : public std::runtime_error
{
private:
    std::string productCode;
    int requestedQuantity;
    int availableQuantity;

public:
    InsufficientStockError(std::string productCode,
                           int requestedQuantity,
                           int availableQuantity);

    const std::string& getProductCode() const;
    int getRequestedQuantity() const;
    int getAvailableQuantity() const;
};

#endif
