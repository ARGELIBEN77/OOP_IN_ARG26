# Complete-Course Review Bank

Use this question bank to review individual topics before attempting a full
practice examination. The questions are arranged by unit, so you can begin
with a topic that needs more work or complete the bank in course order.

Try each tracing question on paper before running the code. For programming
questions, write and test a complete solution unless the question asks only
for declarations or an explanation. Use C++17. Solutions are kept separately.

## Unit 1

### Question 1.1 — Redesign a record

*Suggested time: 15 minutes*  
**Your answer should include:** A class declaration and a short explanation.

The following record allows any part of a program to create an invalid song:

```cpp
struct SongRecord {
    std::string title;
    std::string artist;
    int durationSeconds;
};
```

Replace `SongRecord` with a `Song` class. The title and artist must not be
empty, and the duration must be positive. Keep all data members private and
provide the operations needed to construct a song and read its details.

After writing the class declaration, give two examples of invalid objects that
could be created with `SongRecord` but are prevented by your `Song` interface.

### Question 1.2 — Separate the class

*Suggested time: 15 minutes*  
**Your answer should include:** `Song.hpp`, `Song.cpp`, and a short `main.cpp`.

Separate your class from Task 1.1 into declaration and implementation files.
In `main`, construct two valid songs and print their details using public
operations only. Include suitable header guards.

## Unit 2

### Question 2.1 — Protect an invariant

*Suggested time: 15 minutes*  
**Your answer should include:** The completed class and two test cases.

Complete the constructor and `changeRating` so that `rating` always remains
between 1 and 5. Do not add a public setter for either data member.

```cpp
class Review {
private:
    std::string text;
    int rating;

public:
    Review(const std::string& text, int rating);
    void changeRating(int newRating);
    int getRating() const;
    const std::string& getText() const;
};
```

For this question, an invalid rating should leave the object unchanged. Write
one test using a valid new rating and one using an invalid new rating. Finally,
explain why client code cannot assign an arbitrary value directly to
`rating`.

### Question 2.2 — Check `const` correctness

*Suggested time: 10 minutes*  
**Your answer should include:** Corrected declarations and one sentence for every change.

Some of the following functions below are incorrectly declared. Rewrite the
four declarations, adding or removing `const` where necessary.

```cpp
class Playlist {
public:
    std::size_t size();
    const Song& at(std::size_t position);
    void add(const Song& song) const;
    void print(std::ostream& output);
};
```

The corrected observer functions must be callable through a
`const Playlist&`. A function that changes the playlist must not be declared
`const`.

## Unit 3

### Question 3.1 — Select constructors

*Suggested time: 15 minutes*  
**Your answer should include:** The completed class and the selected constructor for each line.

Add a default constructor and a constructor that receives a course code and a
capacity. A default course has code `"UNKNOWN"` and capacity 30. Initialize
members with initializer lists. Avoid repeating the initialization logic by
delegating from one constructor to the other.

```cpp
class Course {
private:
    std::string code;
    int capacity;

public:
    // Add constructors here.
};

Course first;
Course second("CPP101", 40);
Course third{};
Course fourth{"OOP201", 25};
```

For each of the four declarations, write which constructor is called and give
the final values of `code` and `capacity`.

### Question 3.2 — Find the initialization error

*Suggested time: 10 minutes*  
**Your answer should include:** Corrected code and an explanation.

```cpp
class Registration {
private:
    const int registrationNumber;
    Student& student;

public:
    Registration(int number, Student& selectedStudent) {
        registrationNumber = number;
        student = selectedStudent;
    }
};
```

The compiler rejects this constructor. Explain separately why assignment does
not work for `registrationNumber` and why it does not initialize the
`student` reference. Then rewrite the constructor correctly.

## Unit 4

### Question 4.1 — Trace object lifetime

*Suggested time: 15 minutes*  
**Your answer should include:** The exact output order and an explanation.

```cpp
class Track {
private:
    std::string name;

public:
    Track(const std::string& name) : name(name) {
        std::cout << "construct " << name << '\n';
    }

    ~Track() {
        std::cout << "destroy " << name << '\n';
    }
};

int main() {
    Track first("first");
    {
        Track second("second");
        Track third("third");
    }
    Track fourth("fourth");
}
```

Predict the complete output before running the program. Explain the rule that
determines the destruction order.

### Question 4.2 — Compare automatic and dynamic lifetime

*Suggested time: 15 minutes*  
**Your answer should include:** The output order, the corrected program, and an explanation.

```cpp
int main() {
    Track local("local");
    Track* dynamicTrack = new Track("dynamic");
    std::cout << "end of work\n";
}
```

Write the output produced by the program and identify the object whose
destructor is never called. Correct the program using `delete`, then write the
new output and explain when each destructor runs.

