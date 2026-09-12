# Exception Handling Music Store — Worked Self-Check

## Follow the exception path

When an exception is thrown, normal execution stops. Search outward for the
first compatible handler. Automatic objects created since entering the selected
handler's scope are destroyed during stack unwinding.

```cpp
try {
    store.purchase(productCode, quantity);
} catch (const OutOfStock& error) {
    std::cout << error.what();
} catch (const std::exception& error) {
    std::cout << "purchase failed: " << error.what();
}
```

The more specific handler comes first because a handler for a compatible base
type would otherwise catch the derived exception.

## Preserve valid state

Validate and prepare all operations that may fail before changing inventory or
payment state. If stock is reduced and a later step throws, the object may no
longer represent a completed or rejected purchase consistently.

A useful test records the state before a failing call and verifies that it is
unchanged afterwards.

## Choose exception meaning

Use a standard exception when its meaning fits, such as `invalid_argument` for
an invalid quantity or `out_of_range` for a missing indexed element. A custom
exception is useful when the handler needs domain context such as product code,
requested amount, and available stock.

Destructors release resources but must not allow exceptions to escape during
unwinding. Test successful purchase, every failure type, catch ordering, and
object state after failure.
