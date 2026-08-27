# Guided Exercises

Complete the exercises in order and run `make test` after every change.

## 1. Assign responsibilities

For `Product`, `ProductCatalog`, `CartItem`, and `ShoppingCart`, list the data
and behavior owned by each class. Identify one behavior that would be misplaced
if moved to another class.

## 2. Trace construction

Trace construction of a `CartItem`. Which object is constructed as one of its
data members? Explain why the Product constructor is not called with individual
arguments at this point.

## 3. Trace a catalog search

Trace `findByCode` for an existing and a missing code. Explain the meanings of
the returned Product address and `nullptr`.

## 4. Prevent duplicate products

Explain how `ProductCatalog::addProduct` ensures code uniqueness. Add a test
that attempts to insert two different Product objects with the same code.

## 5. Merge repeated cart selections

Add the same Product to a ShoppingCart three times. Trace `findItem` and
`increaseQuantity`. Why should the cart contain one CartItem rather than three?

## 6. Composition and copying

Add a Product to a cart and then change the original Product's price. Explain
why the cart total remains unchanged. Identify exactly where the copy occurs.

## 7. Add product removal

Implement `bool removeProduct(const std::string& productCode)` in
`ProductCatalog`. Return false when the code is absent and add tests for both
outcomes.

## 8. Add quantity reduction

Implement `bool removeOne(const std::string& productCode)` in ShoppingCart.
Reduce the quantity by one and remove the CartItem when its quantity reaches
zero.

## 9. Add a discount calculation

Implement `double getTotalAfterDiscount(double percentage) const`. Reject
percentages outside 0–100 without changing any object state.

## 10. Relationship reasoning

For each relationship in the project, state whether the containing object owns
the related object. Then explain why the temporary pointer returned by
`findByCode` represents neither composition nor ownership.
