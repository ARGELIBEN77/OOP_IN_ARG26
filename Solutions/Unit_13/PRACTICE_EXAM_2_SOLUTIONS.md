# Practice Examination 2 — Solutions and Self-Check Guide

Attempt the examination under timed conditions before reading this guide.
Equivalent correct designs are possible.

## Question 1

```text
+first
+first copy
+local
-local
-first copy
-first
stop
```

Passing by value invokes the copy constructor. During unwinding, `local`, the
parameter copy, and then `first` are destroyed in reverse construction order.
The replacement parameter is `const Note& note`.

## Question 2

`Registration` associates one `Student` with one `Course`; each student and
course can participate in many registrations. They remain independent.

```cpp
class Registration {
    const Student& student;
    const Course& course;
    double grade;
    inline static std::size_t count = 0;

public:
    Registration(const Student& student, const Course& course, double grade)
        : student(student), course(course), grade(grade) {
        if (grade < 0 || grade > 100)
            throw std::invalid_argument("grade must be in [0, 100]");
        ++count;
    }

    ~Registration() { --count; }
    double getGrade() const { return grade; }
    static std::size_t getCount() { return count; }
};
```

If copying is permitted, the copy constructor must also update the counter.

## Question 3

Allocation must use `new int[size]`, destruction must use `delete[]`, and copy
operations must perform deep copies. A checked non-const subscript returns
`int&`; the const version returns `const int&`. Both throw when `index >= size`.
Stream insertion is a non-member receiving `const Scores&`; it writes each
value and returns `std::ostream&`.

Self-check empty storage, self-assignment, independent copies, invalid index,
and destruction with a memory checker.

## Question 4

A correct solution has a node storing `T` and a next pointer, a list maintaining
first and last pointers, and an iterator storing the current node. `begin()`
points to the first node and `end()` contains `nullptr`.

```cpp
template <typename Iterator, typename Action>
void forEach(Iterator begin, Iterator end, Action action) {
    for (; begin != end; ++begin) action(*begin);
}

int limit = 10;
std::size_t count = 0;
forEach(history.begin(), history.end(), [&](const auto& value) {
    if (value > limit) ++count;
});
```

`add` requires construction or copying of `T`. The iterator requires
dereference, prefix increment, and inequality.

## Question 5

A typical design uses `vector<unique_ptr<MediaItem>>` for exclusive
polymorphic ownership, `set<string>` for unique sorted genres, and
`vector<shared_ptr<Song>>` inside each playlist.

Exclusive and shared smart pointers must not manage the same raw object
independently. A song shared by playlists should be created under
`shared_ptr`; the service must share it too or own a separate media object.

Use `find_if` with a title-comparing lambda, check against `end()`, and throw
`std::out_of_range` or a domain exception when absent. A shared song is
destroyed after the final owner releases it. Destroying one playlist decreases
the count for each shared song it held.

Self-check by drawing the ownership graph. Every object needs one consistent
ownership strategy.

