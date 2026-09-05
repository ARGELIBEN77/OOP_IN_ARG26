# Complete-Course Review Bank

This bank helps you practise the complete course before attempting a timed
examination. The questions are grouped by unit so that you can work on a
specific area. They do not include solutions.

For code questions, first answer without compiling. Afterwards, compile the
code to check your reasoning. Unless a question says otherwise, use C++17.

## Unit 1

### Task 1.1 — Redesign a record

**Estimated time:** 15 minutes  
**Submit:** A class declaration and a short explanation.

The following record allows any part of a program to create an invalid song:

```cpp
struct SongRecord {
    std::string title;
    std::string artist;
    int durationSeconds;
};
```

Replace it with a `Song` class. Keep the state private and provide only the
operations needed to create a song and read its data. A title and artist must
not be empty, and the duration must be positive. State two invalid situations
that client code can create with `SongRecord` but cannot create with `Song`.

### Task 1.2 — Separate the class

**Estimated time:** 15 minutes  
**Submit:** `Song.hpp`, `Song.cpp`, and a short `main.cpp`.

Separate your class from Task 1.1 into declaration and implementation files.
In `main`, construct two valid songs and print their details using public
operations only. Include suitable header guards.

## Unit 2

### Task 2.1 — Protect an invariant

**Estimated time:** 15 minutes  
**Submit:** The completed class and two test cases.

Complete this class so that `rating` always remains between 1 and 5:

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

For this exercise, reject an invalid rating by leaving the object unchanged.
Write one test for a valid modification and one for an invalid modification.
Explain why client code cannot bypass the validation.

### Task 2.2 — Check `const` correctness

**Estimated time:** 10 minutes  
**Submit:** Corrected declarations and one sentence for every change.

Correct the declarations that should be usable through a `const Playlist&`:

```cpp
class Playlist {
public:
    std::size_t size();
    const Song& at(std::size_t position);
    void add(const Song& song) const;
    void print(std::ostream& output);
};
```

Do not change a function to `const` if it logically modifies the playlist.

## Unit 3

### Task 3.1 — Select constructors

**Estimated time:** 15 minutes  
**Submit:** The completed class and the selected constructor for each line.

Complete `Course` with a default constructor and a parameterized constructor.
The default course has code `"UNKNOWN"` and capacity 30. Use initializer lists
and delegate from one constructor to the other where appropriate.

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

For each declaration, identify the selected constructor and the final member
values.

### Task 3.2 — Find the initialization error

**Estimated time:** 10 minutes  
**Submit:** Corrected code and an explanation.

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

Explain why the constructor does not correctly initialize its members and
rewrite it using an initializer list.

## Unit 4

### Task 4.1 — Trace object lifetime

**Estimated time:** 15 minutes  
**Submit:** The exact output order and an explanation.

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

### Task 4.2 — Compare automatic and dynamic lifetime

**Estimated time:** 15 minutes  
**Submit:** The output order, the corrected program, and an explanation.

```cpp
int main() {
    Track local("local");
    Track* dynamicTrack = new Track("dynamic");
    std::cout << "end of work\n";
}
```

Predict the output and identify the resource-management error. Correct the
program using the techniques available at this point in the course. Explain
when each destructor executes in the corrected version.

## Unit 5

### Task 5.1 — Model relationships

**Estimated time:** 20 minutes  
**Submit:** A UML class diagram and a short justification.

A university stores `Student` and `Course` objects independently. A
`Registration` connects one existing student with one existing course. If a
registration is removed, neither the student nor the course is destroyed.
A `Course` owns a collection of `Lesson` objects; its lessons do not exist
independently of that course.

Draw the classes, multiplicities, and relationships. Identify which
relationship is an association and which is a composition, and justify both.

### Task 5.2 — Pass and return objects

**Estimated time:** 15 minutes  
**Submit:** Corrected signatures and explanations.

```cpp
void printStudent(Student student);
bool sameCourse(Course first, Course second);
Student& createStudent(const std::string& name);
```

Assume printing and comparison must not copy or modify their arguments.
Correct the first two signatures. The third function creates a local `Student`
and attempts to return it; choose a safe return type and explain why returning
a reference would be incorrect.

## Unit 6

### Task 6.1 — Complete the Rule of Three

**Estimated time:** 30 minutes  
**Submit:** The three missing member implementations and two tests.

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

Implement the copy constructor, copy-assignment operator, and destructor.
Copies must own independent arrays. Assignment must be safe for self-assignment.
Write tests that demonstrate deep copying and self-assignment.

### Task 6.2 — Choose operator forms

**Estimated time:** 20 minutes  
**Submit:** Operator declarations and brief justifications.

For a `Fraction` class, declare:

1. equality between two fractions;
2. addition that produces a new fraction;
3. `+=`, which modifies the left operand;
4. stream insertion using `std::ostream`.

Choose member or non-member form for each operator. Ensure that expressions
using `const Fraction` objects remain valid where appropriate.

## Unit 7

### Task 7.1 — Repair a hierarchy

**Estimated time:** 20 minutes  
**Submit:** Corrected code and five identified problems.

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

Correct the inheritance access, slicing, signature mismatch, missing virtual
dispatch, and unsafe destruction. Use `override` in the derived class.

### Task 7.2 — Explain binding