## Unit 5

### Question 5.1 — Model relationships

*Suggested time: 20 minutes*  
**Your answer should include:** A UML class diagram and a short justification.

A university stores `Student` and `Course` objects independently. A
`Registration` connects one existing student with one existing course. If a
registration is removed, neither the student nor the course is destroyed.
A `Course` owns a collection of `Lesson` objects; its lessons do not exist
independently of that course.

Draw the classes, multiplicities, and relationships. Identify which
relationship is an association and which is a composition, and justify both.

### Question 5.2 — Pass and return objects

*Suggested time: 15 minutes*  
**Your answer should include:** Corrected signatures and explanations.

```cpp
void printStudent(Student student);
bool sameCourse(Course first, Course second);
Student& createStudent(const std::string& name);
```

Assume that printing and comparison must neither copy nor modify their
arguments. Rewrite the first two declarations accordingly.

Assume that `createStudent` constructs a local `Student` and returns the new
object to its caller. Correct its return type and explain why returning
`Student&` would leave the caller with an invalid reference.

### Question 5.3 — Share class-level information

*Suggested time: 15 minutes*  
**Your answer should include:** The missing declarations and definitions.

Every `Student` object has its own name, but all students share one counter
that records how many `Student` objects have been constructed. Add a static
data member and a static function named `getStudentCount`. Increment the
counter in the constructors.

Define the short `getStudentCount` function inside the class. Explain why the
counter is static and why this short function is a reasonable inline
candidate.

## Unit 6

### Question 6.1 — Complete the Rule of Three

*Suggested time: 30 minutes*  
**Your answer should include:** The three missing member implementations and two tests.

```cpp
class IntBuffer {
private:
    int* data;
    std::size_t length;

public:
    explicit IntBuffer(std::size_t length)
        : data(new int[length]{}), length(length) {}
    IntBuffer(const IntBuffer& other);
    IntBuffer& operator=(const IntBuffer& other);
    ~IntBuffer();

    int& operator[](std::size_t position);
    const int& operator[](std::size_t position) const;
    std::size_t size() const;
};
```

Implement the copy constructor, copy-assignment operator, and destructor. A
copied buffer must own a separate array containing the same values. The
assignment operator must also work when an object is assigned to itself.

Write one test that changes a copied buffer and verifies that the original did
not change. Write a second test for self-assignment.

### Question 6.2 — Choose operator forms

*Suggested time: 20 minutes*  
**Your answer should include:** Operator declarations and brief justifications.

For a `Fraction` class, declare:

1. equality between two fractions;
2. addition that produces a new fraction;
3. `+=`, which modifies the left operand;
4. stream insertion using `std::ostream`.

Choose member or non-member form for each operator. Ensure that expressions
using `const Fraction` objects remain valid where appropriate.

## Unit 7

### Question 7.1 — Repair a hierarchy

*Suggested time: 20 minutes*  
**Your answer should include:** Corrected code and five identified problems.

```cpp
class MediaItem {
public:
    void play() const { std::cout << "media\n"; }
    ~MediaItem() = default;
};

class Song : private MediaItem {
public:
    void play() { std::cout << "song\n"; }
};

void preview(MediaItem item) {
    item.play();
}

int main() {
    MediaItem* item = new Song();
    preview(*item);
    delete item;
}
```

The program contains five hierarchy-related mistakes. Correct:

1. the inheritance access;
2. the lost polymorphism in `preview`;
3. the signature of `Song::play`;
4. the declaration needed for dynamic dispatch; and
5. destruction through a base-class pointer.

Use `override` in `Song`. Briefly explain each correction.

### Question 7.2 — Explain binding

*Suggested time: 15 minutes*  
**Your answer should include:** The predicted output and an explanation using static and dynamic type.

```cpp
class Base {
public:
    void first() const { std::cout << "Base first\n"; }
    virtual void second() const { std::cout << "Base second\n"; }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void first() const { std::cout << "Derived first\n"; }
    void second() const override { std::cout << "Derived second\n"; }
};

int main() {
    Derived object;
    Base& reference = object;
    reference.first();
    reference.second();
}
```

Predict both lines and explain why the two calls behave differently.

## Unit 8

### Question 8.1 — Complete an abstract interface

*Suggested time: 20 minutes*  
**Your answer should include:** Completed declarations and a processing function.

Declare an abstract class named `Notification`. It must have a pure virtual
`send() const` function and a virtual destructor. Derive
`EmailNotification` and `SmsNotification` from it, and override `send` in
both classes. Then implement:

```cpp
void sendAll(const std::vector<Notification*>& notifications);
```

