# Playlist — Rule of Three and Operator Overloading

This Unit 6 project continues the Music Library case study. `Playlist` owns a
dynamically allocated array of `Song` objects, so copying and destruction must
be implemented explicitly.

## Main learning goals

Students will learn to:

- identify a class that owns a dynamic resource;
- explain shallow copy and the danger of double deletion;
- implement a destructor, copy constructor, and copy assignment operator;
- perform a deep copy so objects own independent arrays;
- handle self-assignment;
- grow a dynamic array safely;
- implement `==`, `!=`, `<`, `<<`, `+=`, and `[]` with appropriate signatures;
- reuse one operator when implementing a related operator;
- distinguish member and non-member operators.

## Build and run

From the repository root:

```bash
cd Playlist_Rule_of_Three_and_Operators
make run
make test
```

To remove generated executables:

```bash
make clean
```

## Recommended reading order

1. `include/Song.hpp` — identify member and non-member operators.
2. `src/Song.cpp` — see `!=` reuse `==` and inspect stream output.
3. `include/Playlist.hpp` — locate the owned pointer and Rule of Three.
4. `src/Playlist.cpp` — trace allocation, copying, assignment, and deletion.
5. `src/main.cpp` — observe deep-copy independence.
6. `tests/test_playlist.cpp` — inspect the required behavior.
7. `EXERCISES.md` — complete the guided activities.

## Central ownership model

Each `Playlist` owns exactly one dynamic `Song` array:

- the constructor allocates it with `new[]`;
- the destructor releases it with `delete[]`;
- the copy constructor allocates a different array and copies the songs;
- copy assignment prepares a new array before releasing the old one;
- `ensureCapacity` replaces a full array with a larger one.

The project intentionally uses manual memory management because that is the
learning goal of the Rule of Three. Later C++ code should normally prefer
standard containers and the Rule of Zero.

## Core and extension operators

The central Unit 6 operators are Song comparison and stream insertion. The
Playlist collection operators are included as a natural extension:

- `playlist += song` appends a song;
- `playlist[index]` accesses an existing song;
- `output << playlist` prints the complete playlist.

`operator[]` assumes that `index < playlist.size()`. Exception-based bounds
checking is left for the later exception-handling unit.

## Project structure

```text
Playlist_Rule_of_Three_and_Operators/
├── include/
│   ├── Song.hpp
│   └── Playlist.hpp
├── src/
│   ├── Song.cpp
│   ├── Playlist.cpp
│   └── main.cpp
├── tests/
│   └── test_playlist.cpp
├── EXERCISES.md
├── Makefile
└── README.md
```
