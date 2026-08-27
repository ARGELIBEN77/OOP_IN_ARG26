# Guided Exercises

Run `make compare` before beginning. Complete the exercises in order.

## 1. Compare the two designs

List the data and functions in `ProceduralSong.cpp`. Then identify which parts
became private data and which became public operations in `Song`.

## 2. Create invalid public state

In the procedural version, assign an empty title, a negative duration, and an
invalid rating. Why can the compiler not prevent these assignments?

## 3. Trace object construction

For this declaration:

```cpp
Song song("Imagine", "John Lennon", 183);
```

Trace the constructor arguments and every member initializer. What value is
given to `rating`, and why is the initializer list preferable to assignment in
the constructor body?

## 4. Classify member functions

For every public `Song` method, state whether it observes or modifies the
object. Verify that all observing methods are marked `const`.

## 5. Controlled modification

Test `setRating` with `1`, `5`, `0`, and `6`. Record the returned value and the
rating stored after each call. Why is this safer than a public `rating` field?

## 6. Add a new calculated method

Implement:

```cpp
bool isLongSong() const;
```

Define a long song as one lasting at least four minutes. Add tests for values
just below, exactly at, and just above the boundary.

## 7. Add controlled title modification

Implement `bool setTitle(const std::string& newTitle)`. Reject an empty title
and preserve the previous title when the request is invalid.

## 8. Const-reference reasoning

Explain why `printSong` receives `const Song&` instead of `Song`. What copy
would occur with pass-by-value, and what modification does `const` prevent?

## 9. Header and implementation separation

Move one method body temporarily into `Song.hpp`, compile, and then restore it.
Explain what information belongs in the declaration and what belongs in the
implementation file.

## 10. Design a second class

Design a small `Album` class declaration with private title and year fields.
Provide a constructor, getters, one calculated `const` method, and one
controlled modifying method. Do not add a collection of Songs yet; composition
belongs to the next project.
