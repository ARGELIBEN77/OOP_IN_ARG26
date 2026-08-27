# Inheritance and Polymorphism — Media Library

This C++17 project applies the concepts from Units 7–8 in one small program.
It continues the Music Library case study with several kinds of playable media.

## Main learning goals

Students will see how to:

- model an **is-a** relationship with public inheritance;
- initialize the base part of a derived object;
- override virtual functions safely with `override`;
- define an abstract class with a pure virtual function;
- use base references and pointers without slicing objects;
- observe run-time polymorphism through one common call;
- explain why a polymorphic base class needs a virtual destructor;
- distinguish a non-owning pointer from an owning pointer.

## Class design

`MediaItem` stores the title and duration shared by all media. Its `play`
function is pure virtual because there is no honest generic way to play an
unspecified media item. `Song`, `PodcastEpisode`, and `Audiobook` are concrete
derived classes that implement `play` and extend `printDetails`.

`MusicLibrary` stores non-owning `const MediaItem*` values. A single loop calls
the correct derived override for each real object at run time.

## Build and run

From the repository root:

```bash
cd Inheritance_Polymorphism_Media_Library
make run
make test
```

To remove compiled files:

```bash
make clean
```

## Recommended reading order

1. `include/MediaItem.hpp` — identify shared state and virtual operations.
2. `include/Song.hpp` and `src/Song.cpp` — trace one derived class.
3. `include/PodcastEpisode.hpp` and `include/Audiobook.hpp` — compare overrides.
4. `include/MusicLibrary.hpp` and `src/MusicLibrary.cpp` — find the base pointers.
5. `src/main.cpp` — trace each polymorphic call.
6. `tests/test_media_library.cpp` — inspect the required design properties.
7. `EXERCISES.md` — complete the guided extensions.

## Important ownership rule

The library does **not** own the media objects and never deletes them. Every
object added to a `MusicLibrary` must remain alive while the library uses it.
In `main`, the media objects are created before the library, so reverse local
destruction order destroys the library first.

Smart pointers are intentionally not used here. Ownership with `unique_ptr`
and `shared_ptr` belongs to the later smart-pointer unit.

## Project structure

```text
Inheritance_Polymorphism_Media_Library/
├── include/                  Class declarations
├── src/                      Implementations and demonstration
├── tests/                    Small behavioral tests
├── EXERCISES.md              Guided student work
├── Makefile
└── README.md
```
