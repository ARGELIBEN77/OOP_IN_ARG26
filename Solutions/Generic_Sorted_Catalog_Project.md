# Generic Sorted Catalog — Self-Check Guidance

- Exercise 1: identify the exact substitutions for `T` and `Compare`; template
  definitions must be visible when instantiation occurs.
- Exercise 2: trace comparisons until the insertion position is found and
  verify the ordering invariant after every insertion.
- Exercises 3–4: the iterator needs dereference, increment, and comparison for
  traversal; connect `begin()` and `end()` to the range-based loop translation.
- Exercises 5–6: a functor stores named reusable behavior; a lambda is often
  clearer for short local behavior and may capture context.
- Exercises 7–8: derive requirements from expressions in the algorithm body
  and trace the iterator range without assuming random access.
- Exercises 9–10: document each new template requirement and add tests using a
  second element type.

