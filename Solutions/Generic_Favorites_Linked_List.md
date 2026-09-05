# Generic Favorites Linked List — Self-Check Guidance

- Exercises 1–4: verify that every value-dependent declaration uses `T` and
  that template definitions remain visible in the header.
- Exercises 5–8: draw links after every change; update both `first` and `last`
  when the list becomes empty.
- Exercises 9–12: deep-copy nodes in order, release old nodes exactly once, and
  test copying and assignment with empty and non-empty lists.
- Exercises 13–16: `end()` is the one-past-the-range state; postfix increment
  returns the old iterator value; const traversal must not permit mutation.
- Exercises 17–22: derive callable and iterator requirements from expressions,
  compare functors with capturing lambdas, and test algorithms with more than
  one `T`.

Draw the nodes and iterator position before debugging pointer code.

