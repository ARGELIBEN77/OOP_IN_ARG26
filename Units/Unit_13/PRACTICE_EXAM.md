# Practice Examination

**Duration:** 180 minutes  
**Total:** 100 points  
**Language standard:** C++17

## Instructions

- Answer every question.
- You may add small helper functions when they improve the design.
- Unless stated otherwise, assume all required standard headers are included.
- When asked to predict output, explain the reason for the order.
- Code must manage resources safely and preserve valid object state.
- A clear, substantially correct solution may receive partial credit.

## Question 1 (20 points)

Study the following program without compiling it.

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Track {
    std::string title;

public:
    explicit Track(std::string title) : title(std::move(title)) {
        std::cout << "create " << this->title << '\n';
    }

    ~Track() { std::cout << "destroy " << title << '\n'; }

    const std::string& getTitle() const { return title; }
};

void inspect(const Track& track) {
    std::cout << "inspect " << track.getTitle() << '\n';
}

int main() {
    auto first = std::make_unique<Track>("Blue");
    inspect(*first);
    {
        auto second = std::move(first);
        std::cout << std::boolalpha << (first == nullptr) << '\n';
        inspect(*second);
    }
    std::cout << "finished\n";
}
```

a. Write the exact output in order. (8 points)  
b. Explain why `inspect` does not create another `Track`. (4 points)  
c. Explain the ownership change caused by `std::move(first)`. (4 points)  
d. State exactly when the `Track` is destroyed and why. (4 points)

## Question 2 (20 points)

The following code is intended to store different media items and display
them polymorphically. It contains several design or C++ errors.

```cpp
class MediaItem {
    std::string title;

public:
    MediaItem(const std::string& title) : title(title) {}
    ~MediaItem() = default;
    virtual void print() const = 0;
};

class Song : MediaItem {
public:
    Song(const std::string& title) : MediaItem(title) {}
    void print() { std::cout << "song\n"; }
};

int main() {
    std::vector<MediaItem> items;
    items.push_back(Song("Morning"));
    for (MediaItem item : items) {
        item.print();
    }
}
```

a. Identify four distinct problems and explain the effect of each. (12 points)  
b. Rewrite the declarations and `main` so the program safely owns the objects
and invokes the correct override. (8 points)

## Question 3 (25 points)

Complete the essential parts of this class. A `Playlist` owns a dynamically
allocated array of names. Each object must own its own array.

```cpp
class Playlist {
    std::string* names;
    std::size_t count;

public:
    Playlist(const std::string initialNames[], std::size_t count);
    Playlist(const Playlist& other);
    Playlist& operator=(const Playlist& other);
    ~Playlist();

    const std::string& operator[](std::size_t index) const;
    bool operator==(const Playlist& other) const;
};
```

a. Implement the constructor, copy constructor, copy-assignment operator and
destructor. Handle self-assignment safely. (17 points)  
b. Implement `operator[]`. It must throw `std::out_of_range` for an invalid
index. (4 points)  
c. Implement `operator==`; two playlists are equal when they contain the same
names in the same order. (4 points)

## Question 4 (15 points)

Write one generic function named `countMatching`. It receives an iterator
range and a callable condition, and returns the number of matching elements.

```cpp
template <typename Iterator, typename Predicate>
std::size_t countMatching(Iterator begin, Iterator end, Predicate predicate);
```

a. Implement the function without using an STL counting algorithm. (7 points)  
b. Use it with a `std::vector<int>` and a lambda to count values greater than a
variable named `limit`. (4 points)  
c. Explain why the same function can also work with a `std::list<double>`.
(4 points)

## Question 5 (20 points)

A music application has these requirements:

- Every media item has a title and a virtual `play()` operation.
- `Song` and `Podcast` are media-item types.
- The library exclusively owns all media items.
- An empty title reports an error.
- The application plays every stored item without testing its concrete type.

a. Draw or describe the required class relationships. (5 points)  
b. Choose the library container, including its element type, and justify the
ownership decision. (5 points)  
c. Write the essential class declarations and the library's `add` and
`playAll` operations. (8 points)  
d. Show one call that creates a `Song` and transfers it into the library.
(2 points)
