# Practice Examination — Solutions and Marking Guide

This guide corresponds to the
[`Practice Examination`](../../Units/Unit_13/PRACTICE_EXAM.md). Equivalent
correct C++ designs should receive credit.

## Question 1 (20 points)

```text
create Blue
inspect Blue
true
inspect Blue
destroy Blue
finished
```

`inspect` receives a const reference and therefore aliases the object rather
than copying it. Moving `first` transfers ownership to `second` and leaves
`first` empty. The object is destroyed when `second`, its sole owner, leaves
the inner scope.

Allocate 8 points for the output and 4 points for each explanation.

## Question 2 (20 points)

The errors include a non-virtual base destructor, private inheritance, a
non-const `Song::print` that does not override the base operation, attempting
to store an abstract type by value, and a value-based loop that would slice or
copy. Four correctly explained errors earn 12 points.

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
    for (const auto& item : items) {
        item->print();
    }
}
```

Award 8 points for a coherent safe correction.

## Question 3 (25 points)

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
    for (std::size_t i = 0; i < other.count; ++i) {
        replacement[i] = other.names[i];
    }

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
    for (std::size_t i = 0; i < count; ++i) {
        if (names[i] != other.names[i]) return false;
    }
    return true;
}
```

Allocate 17 points for resource ownership and copying, 4 for checked indexing,
and 4 for equality. Copy-and-swap is equally valid.

## Question 4 (15 points)

```cpp
template <typename Iterator, typename Predicate>
std::size_t countMatching(Iterator begin, Iterator end, Predicate predicate) {
    std::size_t count = 0;
    for (; begin != end; ++begin) {
        if (predicate(*begin)) ++count;
    }
    return count;
}

std::vector<int> values{2, 9, 4, 12, 6};
int limit = 5;
std::size_t result = countMatching(
    values.begin(), values.end(),
    [limit](int value) { return value > limit; });
```

The algorithm uses only dereference, increment and comparison. Both vector and
list iterators support these operations; random access is unnecessary.

## Question 5 (20 points)

`MediaItem` is an abstract base. `Song` and `Podcast` publicly derive from it.
`Library` exclusively owns its media items.

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

Allocate 5 points for relationships, 5 for the justified ownership/container
choice, 8 for declarations and operations, and 2 for the transfer call.

