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

## Learning focus

Use this project to build a clear mental model of one class and its objects.
Pay particular attention to the boundary between private state and the public
interface. Constructor assertions express the object's requirements, while
`setRating` demonstrates controlled modification of existing state.

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
