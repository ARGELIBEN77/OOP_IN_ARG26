# Guided Exercises

Complete the exercises in order. Each stage builds on the previous one.

## 1. Trace template instantiation

For this declaration:

```cpp
SortedCatalog<Song, CompareSongByTitle> catalog(CompareSongByTitle{});
```

Answer:

1. What type replaces `T`?
2. What type replaces `Compare`?
3. What expression is executed by `compare(first, second)`?
4. Why must the implementation of `SortedCatalog` be visible in the header?

## 2. Trace insertion

Insert `One`, `Imagine`, and `Yesterday` into a title-ordered catalog. After
each call to `add`, draw the vector and mark the insertion position returned by
`std::lower_bound`.

## 3. Complete an iterator

Temporarily remove the bodies of these operations and implement them again:

```cpp
const T& operator*() const;
const T* operator->() const;
Iterator& operator++();
bool operator!=(const Iterator& other) const;
```

Explain which operation is used by each part of an explicit `for` loop.

## 4. Range-based loop translation

Rewrite this loop without using a range-based `for`:

```cpp
for (const Song& song : catalog)
    std::cout << song << '\n';
```

Your version must call `begin()` and `end()` explicitly.

## 5. New comparison functor

Create `CompareSongByArtist`. If two Songs have the same artist, order them by
title. Instantiate a catalog with the new functor and test it with at least five
Songs.

## 6. Functor and equivalent lambda

Use `LongerThan(200)` with `teaching::countIf`. Then replace it with an
equivalent capturing lambda. Explain where each object stores the value `200`.

## 7. Write a generic algorithm

Implement:

```cpp
template <typename Iterator, typename Predicate>
bool anyOf(Iterator first, Iterator last, Predicate predicate);
```

Test it with a lambda that checks whether the catalog contains a Song by a
specified artist.

## 8. Trace a generic algorithm

Trace `teaching::findFirst` for a catalog containing three Songs. Use a
predicate that accepts Songs longer than 200 seconds. For each loop iteration,
record:

- the Song referred to by `first`;
- the result of `predicate(*first)`;
- whether `first` is incremented or returned.

Explain why `findFirst` does not need to know the type of the container.

## 9. Design question

Why does `SortedCatalog::Iterator` return `const T&`? Describe a concrete bug
that could occur if a client changed a Song title through the iterator.

## 10. Optional extension

Create a different domain type, such as `Book`, `Student`, or `Product`, and
instantiate the unchanged `SortedCatalog` with two different ordering policies.
