# Guided Exercises

Complete the exercises in order. Rebuild and test after every change.

## 1. Identify inheritance roles

For each class, state whether it is a base class, derived class, abstract class,
or concrete class. A class may have more than one role.

## 2. Trace construction

Trace the construction of a `PodcastEpisode`. Which constructor runs first?
Which data members are initialized by `MediaItem`, and which by
`PodcastEpisode`?

## 3. Trace dynamic binding

In `MusicLibrary::playAll`, the declared pointer type is `const MediaItem*`.
For each object in the demonstration, write:

1. its real object type;
2. the override selected at run time;
3. why no `if` statement is required.

## 4. Introduce a signature error

Temporarily remove `const` from `Song::play`. Keep `override`. Record the
compiler error and explain how `override` protected the design. Restore the
correct signature afterward.

## 5. Add a new media type

Create `RadioStream`, derived from `MediaItem`, with a station name. Implement
`play` and `printDetails`, add one object to `main`, and predict which existing
library functions need to change.

## 6. Abstract-class requirement

Temporarily remove `play` from `Audiobook`. Why can no `Audiobook` object now be
created? Relate the compiler error to the pure virtual function in `MediaItem`.

## 7. Avoid slicing

Explain why the project uses `const MediaItem&` and `const MediaItem*`. What
would be lost if a derived object were copied into a base object by value?

## 8. Virtual destructor

Explain what could go wrong if `MediaItem` had a non-virtual destructor and a
derived object were deleted through a `MediaItem*`.

## 9. Ownership reasoning

`MusicLibrary` stores non-owning pointers. Describe one way a dangling pointer
could be created, and state the lifetime rule that prevents it in this project.

## 10. Design extension

Add one ordinary virtual function with a useful default implementation in
`MediaItem`. Override it in only one derived class and explain the difference
between this function and the pure virtual `play` function.
