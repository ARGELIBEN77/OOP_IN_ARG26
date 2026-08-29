# FavoritesList Guided Exercises

Complete the exercises in order. Build and test after each change.

## Part 1 — Understand the class template

1. Create `FavoritesList<double>` in `main.cpp` and add three values.
2. Explain why `Node` is declared inside `FavoritesList<T>`.
3. Identify every place where `T` is replaced when the compiler creates
   `FavoritesList<Song>`.
4. Explain why template method implementations are kept in the header file.

## Part 2 — Trace the linked structure

5. Draw the nodes after adding `10`, `20`, and `30`. Mark `first`, `last`, and
   every `next` pointer.
6. Trace `removeFirst` when removing the first, middle, and last nodes.
7. Explain why `last` must change when the final node is removed.
8. Add a `back()` method with const and non-const versions. Throw
   `std::out_of_range` when the list is empty.

## Part 3 — Ownership and copying

9. Explain what would go wrong with the compiler-generated copy constructor.
10. Temporarily print from `clear()` and observe when copied lists release
    their nodes.
11. Add a test proving that assignment to a non-empty list deletes its old
    elements and copies the new elements.
12. Explain how the temporary object in `operator=` makes self-assignment and
    exceptions safer.

## Part 4 — Build the iterator

13. Rewrite one range-based loop as an explicit iterator loop.
14. Explain why `end()` contains `nullptr` rather than the last node.
15. Add postfix increment as an optional extension. First explain why it must
    return the iterator's old position.
16. Advanced: design a separate `ConstIterator`. Do this only after the basic
    iterator is fully understood.

## Part 5 — Generic algorithms, functors, and lambdas

17. Use `findFirst` with a lambda to find a song by title.
18. Create a `DurationAtLeast` functor and use it with `countIf`.
19. Replace that functor with a lambda capturing the minimum duration.
20. Use `forEach` and a reference capture to calculate total duration.
21. Call one generic algorithm with `FavoritesList<std::string>` to prove that
    the algorithm is independent of `Song`.
22. Write a generic `allOf` algorithm that returns true when every element
    satisfies a predicate. Add tests for an empty and a non-empty range.

## Reflection questions

1. Which operations must `Iterator` provide for the three algorithms?
2. Which additional operation does `removeFirst` require from `T`?
3. What is the difference between `T`, `Iterator`, `Predicate`, and `Action`?
4. When is a named functor clearer than a lambda?
5. Which part of the project is compile-time polymorphism?
6. How is the iterator different from a pointer, and how is it similar?
