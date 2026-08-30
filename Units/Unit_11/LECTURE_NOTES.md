# Unit 11 — Smart Pointers, Ownership, and Move Semantics

## Learning objectives

After this unit, students should be able to:

- explain ownership and automatic resource release;
- create exclusively owned objects with `std::make_unique`;
- transfer exclusive ownership using `std::move`;
- create jointly owned objects with `std::make_shared`;
- explain how shared owners determine object lifetime;
- use smart pointers with inheritance and runtime polymorphism;
- choose between a direct object, `unique_ptr`, and `shared_ptr`.

## 1. Ownership gives object lifetime a clear meaning

Dynamic objects live until an owner releases them. An ownership design answers
two questions:

1. Which object is responsible for the resource?
2. When should the resource be released?

Smart pointers represent those answers as ordinary C++ objects. Their
destructors automatically release the managed resources. This connects smart
pointers with RAII: resource acquisition and release follow object lifetime.

```cpp
{
    auto song = std::make_unique<Song>("One", "U2", 276);
    song->display();
} // song is destroyed and releases the Song
```

## 2. Exclusive ownership with `unique_ptr`

`std::unique_ptr<T>` represents one owner of a dynamically allocated `T`.

```cpp
std::unique_ptr<Song> song =
    std::make_unique<Song>("One", "U2", 276);
```

Type deduction often makes the declaration shorter:

```cpp
auto song = std::make_unique<Song>("One", "U2", 276);
```

The smart pointer supports familiar pointer syntax:

```cpp
song->display();
Song& songReference = *song;
```

It can also be checked before dereferencing:

```cpp
if (song != nullptr)
    song->display();
```

## 3. Transferring ownership with `std::move`

Exclusive ownership has one owner at a time. `std::move` enables ownership to
move from one `unique_ptr` to another.

```cpp
auto song = std::make_unique<Song>("One", "U2", 276);
std::unique_ptr<Song> selectedSong = std::move(song);
```

After the transfer:

- `selectedSong` owns the `Song`;
- `song` is empty and can be compared with `nullptr`;
- the `Song` object remains alive throughout the transfer.

`std::move` expresses that the source may give up its resource. The move
operation performed by `unique_ptr` transfers the stored address and clears the
source pointer.

## 4. Passing ownership to another object

A function parameter can make ownership transfer visible in an interface:

```cpp
class MediaLibrary
{
private:
    std::vector<std::unique_ptr<MediaItem>> items;

public:
    void addItem(std::unique_ptr<MediaItem> item)
    {
        items.push_back(std::move(item));
    }
};
```

The caller explicitly transfers ownership:

```cpp
auto song = std::make_unique<Song>("One", "U2", 276);
library.addItem(std::move(song));
```

The interface communicates that the library becomes responsible for the media
item's lifetime.

## 5. Smart pointers and runtime polymorphism

A collection of `unique_ptr<MediaItem>` can own different derived objects:

```cpp
std::vector<std::unique_ptr<MediaItem>> items;

items.push_back(
    std::make_unique<Song>("One", "U2", 276));

items.push_back(
    std::make_unique<Audiobook>("Dune", "Frank Herbert"));
```

Virtual dispatch selects the derived implementation:

```cpp
for (const auto& item : items)
    item->display();
```

The virtual destructor in `MediaItem` ensures that destroying a
`unique_ptr<MediaItem>` correctly destroys the complete derived object.

## 6. Shared ownership with `shared_ptr`

`std::shared_ptr<T>` represents joint ownership. Several smart pointers can
own the same object.

```cpp
auto song = std::make_shared<Song>("Africa", "Toto", 295);

std::shared_ptr<Song> favorite = song;
std::shared_ptr<Song> roadTrip = song;
```

The three smart pointers refer to one `Song`. Copying a `shared_ptr` adds an
owner rather than copying the managed object.

The object remains alive while at least one shared owner exists. It is
destroyed automatically when the final owner is destroyed or releases its
pointer.

## 7. Observing shared ownership

`use_count()` can make the ownership process visible during a demonstration:

```cpp
auto song = std::make_shared<Song>("Africa", "Toto", 295);
std::cout << song.use_count() << '\n'; // 1

auto anotherOwner = song;
std::cout << song.use_count() << '\n'; // 2
```

The program's behavior should follow the intended ownership relationship. The
count is useful for tracing how the example works.

## 8. Sharing a song between playlists

Two playlists can share one song object:

```cpp
auto song = std::make_shared<Song>("Beautiful Day", "U2", 248);

Playlist favorites("Favorites");
Playlist roadTrip("Road Trip");

favorites.addSong(song);
roadTrip.addSong(song);
```

Releasing the original pointer leaves the playlist owners:

```cpp
song.reset();
```

Both playlists can continue using the song. When the playlist owners finish,
the song is destroyed automatically.

## 9. Choosing a representation

| Representation | Ownership meaning | Suitable situation |
|---|---|---|
| `Song` | Direct object lifetime | The object naturally belongs to the current scope or class |
| `Song&` | Temporary access | A function reads or modifies an existing object |
| `Song*` | Nullable, non-owning access | A search may return an existing object or no result |
| `unique_ptr<Song>` | One exclusive owner | One library or manager controls the lifetime |
| `shared_ptr<Song>` | Several lifetime owners | Several independent objects keep the same song alive |

Begin by identifying the ownership relationship. The matching C++ type then
makes the design visible in the class interface.

## 10. Reading smart-pointer declarations

Read declarations from the managed object outward:

```cpp
std::unique_ptr<Song> song;
```

`song` exclusively owns a `Song`.

```cpp
std::vector<std::unique_ptr<MediaItem>> items;
```

`items` is a vector whose elements exclusively own polymorphic media objects.

```cpp
std::shared_ptr<Song> song;
```

`song` participates in shared ownership of one `Song`.

## 11. Summary

- Ownership defines responsibility for object lifetime.
- Smart-pointer destructors release managed objects automatically.
- `unique_ptr` expresses exclusive ownership.
- `std::move` transfers ownership between `unique_ptr` objects.
- `shared_ptr` expresses joint ownership of one object.
- The final shared owner determines when the object is destroyed.
- Smart pointers work naturally with polymorphic collections.
- The class interface should make the intended ownership relationship clear.

## Review questions

1. What does it mean for an object to own another object?
2. How does RAII connect ownership with destruction?
3. Why does transferring a `unique_ptr` require `std::move`?
4. What is the state of the source pointer after ownership transfer?
5. Does copying a `shared_ptr` copy the managed object?
6. When is an object managed by `shared_ptr` destroyed?
7. Why is a virtual destructor important in the Media Library example?
8. When is a direct object or reference clearer than a smart pointer?
9. Which pointer type represents exclusive library ownership?
10. Which pointer type represents a song shared by several playlists?
