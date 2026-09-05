# Product Catalog and Shopping Cart — Self-Check Guidance

- Exercises 1–2: assign each responsibility to the class that owns the needed
  state; trace contained objects during construction.
- Exercise 3: successful search returns access to the existing catalog item;
  unsuccessful search must be represented explicitly.
- Exercises 4–5: check first, then mutate, so duplicates do not corrupt state.
- Exercise 6: the cart uses a snapshot copy of a product; test that later
  catalog changes do not rewrite an existing cart entry.
- Exercises 7–8: test removal at the beginning, middle, end, and missing case.
- Exercise 9: calculate discounts from existing state rather than storing a
  second total that can become inconsistent.
- Exercise 10: distinguish ownership from temporary access. Draw the
  relationship before naming it.