The function must call `send` for every notification. Do not use
`dynamic_cast`, a type flag, or a chain of `if` statements. Add a third
notification class and show that `sendAll` itself does not need to change.

### Question 8.2 — Identify abstract and concrete classes

*Suggested time: 15 minutes*  
**Your answer should include:** Answers for A–D with explanations.

```cpp
class Shape {
public:
    virtual double area() const = 0;
    virtual void print() const { std::cout << "shape\n"; }
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    double area() const override { return 12.56; }
};

class LabelledShape : public Shape {
public:
    void print() const override { std::cout << "labelled\n"; }
};
```

For each class, state whether it is abstract or concrete. Then determine which
of these declarations compile: (A) `Shape shape;` (B) `Circle circle;`
(C) `LabelledShape labelled;` (D) `Shape& view = circle;`.

## Unit 9

### Question 9.1 — Trace propagation and unwinding

*Suggested time: 20 minutes*  
**Your answer should include:** The exact output order and the final value of `copies`.

```cpp
class Trace {
private:
    std::string name;

public:
    Trace(const std::string& name) : name(name) {
        std::cout << "enter " << name << '\n';
    }

    ~Trace() {
        std::cout << "leave " << name << '\n';
    }
};

void load(int& copies) {
    Trace trace("load");
    ++copies;
    throw std::runtime_error("file unavailable");
}

void prepare(int& copies) {
    Trace trace("prepare");
    load(copies);
}

int main() {
    int copies = 0;
    try {
        Trace trace("try");
        prepare(copies);
    } catch (const std::exception& error) {
        std::cout << error.what() << '\n';
    }
    std::cout << copies << '\n';
}
```

Predict the complete output before compiling. Explain stack unwinding.

### Question 9.2 — Preserve object state

*Suggested time: 20 minutes*  
**Your answer should include:** A custom exception, the completed operation, and three tests.

A `BankAccount::withdraw(double amount)` function must reject a non-positive
amount and an amount greater than the current balance. Define a custom
exception derived from `std::runtime_error`. It must also store the amount
that caused the error.

Implement `withdraw` so that the balance changes only after all checks have
passed. Test a successful withdrawal, a non-positive amount, and an amount
greater than the balance. Catch the exceptions by `const` reference and
verify that each failed withdrawal leaves the original balance unchanged.

### Question 9.3 — Order catch handlers correctly

*Suggested time: 10 minutes*  
**Your answer should include:** The corrected handlers and an explanation.

```cpp
try {
    loadCatalogue();
} catch (const std::exception& error) {
    std::cout << "general error: " << error.what() << '\n';
} catch (const std::out_of_range& error) {
    std::cout << "invalid position: " << error.what() << '\n';
}
```

Assume that `loadCatalogue` may throw `std::out_of_range`. Explain why the
second handler cannot deal with that exception separately in the code above.
Reorder the handlers so that the more specific case is handled first.

## Unit 10

### Question 10.1 — Complete a function template

*Suggested time: 15 minutes*  
**Your answer should include:** The template and three calls.

Write a function template `larger` that receives two `const` references and
returns a `const` reference to the larger value. Test it with named variables
of types `int`, `double`, and `std::string`. Do not pass temporary objects
in these tests. State which comparison operation a type must provide for use
with this function.

### Question 10.2 — Use a simple iterator

*Suggested time: 25 minutes*  
**Your answer should include:** Completed iterator operations and two searches.

The following iterator walks through a contiguous sequence:

```cpp
template<typename T>
class SimpleIterator {
private:
    T* current;

public:
    explicit SimpleIterator(T* position) : current(position) {}

    T& operator*() const;
    SimpleIterator& operator++();
    bool operator!=(const SimpleIterator& other) const;
};
```

Implement the three operations. Use a pair of these iterators in a loop to
print this array:

```cpp
int values[] = {3, 8, 11, 14, 19};
```

Write a small function template named `findFirst` that receives a beginning
iterator, an ending iterator, and a predicate. It should return an iterator to
the first matching value, or the ending iterator if there is no match.

Use `findFirst` to find the first even value with a named functor. Use it
again to find the first value greater than a captured `limit` with a lambda.
This is a deliberately simple educational iterator; do not add
`std::iterator_traits` machinery.

### Question 10.3 — Complete a class template

*Suggested time: 20 minutes*  
**Your answer should include:** A complete class template and two tests.

Write a class template named `Pair` that stores two values of the same type.
Its constructor receives both values. Provide `getFirst`, `getSecond`, and
`swapValues`. The two observer functions must be callable on a `const Pair`.

Create and test a `Pair<int>` and a `Pair<std::string>`. Explain why the
complete template definition belongs in the header file.

## Unit 11

### Question 11.1 — Select an ownership model

