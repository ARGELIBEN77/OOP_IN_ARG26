# Practice Examination 2

**Duration:** 180 minutes  
**Total:** 100 points  
**Language standard:** C++17

## Instructions

- Answer every question and justify design choices briefly.
- Assume required standard headers are included unless stated otherwise.
- Code must compile in C++17 and preserve valid object state.
- When predicting output, include the complete order and explanation.

## Question 1 (20 points)

```cpp
class Note {
    std::string text;

public:
    explicit Note(std::string text) : text(std::move(text)) {
        std::cout << "+" << this->text << '\n';
    }
    Note(const Note& other) : text(other.text + " copy") {
        std::cout << "+" << text << '\n';
    }
    ~Note() { std::cout << "-" << text << '\n'; }
};

void process(Note note) {
    Note local("local");
    throw std::runtime_error("stop");
}

int main() {
    try {
        Note first("first");
        process(first);
    } catch (const std::exception& error) {
        std::cout << error.what() << '\n';
    }
}
```

- Write the exact output. (10 points)
- Explain each copy and the destruction order during stack unwinding. (6 points)
- Change only the parameter declaration of `process` to avoid the copy while
  preventing modification of the argument. (4 points)

## Question 2 (20 points)

A college system contains `Student`, `Course`, and `Registration`. A student
and course exist independently. A registration connects exactly one existing
student with one existing course and stores a grade. The system must count how
many `Registration` objects currently exist.

- Draw a UML class diagram including multiplicities. (7 points)
- Choose the relationships and explain why `Student` and `Course` are not
  related by composition. (5 points)
- Declare the essential members, a validating constructor, one `const`
  observer, and a static counter operation for `Registration`. (8 points)

## Question 3 (20 points)

```cpp
class Scores {
    int* values;
    std::size_t size;

public:
    Scores(std::size_t size) : values(new int(size)), size(size) {}
    Scores(const Scores&) = default;
    Scores& operator=(const Scores&) = default;
    ~Scores() { delete values; }
    int operator[](std::size_t index) const { return values[index]; }
};
```

- Identify and correct every resource-management error. (10 points)
- Implement const and non-const checked subscript operators. (6 points)
- Implement stream insertion that prints values without changing the object.
  (4 points)

## Question 4 (20 points)

Design a class template `History<T>` that stores values in a simple linked
structure and supports adding at the end, `begin()`, `end()`, and traversal in
a range-based loop.

- Write the essential class, node, and iterator declarations and
  implementations. The iterator needs dereference, prefix increment, and
  inequality. (12 points)
- State the operations required from `T` by `add`. (3 points)
- Write a generic `forEach` and call it with a capturing lambda that counts
  values satisfying a condition. (5 points)

## Question 5 (20 points)

A media service owns media items polymorphically. It also keeps unique genre
names and allows playlists to share selected songs.

- Select suitable STL container and element types for all three collections.
  Justify ordering, uniqueness, lookup, and ownership. (7 points)
- Show how a song is created and transferred into the service, and explain how
  songs shared by playlists require a consistent ownership model. (5 points)
- Use an STL algorithm and lambda to find a title. Handle a missing title by
  throwing and catching a suitable exception. (5 points)
- Explain when a shared song is destroyed and how destroying one playlist
  changes its reference count. (3 points)
