#include "InsufficientStockError.hpp"
#include "MusicStore.hpp"
#include "Product.hpp"

#include <exception>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

// This small educational helper makes stack unwinding visible. When an
// exception leaves attemptCheckout, the local object is destroyed before the
// matching catch block in main begins.
class ScopeTracer
{
private:
    std::string scopeName;

public:
    explicit ScopeTracer(std::string name)
        : scopeName(std::move(name))
    {
        std::cout << "Entering " << scopeName << '\n';
    }

    ~ScopeTracer()
    {
        std::cout << "Leaving " << scopeName << '\n';
    }
};

double attemptCheckout(MusicStore& store,
                       const std::string& productCode,
                       int quantity)
{
    ScopeTracer tracer("attemptCheckout");

    // No catch appears here. Any exception travels back to the caller, while
    // normal destruction of local objects occurs during stack unwinding.
    return store.checkout(productCode, quantity);
}

void runExample(MusicStore& store,
                const std::string& productCode,
                int quantity)
{
    std::cout << "\nRequest: " << productCode
              << ", quantity " << quantity << '\n';

    try
    {
        const double total = attemptCheckout(store, productCode, quantity);
        std::cout << "Purchase completed. Total: $"
                  << std::fixed << std::setprecision(2) << total << '\n';
    }
    catch (const InsufficientStockError& error)
    {
        // Catch the most specific custom type before broader base types.
        std::cout << "Stock error: " << error.what() << '\n';
    }
    catch (const std::invalid_argument& error)
    {
        std::cout << "Invalid request: " << error.what() << '\n';
    }
    catch (const std::out_of_range& error)
    {
        std::cout << "Catalog error: " << error.what() << '\n';
    }
    catch (const std::exception& error)
    {
        // This final handler is a safety net for other standard exceptions.
        std::cout << "Unexpected error: " << error.what() << '\n';
    }
}

int main()
{
    std::cout << "Music Store Exception Handling Demonstration\n";

    MusicStore store;
    store.addProduct(Product("HP100", "Studio Headphones", 129.90, 4));
    store.addProduct(Product("VR300", "Classic Rock Vinyl", 34.00, 2));

    runExample(store, "HP100", 2);  // Successful purchase.
    runExample(store, "HP100", 0);  // std::invalid_argument.
    runExample(store, "UNKNOWN", 1); // std::out_of_range.
    runExample(store, "VR300", 5);  // Custom exception.

    return 0;
}
