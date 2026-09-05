# Practice Examination — Solutions and Self-Check Guide

Use this guide only after completing the
[`Practice Examination`](../../Units/Unit_13/PRACTICE_EXAM.md). Equivalent
correct C++ designs are possible. Compare the reasoning, not only the syntax.

## Question 1

```text
create Blue
inspect Blue
true
inspect Blue
destroy Blue
finished
```

`inspect` receives a const reference, so no copy is created. Moving `first`
transfers ownership to `second` and leaves `first` empty. The `Track` is
destroyed when `second`, its sole owner, leaves the inner scope.

Self-check: Can you explain the output without using the phrase “because that
is what `unique_ptr` does”?

## Question 2

The problems include the non-virtual base destructor, private inheritance,
the missing `const` on `Song::print`, storage of an abstract type by value, and
the value-based loop. One safe correction is:

```cpp
class MediaItem {
public:
    explicit MediaItem(std::string title) : title(std::move(title)) {}
    virtual ~MediaItem() = default;
    virtual void print() const = 0;

private:
    std::string title;
};

class Song : public MediaItem {
public:
    explicit Song(std::string title) : MediaItem(std::move(title)) {}
    void print() const override { std::cout << "song\n"; }
};

int main() {
    std::vector<std::unique_ptr<MediaItem>> items;
    items.push_back(std::make_unique<Song>("Morning"));
    for (const auto& item : items) item->print();
}
```

Self-check: For every correction, identify the compiler error or runtime risk
that it prevents.

## Question 3

```cpp
Playlist::Playlist(const std::string initialNames[], std::size_t count)
    : names(count == 0 ? nullptr : new std::string[count]), count(count) {
    for (std::size_t i = 0; i < count; ++i) names[i] = initialNames[i];
}

Playlist::Playlist(const Playlist& other)
    : names(other.count == 0 ? nullptr : new std::string[other.count]),
      count(other.count) {
    for (std::size_t i = 0; i < count; ++i) names[i] = other.names[i];
}

Playlist& Playlist::operator=(const Playlist& other) {
    if (this == &other) return *this;

    std::string* replacement =
        other.count == 0 ? nullptr : new std::string[other.count];
    for (std::size_t i = 0; i < other.count; ++i)
        replacement[i] = other.names[i];

    delete[] names;
    names = replacement;
    count = other.count;
    return *this;
}

Playlist::~Playlist() { delete[] names; }

const std::string& Playlist::operator[](std::size_t index) const {
    if (index >= count) throw std::out_of_range("playlist index");
    return names[index];
}

bool Playlist::operator==(const Playlist& other) const {
    if (count != other.count) return false;
    for (std::size_t i = 0; i < count; ++i)
        if (names[i] != other.names[i]) return false;
    return true;
}
```

Self-check: Test copying, assignment to a non-empty object, self-assignment,
empty playlists, independent modification, and invalid indexing.

## Question 4

```cpp
template <typename Iterator, typename Predicate>
std::size_t countMatching(Iterator begin, Iterator end, Predicate predicate) {
    std::size_t count = 0;
    for (; begin != end; ++begin)
        if (predicate(*begin)) ++count;
    return count;
}

std::vector<int> values{2, 9, 4, 12, 6};
int limit = 5;
std::size_t result = countMatching(
    values.begin(), values.end(),
    [limit](int value) { return value > limit; });
```

The function requires dereference, increment, and comparison. Vector and list
iterators provide those operations; random access is unnecessary.

Self-check: List the requirements on `Iterator` and `Predicate` directly from
the expressions in the function body.

## Question 5

`MediaItem` is an abstract base class. `Song` and `Podcast` publicly derive
from it. The library owns a polymorphic collection.

```cpp
class MediaItem {
public:
    explicit MediaItem(std::string title) : title(std::move(title)) {
        if (this->title.empty())
            throw std::invalid_argument("title must not be empty");
    }
    virtual ~MediaItem() = default;
    virtual void play() const = 0;

private:
    std::string title;
};

class Song : public MediaItem {
public:
    using MediaItem::MediaItem;
    void play() const override { std::cout << "Playing song\n"; }
};

class Podcast : public MediaItem {
public:
    using MediaItem::MediaItem;
    void play() const override { std::cout << "Playing podcast\n"; }
};

class Library {
    std::vector<std::unique_ptr<MediaItem>> items;

public:
    void add(std::unique_ptr<MediaItem> item) {
        if (!item) throw std::invalid_argument("item must not be null");
        items.push_back(std::move(item));
    }

    void playAll() const {
        for (const auto& item : items) item->play();
    }
};

Library library;
library.add(std::make_unique<Song>("Morning"));
```

Self-check: Explain why this design needs a virtual destructor, why ownership
is exclusive, and why `playAll` needs no test for the concrete object type.
