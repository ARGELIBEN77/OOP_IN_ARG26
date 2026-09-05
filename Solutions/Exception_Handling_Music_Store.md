# Exception Handling Music Store — Self-Check Guidance

- Exercises 1–3: match exception type to meaning and trace the throw until the
  first compatible handler.
- Exercise 4: local automatic objects are destroyed as the stack unwinds.
- Exercise 5: validate and prepare all failing work before committing a state
  change.
- Exercise 6: catch derived exception types before a compatible base type.
- Exercises 7–8: useful custom exceptions preserve context needed by the
  handler without exposing unrelated implementation details.
- Exercise 9: use exceptions for failures that prevent an operation from
  fulfilling its contract, not ordinary alternative results.
- Exercise 10: destructors should release resources and must not allow
  exceptions to escape during unwinding.

Test success, every exception type, unchanged state after failure, and catch
ordering.
