# Smart Pointers and Media Ownership

This C++17 teaching project demonstrates ownership using `std::unique_ptr`,
`std::shared_ptr`, and introductory move semantics. It continues the Media
Library case study and connects smart pointers with inheritance, virtual
functions, virtual destructors, containers, and object lifetime.

## Learning objectives

After studying the project, students should be able to:

- describe exclusive and shared ownership;
- create objects with `std::make_unique` and `std::make_shared`;
- transfer a `unique_ptr` using `std::move`;
- predict the state of a moved-from `unique_ptr`;
- explain how copying a `shared_ptr` adds another owner;
- predict when an exclusively or jointly owned object is destroyed;
- store polymorphic objects in `vector<unique_ptr<MediaItem>>`;
- choose an ownership model that matches an object relationship.

## Project story

`MediaLibrary` exclusively owns its media objects. A media object enters the
library through `unique_ptr<MediaItem>`, and ownership is transferred into the
library with `std::move`.

`Playlist` represents shared lifetime. The same `Song` can belong to several
playlists, and each playlist keeps a `shared_ptr<Song>`. The song remains alive
while at least one owning pointer remains.

## Quick start

```bash
git clone https://github.com/ARGELIBEN77/OOP_IN_ARG26.git
cd OOP_IN_ARG26/Smart_Pointers_Media_Ownership
make run
```

Run the tests:

```bash
make test
```

Remove generated executables:

```bash
make clean
```

Run the commands from `Smart_Pointers_Media_Ownership`, where the `Makefile`
is located.

## Demonstration sequence

The program first creates a `unique_ptr<Song>`, transfers it to a
`MediaLibrary`, and shows that the caller's pointer becomes empty. When the
library leaves scope, its owned object is destroyed automatically.

The program then creates one shared song and adds it to two playlists. It
prints the owner count for observation, releases the original pointer, and
shows that both playlists can still access the song. The object is destroyed
after the playlist owners leave scope.

## Recommended study order

1. Run the demonstration and predict each printed ownership state.
2. Read `MediaItem` and connect its virtual destructor to Units 7–8.
3. Read `MediaLibrary` and trace the `unique_ptr` transfer.
4. Read `main.cpp` and inspect the moved-from pointer.
5. Read `Playlist` and count the owners of its shared song.
6. Read the tests and trace when `livingObjects` changes.
7. Complete the guided exercises in `EXERCISES.md`.

## Project structure

```text
Smart_Pointers_Media_Ownership/
├── include/
│   ├── MediaItem.hpp       Abstract polymorphic base class
│   ├── MediaLibrary.hpp    Exclusive ownership with unique_ptr
│   ├── Playlist.hpp        Shared ownership with shared_ptr
│   └── Song.hpp            Concrete media class
├── src/
│   ├── MediaItem.cpp
│   ├── MediaLibrary.cpp
│   ├── Playlist.cpp
│   ├── Song.cpp
│   └── main.cpp            Ownership demonstration
├── tests/
│   └── test_smart_pointers.cpp
├── EXERCISES.md
├── Makefile
└── README.md
```

## Ownership choices in this project

| Representation | Ownership meaning | Project example |
|---|---|---|
| `Song` | Direct object lifetime | Local value objects |
| `MediaItem*` | Temporary access to an object owned elsewhere | Observation through an existing owner |
| `unique_ptr<MediaItem>` | One exclusive owner | Items owned by `MediaLibrary` |
| `shared_ptr<Song>` | Several owners share the lifetime | Songs stored in several playlists |

The ownership relationship determines the pointer choice.

## Observing lifetime

`MediaItem::getLivingObjectCount()` makes construction and destruction visible
without changing ownership behavior. The tests record the count before a
scope, create smart-pointer owners, and verify that the count returns to its
starting value when those owners are destroyed.
