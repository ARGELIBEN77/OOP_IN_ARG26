#include "InsufficientStockError.hpp"

#include <utility>

namespace
{
std::string buildMessage(const std::string& productCode,
                         int requestedQuantity,
                         int availableQuantity)
{
    return "Insufficient stock for " + productCode +
           ": requested " + std::to_string(requestedQuantity) +
           ", available " + std::to_string(availableQuantity);
}
}

InsufficientStockError::InsufficientStockError(std::string code,
                                               int requested,
                                               int available)
    : std::runtime_error(buildMessage(code, requested, available)),
      productCode(std::move(code)),
      requestedQuantity(requested),
      availableQuantity(available)
{
}

const std::string& InsufficientStockError::getProductCode() const
{
    return productCode;
}

int InsufficientStockError::getRequestedQuantity() const
{
    return requestedQuantity;
}

int InsufficientStockError::getAvailableQuantity() const
{
    return availableQuantity;
}