*Suggested time: 15 minutes*  
**Your answer should include:** One choice and justification for each scenario.

Choose a direct object, `std::unique_ptr`, or `std::shared_ptr`:

1. A `Car` always contains exactly one `Engine`, and the engine cannot
   outlive the car.
2. A media library owns polymorphic `MediaItem` objects; each item has
   exactly one owner but ownership may be transferred.
3. Several active `Playlist` objects share the same dynamically created
   `Song`, which must remain alive until the final playlist releases it.

Explain the lifetime represented by every choice.

### Question 11.2 — Trace move and shared ownership

*Suggested time: 20 minutes*  
**Your answer should include:** The owner and reference count after every numbered line.

```cpp
auto first = std::make_unique<Song>("Blue");        // 1
std::unique_ptr<Song> second = std::move(first);    // 2

auto sharedFirst = std::make_shared<Song>("Gold");  // 3
auto sharedSecond = sharedFirst;                    // 4
sharedFirst.reset();                                // 5
```

After lines 1 and 2, state whether `first` and `second` are empty and identify
the owner of `"Blue"`. After each of lines 3, 4, and 5, give the reference
count for `"Gold"` and state whether that object is still alive. Explain why
a `unique_ptr` cannot be copied but can be moved.

### Question 11.3 — Implement exclusive ownership

*Suggested time: 30 minutes*  
**Your answer should include:** The completed class and three tests.

The class below is a small educational version of `unique_ptr`. It is not a
replacement for the standard-library class.

```cpp
template<typename T>
class UniquePointer {
private:
    T* pointer;

public:
    explicit UniquePointer(T* pointer = nullptr) : pointer(pointer) {}

    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    UniquePointer(UniquePointer&& other) noexcept;
    UniquePointer& operator=(UniquePointer&& other) noexcept;
    ~UniquePointer();

    T& operator*() const;
    T* operator->() const;
    T* get() const;
};
```

Implement the move constructor, move-assignment operator, destructor, and
access operations. After a move, the source pointer must be empty. Moving onto
an existing `UniquePointer` must first release the object it currently owns.

Test destruction, move construction, and move assignment. Explain briefly why
the copy operations are deleted.

## Unit 12

### Question 12.1 — Choose a standard container

*Suggested time: 20 minutes*  
**Your answer should include:** A container choice and justification for each requirement.

Choose among `std::vector`, `std::list`, `std::set`, and `std::map`:

1. Songs remain in insertion order and are frequently accessed by position.
2. A catalogue associates each unique integer identifier with one `Product`.
3. A collection stores each username once and keeps usernames ordered.
4. A long sequence frequently inserts and removes elements through existing
   iterators; random access is not required.

Justify each answer using access, lookup, ordering, uniqueness, iterator
behavior, or modification cost as relevant.

### Question 12.2 — Apply algorithms and callables

*Suggested time: 25 minutes*  
**Your answer should include:** Four algorithm calls; do not write manual loops.

```cpp
struct Product {
    std::string name;
    double price;
};

std::vector<Product> products = {
    {"Notebook", 12.5},
    {"Pen", 4.0},
    {"Backpack", 90.0},
    {"Marker", 7.5}
};
```

Write four independent statements using standard algorithms and suitable
lambdas. Do not replace an algorithm with a handwritten loop.

1. sort by increasing price;
2. find the first product whose name is `"Pen"`;
3. count products costing at most a captured limit;
4. print every product without changing it.

## Unit 13

### Question 13.1 — Integrated media catalogue

*Suggested time: 60 minutes*  
**Your answer should include:** A UML sketch, essential class declarations, implementation of the
specified operation, and tests.

Design a small media catalogue. The catalogue stores songs and podcast
episodes through a common abstract `MediaItem` interface. Every media item has
a title and a unique integer identifier.

Your design must:

- own items without manual `delete`;
- support runtime-polymorphic printing;
- reject duplicate identifiers with a custom exception;
- find an item by identifier efficiently;
- print only items accepted by a caller-provided predicate;
- transfer ownership of a newly created item into the catalogue.

Begin with a small UML diagram and the essential class declarations. Choose a
smart pointer and an STL container, and justify both choices. Then implement
the catalogue operation that adds an item, including duplicate detection.

Finally, provide tests for successful insertion, duplicate rejection,
polymorphic printing, and ownership transfer. State what the caller's predicate
must be able to accept and return.

## How to use this bank

1. Choose one unit rather than trying to complete the entire bank at once.
2. Work without the lecture notes for the suggested time.
3. Write down tracing predictions before compiling.
4. Compile and test every programming answer.
5. If your answer is incomplete, return to the corresponding unit and project.
6. Write down what went wrong, then try the question again on another day.
