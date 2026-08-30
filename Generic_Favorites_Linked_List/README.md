# Generic Favorites Linked List

This C++17 learning project implements `FavoritesList<T>`, a generic singly
linked container that preserves insertion order. It connects class templates,
manual ownership, simple iterators, generic algorithms, functors, and lambdas
in the Music Library case study.

The iterator focuses on the essential operations needed for explicit
traversal, range-based loops, and this project's generic algorithms:
dereference, arrow, prefix increment, equality, and inequality.

## Learning objectives

After completing the project, students should be able to:

- explain how one class template creates containers for different types;
- describe a singly linked list using `first`, `last`, and `next` pointers;
- explain why an owning linked list needs a destructor and deep copying;
- implement the core operations of a simple forward iterator;
- explain how a range-based `for` loop uses `begin()` and `end()`;
- write generic algorithms over the half-open range `[first, last)`;
- pass a named functor or lambda as a predicate;
- explain what a lambda captures by value or by reference;
- identify type requirements such as the need for `operator==`.

## What the demonstration does

The program:

1. creates `FavoritesList<Song>` and adds songs in a chosen order;
2. traverses the list with a range-based loop;
3. counts U2 songs with the `ArtistMatches` functor;
4. finds a long song with a capturing lambda;
5. prints titles with a generic `forEach` algorithm;
6. creates `FavoritesList<std::string>` to demonstrate reuse with another type.

## Quick start

Clone the repository only once, then enter this project directory:

```bash
git clone https://github.com/ARGELIBEN77/OOP_IN_ARG26.git
cd OOP_IN_ARG26/Generic_Favorites_Linked_List
```

Compile and run the demonstration:

```bash
make run
```

Compile and run the tests:

```bash
make test
```

Remove generated executables:

```bash
make clean
```

Run these commands from `Generic_Favorites_Linked_List`, where the `Makefile`
is located.

## If Make is unavailable

```bash
mkdir -p bin
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude \
    src/main.cpp src/Song.cpp -o bin/favorites_list_demo
./bin/favorites_list_demo
```

For the tests:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude \
    tests/test_favorites_list.cpp src/Song.cpp \
    -o bin/favorites_list_tests
./bin/favorites_list_tests
```

The final line should be `All FavoritesList tests passed.`

## Recommended study order

1. Run `make run` and inspect the output.
2. Read `src/main.cpp` to see how clients use the container.
3. Read `include/FavoritesList.hpp` through `add`, `clear`, and the Rule of
   Three operations.
4. Draw the node chain before studying `removeFirst`.
5. Trace the nested `Iterator` and rewrite a range-based loop explicitly.
6. Read `include/Algorithms.hpp` and identify what each algorithm requires
   from its iterator and callable object.
7. Compare `ArtistMatches` with the lambdas in `main.cpp`.
8. Run the tests and complete `EXERCISES.md`.

## Project structure

```text
Generic_Favorites_Linked_List/
├── include/
│   ├── Algorithms.hpp        Three small generic algorithms
│   ├── FavoritesList.hpp     Container template, nodes, and iterator
│   ├── Song.hpp              Example element type
│   └── SongPredicates.hpp    Named predicate functor
├── src/
│   ├── Song.cpp
│   └── main.cpp              Demonstration program
├── tests/
│   └── test_favorites_list.cpp
├── EXERCISES.md              Guided student work
├── Makefile                  Build, run, test, and clean commands
└── README.md
```

## Important design decisions

`FavoritesList` uses raw pointers to make node ownership visible and reinforce
the Rule of Three. Students can trace exactly when nodes are allocated, copied,
linked, unlinked, and deleted.

Adding happens at the end so iteration keeps the students' insertion order.
The `last` pointer makes this operation constant time.

`removeFirst` uses `operator==`, so it works only for element types that can be
compared for equality. Other operations do not impose that requirement. This
is an example of a template type requirement.

## Iterator validity

Adding an element does not invalidate iterators that already refer to existing
nodes. Removing an element invalidates an iterator referring to that element.
`clear()` and destruction invalidate all iterators. An invalid iterator must
not be dereferenced or incremented.
