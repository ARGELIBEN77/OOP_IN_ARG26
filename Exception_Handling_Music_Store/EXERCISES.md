# Guided Exercises

Complete the exercises in order and run `make test` after every change.

## 1. Classify the exception types

For every `throw` statement, identify the exception type, the condition that
causes it, and the catch block that handles it.

## 2. Trace a successful purchase

Trace `runExample`, `attemptCheckout`, `MusicStore::checkout`, and
`Product::purchase` when enough stock exists. Explain why no catch block runs.

## 3. Trace propagation

Trace an unknown product request. List the functions removed from the call
stack before the `std::out_of_range` handler begins.

## 4. Observe stack unwinding

Run the program and examine the `ScopeTracer` output. Why is its destructor
called even though `attemptCheckout` does not reach a normal return statement?

## 5. Test the strong state rule

Request more units than are available and verify that stock remains unchanged.
Explain why validation occurs before `stock -= quantity`.

## 6. Reverse two catch blocks

Temporarily place `catch (const std::exception&)` before the custom handler.
Compile and record the warning or behavior. Explain why handlers should be
ordered from the most specific type to the most general.

## 7. Extend the custom exception

Add the product name to `InsufficientStockError`. Update its message, getters,
throw statement, and tests.

## 8. Add a payment exception

Create `PaymentDeclinedError`, derived from `std::runtime_error`, with a reason
string. Add one demonstration and one test without changing existing handlers
unnecessarily.

## 9. Decide between return values and exceptions

For each condition below, justify either a return value or an exception:

- a search finds no optional recommendation;
- a required checkout product does not exist;
- a discount code is simply not applicable;
- a constructor receives an empty product code.

## 10. Destructor rule

Explain why destructors should not allow exceptions to escape during stack
unwinding. Describe what could happen if a second exception were thrown while
the first exception was already being handled.
