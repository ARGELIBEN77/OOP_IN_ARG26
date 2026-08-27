# Generic Sorted Catalog Project

This C++17 project demonstrates how class templates, iterators, functors,
lambdas, and generic algorithms fit together in one coherent design.

The project continues the Music Library case study. `SortedCatalog<T, Compare>`
stores objects in the order defined by a comparison policy. The same container
can therefore order `Song` objects by title, duration, artist, or another rule
without changing the container implementation.

## Learning objectives

After studying the project, students should be able to:

- explain the roles of `T` and `Compare` in a class template;
- identify the operations required from a comparison policy;
- explain the iterator range `[begin, end)`;
- implement dereference, arrow, increment, and comparison operators;
- explain how a range-based `for` loop uses an iterator;
- pass functors and lambdas to generic algorithms;
- explain lambda captures and `decltype(lambda)`;
- use a custom iterator with a standard-library algorithm.

## Project structure

```text
Generic_Sorted_Catalog_Project/
├── include/
│   ├── Algorithms.hpp       Generic findFirst, countIf, and forEach
│   ├── Song.hpp             Example domain class
│   ├── SongFunctors.hpp     Comparison and predicate functors
│   └── SortedCatalog.hpp    Generic container and iterator
├── src/
│   ├── Song.cpp
│   └── main.cpp             Demonstrations with functors and lambdas
├── EXERCISES.md
├── Makefile
└── README.md
```

Template implementations are placed in header files because the compiler must
see their complete definitions when it instantiates them for a particular type.

## Build and run

```bash
make
make run
make test
```

Or compile directly:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude \
    src/main.cpp src/Song.cpp -o sorted_catalog_demo
./sorted_catalog_demo
```

## Suggested teaching sequence

1. Examine `Song` and verify that it contains no generic-programming code.
2. Instantiate `SortedCatalog<Song, CompareSongByTitle>`.
3. Trace `add` and observe how `Compare` controls `std::lower_bound`.
4. Trace an explicit iterator loop.
5. Translate that loop into a range-based `for` loop.
6. Use a predicate functor with `teaching::countIf`.
7. replace the functor with a lambda.
8. Use the custom iterator with `std::count_if`.
9. Construct a second catalog whose comparator is a lambda.

## Important design decision

The iterator provides `const T&`, even for a non-const catalog. This is
deliberate. If clients changed a title or duration through the iterator, the
catalog could stop being sorted. The design is similar to ordered associative
containers, whose keys cannot be modified through an iterator.

The internal `std::vector` is also deliberate: this project concentrates on
generic programming and iterator design rather than repeating manual memory
management. `SortedCatalog` is still a genuine container because it defines a
new invariant and interface: every insertion preserves an ordering policy.

## Iterator invalidation

An iterator should not be kept while the catalog is modified. `add`, `remove`,
and `clear` may invalidate existing iterators because `std::vector` may move or
shift its elements. Obtain new `begin()` and `end()` iterators after a modifying
operation. This is part of an iterator's behavioral contract, not merely an
implementation detail.
