# Song Class Fundamentals — Self-Check Guidance

Use this after attempting the exercises.

- Exercises 1–2: public data permits invalid state; the class interface must be
  the only route to modification.
- Exercise 3: trace the initializer list before the constructor body and test
  every constructor requirement.
- Exercises 4–5: observers should be `const`; a modifying operation validates
  before changing state.
- Exercises 6–7: calculated values need no extra data member; title changes
  must preserve the invariant.
- Exercise 8: a `const Song&` avoids a copy and prevents modification.
- Exercise 9: declarations describe the interface; the `.cpp` file contains
  non-inline definitions.
- Exercise 10: judge the new class by whether invalid objects can be created or
  produced through its public operations.

Re-run `make test` after each change and add tests for every new rule.

