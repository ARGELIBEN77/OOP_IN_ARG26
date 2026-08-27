# Guided Exercises

Complete the exercises in order and run `make test` after each change.

## 1. Identify the owned resource

Which `Playlist` data member represents the dynamic resource? Which function
allocates it, and which function releases it?

## 2. Predict the shallow-copy bug

Imagine deleting the copy constructor and copy assignment operator. Draw two
Playlist objects after a compiler-generated shallow copy. Explain why their
destructors could call `delete[]` on the same address.

## 3. Trace the copy constructor

For a Playlist with three songs and capacity four, trace every initializer and
loop iteration in the copy constructor. Which values are copied, and which
address must be different?

## 4. Trace copy assignment

Explain why copy assignment must handle resources already owned by its left
operand. Then explain the purpose of:

```cpp
if (this == &other)
    return *this;
```

## 5. Verify deep-copy independence

Copy a Playlist, replace one song through `operator[]`, and print both objects.
Explain why the original must remain unchanged.

## 6. Grow the array

Create a Playlist with capacity two and add a third Song. Draw the old and new
arrays while `ensureCapacity` executes. Mark the moment ownership transfers to
the new array.

## 7. Comparison reuse

Explain why `Song::operator!=` calls `operator==` instead of comparing the data
members again. Add `operator>` by reusing `operator<`.

## 8. Stream design

Why is `operator<<` a non-member function? Why does it return
`std::ostream&`, and why does it not print an extra `std::endl`?

## 9. Const and non-const subscript

Explain why `Playlist` supplies two versions of `operator[]`. Demonstrate one
operation allowed on a non-const Playlist but rejected for a const Playlist.

## 10. Optional extension: combine playlists

Implement `Playlist& operator+=(const Playlist& other)`. Pay special attention
to `playlist += playlist`: the array may grow while it is also the source of
the songs being appended. Describe and test your solution.