**Estimated time:** 15 minutes  
**Submit:** The predicted output and an explanation using static and dynamic type.

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

### Task 8.1 — Complete an abstract interface

**Estimated time:** 20 minutes  
**Submit:** Completed declarations and a processing function.

Create an abstract `Notification` class with a pure virtual
`send() const` operation and a virtual destructor. Implement
`EmailNotification` and `SmsNotification`. Then write:

```cpp
void sendAll(const std::vector<Notification*>& notifications);
```

The function must process every object polymorphically and must not use type
tests. Show that a third notification type can be added without modifying
`sendAll`.

### Task 8.2 — Identify abstract and concrete classes

**Estimated time:** 15 minutes  
**Submit:** Answers for A–D with explanations.

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

### Task 9.1 — Trace propagation and unwinding

**Estimated time:** 20 minutes  
**Submit:** The exact output order and the final value of `copies`.

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

### Task 9.2 — Preserve object state

**Estimated time:** 20 minutes  
**Submit:** A custom exception, the completed operation, and three tests.

A `BankAccount::withdraw(double amount)` operation must reject non-positive
amounts and withdrawals larger than the balance. Define an exception class
that records the attempted amount. Implement `withdraw` so a failed operation
leaves the balance unchanged. Test a successful withdrawal and both failures.
Catch exceptions by `const` reference.

## Unit 10

### Task 10.1 — Complete a function template

**Estimated time:** 15 minutes  
**Submit:** The template and three calls.

Write a function template `larger` that returns a `const` reference to the
larger of two values. Demonstrate it with `int`, `double`, and
`std::string`. State the operation that a type must support for use with this
template.

### Task 10.2 — Use a simple iterator

**Estimated time:** 25 minutes  
**Submit:** Completed iterator operations and two searches.

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

Then use `std::find_if` to find the first even value with a named functor.
Use `std::find_if` again to find the first value greater than a captured
`limit` with a lambda. Do not add `std::iterator_traits` machinery.

## Unit 11

### Task 11.1 — Select an ownership model

**Estimated time:** 15 minutes  
**Submit:** One choice and justification for each scenario.

Choose a direct object, `std::unique_ptr`, or `std::shared_ptr`:

1. A `Car` always contains exactly one `Engine`, and the engine cannot
   outlive the car.
2. A media library owns polymorphic `MediaItem` objects; each item has
   exactly one owner but ownership may be transferred.
3. Several active `Playlist` objects share the same dynamically created
   `Song`, which must remain alive until the final playlist releases it.

Explain the lifetime represented by every choice.

### Task 11.2 — Trace move and shared ownership

**Estimated time:** 20 minutes  
**Submit:** The owner and reference count after every numbered line.

```cpp
auto first = std::make_unique<Song>("Blue");        // 1
std::unique_ptr<Song> second = std::move(first);    // 2

auto sharedFirst = std::make_shared<Song>("Gold");  // 3
auto sharedSecond = sharedFirst;                    // 4
sharedFirst.reset();                                // 5
```

For lines 1–2, state which pointer owns the song and which pointer is empty.
For lines 3–5, state `use_count()` and whether the shared song is still alive.
Explain why copying the first smart pointer is forbidden but moving it is valid.

## Unit 12

### Task 12.1 — Choose a standard container

**Estimated time:** 20 minutes  
**Submit:** A container choice and justification for each requirement.

Choose among `std::vector`, `std::list`, `std::set`, and `std::map`:

1. Songs remain in insertion order and are frequently accessed by position.
2. A catalogue associates each unique integer identifier with one `Product`.
3. A collection stores each username once and keeps usernames ordered.
4. A long sequence frequently inserts and removes elements through existing
   iterators; random access is not required.

Justify each answer using access, lookup, ordering, uniqueness, iterator
behavior, or modification cost as relevant.

### Task 12.2 — Apply algorithms and callables

**Estimated time:** 25 minutes  
**Submit:** Four algorithm calls; do not write manual loops.

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

Use standard algorithms and suitable lambdas to:

1. sort by increasing price;
2. find the first product whose name is `"Pen"`;
3. count products costing at most a captured limit;
4. print every product without changing it.

## Unit 13

### Task 13.1 — Integrated media catalogue

**Estimated time:** 60 minutes  
**Submit:** A UML sketch, essential class declarations, implementation of the
specified operation, and tests.

Design a catalogue that owns songs and podcast episodes through one abstract
`MediaItem` interface. Every item has a unique integer identifier and a
title. The catalogue must:

- own items without manual `delete`;
- support runtime-polymorphic printing;
- reject duplicate identifiers with a custom exception;
- find an item by identifier efficiently;
- print only items accepted by a caller-provided predicate;
- transfer ownership of a newly created item into the catalogue.

Choose appropriate smart pointers and STL containers. Implement the operation
that adds an item, including its failure behavior. Provide tests for successful
insertion, duplicate rejection, polymorphic printing, and correct ownership
transfer. State the requirements imposed on the predicate.

## How to use this bank

1. Select the unit you want to review.
2. Work within the estimated time without consulting the lecture notes.
3. Compile and test code only after recording your initial answer.
4. Revisit the corresponding unit and project when your result is incomplete.
5. Record the mistake and the principle that corrects it.
6. Attempt the same task again later without looking at your first solution.
