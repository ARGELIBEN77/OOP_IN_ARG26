# Generic Sorted Catalog Project

This C++17 project demonstrates how class templates, simple iterators, functors,
lambdas, and generic algorithms fit together in one coherent design.

The project continues the Music Library case study. `SortedCatalog<T, Compare>`
stores objects in the order defined by a comparison policy. The same container
can therefore order `Song` objects by title, duration, artist, or another rule
without changing the container implementation.

## What the program demonstrates

The demonstration creates the same collection of songs in two catalogs:

- one catalog is ordered by title using a named comparison functor;
- another is ordered by artist and title using a lambda.

It then traverses the catalogs with a range-based loop and an explicit iterator,
and processes them with small custom generic algorithms.

The iterator is intentionally educational rather than a complete
standard-library iterator. It implements only the operations used in this
project: dereference, arrow, prefix increment, equality, and inequality.
Iterator traits and iterator categories are outside the scope of this project.

## Before you begin

You need:

- a C++ compiler supporting C++17, such as `g++`;
- `make` for the short build commands;
- a terminal opened in the cloned repository.

On Ubuntu or WSL, install the compiler and Make with:

```bash
sudo apt update
sudo apt install build-essential
```

## Quick start

Clone the repository only once:

```bash
git clone https://github.com/ARGELIBEN77/OOP_IN_ARG26.git
cd OOP_IN_ARG26/Generic_Sorted_Catalog_Project
```

Compile and run the demonstration:

```bash
make run
```

Compile and run the tests:

```bash
make test
```

Remove generated executables when finished:

```bash
make clean
```

**Important:** run these commands from inside
`Generic_Sorted_Catalog_Project`, where the `Makefile` is located.

If the project was already cloned, update it before starting:

```bash
cd OOP_IN_ARG26
git pull
cd Generic_Sorted_Catalog_Project
make run
```

## If Make is not available

From inside the project directory, compile directly:

```bash
mkdir -p bin
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude \
    src/main.cpp src/Song.cpp -o bin/sorted_catalog_demo
./bin/sorted_catalog_demo
```

Compile and run the tests directly:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude \
    tests/test_sorted_catalog.cpp src/Song.cpp -o bin/sorted_catalog_tests
./bin/sorted_catalog_tests
```

## What should happen?

The demonstration should print:

1. songs ordered alphabetically by title;
2. the first song longer than 240 seconds;
3. the number of songs by U2;
4. messages showing every song being played;
5. songs ordered by artist and then title;
6. explicit iterator traversal.

The test command should finish with `All SortedCatalog tests passed.` and no
assertion failure.

## Recommended reading order

Build the idea gradually:

1. `include/Song.hpp` and `src/Song.cpp` — the ordinary domain class.
2. `include/SongFunctors.hpp` — named comparison and predicate objects.
3. `src/main.cpp` — see how the catalog is used.
4. `include/Algorithms.hpp` — small generic algorithms using iterator ranges.
5. `include/SortedCatalog.hpp` — the container template and its iterator.
6. `tests/test_sorted_catalog.cpp` — examples of expected behavior.
7. `EXERCISES.md` — guided student tasks.

## Project structure

```text
Generic_Sorted_Catalog_Project/
├── include/
│   ├── Algorithms.hpp       Generic findFirst, countIf, and forEach
│   ├── Song.hpp             Example domain class
│   ├── SongFunctors.hpp     Comparison and predicate functors
│   └── SortedCatalog.hpp    Generic container and simple iterator
├── src/
│   ├── Song.cpp
│   └── main.cpp             Demonstrations with functors and lambdas
├── tests/
│   └── test_sorted_catalog.cpp
├── EXERCISES.md             Guided learning activities
├── Makefile                 Build, run, test, and clean commands
└── README.md
```

Template implementations are placed in header files because the compiler must
see their complete definitions when it instantiates them for a particular type.

## Learning objectives

After studying the project, students should be able to:

- explain the roles of `T` and `Compare` in a class template;
- identify the operations required from a comparison policy;
- explain the iterator range `[begin, end)`;
- implement dereference, arrow, prefix increment, and comparison operators;
- explain how a range-based `for` loop uses an iterator;
- pass functors and lambdas to custom generic algorithms;
- explain lambda captures and `decltype(lambda)`.

## Suggested classroom sequence

1. Run the program before reading its implementation.
2. Examine `Song` and verify that it contains no generic-programming code.
3. Instantiate `SortedCatalog<Song, CompareSongByTitle>`.
4. Trace `add` and observe how `Compare` controls `std::lower_bound`.
5. Trace an explicit iterator loop.
6. Translate that loop into a range-based `for` loop.
7. Use a predicate functor with `teaching::countIf`.
8. Replace the functor with a lambda.
9. Construct a second catalog whose comparator is a lambda.
10. Continue with the tasks in `EXERCISES.md`.

## Code style used in this project

The examples use descriptive camelCase names. Data members do not use trailing
underscores: for example, the catalog stores `items` and `compare`, and the
iterator stores `current`. Comments focus on the purpose of templates,
iterators, comparison policies, and generic algorithms rather than repeating
obvious C++ syntax.

## Important design decision

The iterator provides `const T&`, even for a non-const catalog. This is
deliberate. If clients changed a title or duration through the iterator, the
catalog could stop being sorted.

The internal `std::vector` is also deliberate: this project concentrates on
generic programming and iterator design rather than repeating manual memory
management. `SortedCatalog` is still a genuine container because it defines a
new invariant and interface: every insertion preserves an ordering policy.

## Iterator invalidation

An iterator should not be kept while the catalog is modified. `add`, `remove`,
and `clear` may invalidate existing iterators because `std::vector` may move
or shift its elements. Obtain new `begin()` and `end()` iterators after a
modifying operation.
