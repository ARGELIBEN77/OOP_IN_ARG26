# Song Class Fundamentals

This introductory project supports the first OOP units. It begins with a
procedural `struct` and then redesigns the same idea as an encapsulated class.

## Main learning goals

Students will learn to:

- explain the difference between a `struct` with public data and a class;
- separate a class declaration from its implementation;
- protect object state with `private` data members;
- design a small public interface;
- construct valid objects with a constructor and initializer list;
- use getters and controlled modifying methods;
- mark non-modifying member functions `const`;
- pass an object by `const` reference;
- distinguish an object's state from its behavior.

## Build and run

From the repository root:

```bash
cd Song_Class_Fundamentals
make compare
make test
```

`make compare` runs two programs:

1. the procedural `SongData` version, where public fields can be corrupted;
2. the encapsulated `Song` class, where modification uses a checked operation.

The class version alone can be run with:

```bash
make run
```

## Recommended reading order

1. `examples/ProceduralSong.cpp` — identify the public data and free function.
2. `include/Song.hpp` — separate private state from the public interface.
3. `src/Song.cpp` — inspect the initializer list and `const` methods.
4. `src/main.cpp` — see how client code creates and uses objects.
5. `tests/test_song.cpp` — inspect the class's expected behavior.
6. `EXERCISES.md` — complete the guided activities.

## Important scope decision

This project intentionally excludes inheritance, operator overloading,
templates, smart pointers, and manual dynamic memory. The goal is to establish
a clear mental model of one class and its objects before adding relationships
between classes.

Constructor requirements are expressed with assertions because exception
handling belongs to a later unit. `setRating` demonstrates validation without
requiring `try` and `catch`.

## Project structure

```text
Song_Class_Fundamentals/
├── examples/
│   └── ProceduralSong.cpp
├── include/
│   └── Song.hpp
├── src/
│   ├── Song.cpp
│   └── main.cpp
├── tests/
│   └── test_song.cpp
├── EXERCISES.md
├── Makefile
└── README.md
```
