# Unit 12 — STL Exercises

Complete these exercises after studying the lecture. Use the standard
containers and algorithms directly; the purpose is to practise choosing and
combining STL components.

## 1. Choose a container

Choose `vector`, `list`, `set`, or `map` for each requirement and justify the
choice in one or two sentences.

- Songs are displayed in insertion order and frequently accessed by index.
- Artist names must be unique and kept in sorted order.
- A product code must quickly locate its corresponding `Product`.
- Elements are frequently inserted and removed at known positions while
  existing iterators should remain valid.

## 2. Compare the choices

For every answer in Exercise 1, identify the operation that matters most and
state its expected complexity using Big-O notation.

## 3. Sort objects in two ways

Create a `vector<Song>`. Sort it first by title and then by duration. Use a
different lambda for each ordering. Explain why the `Song` class does not need
to change when the ordering changes.

## 4. Search with a captured value

Use `find_if` to locate the first song whose duration is at least a variable
named `minimumDuration`. Capture only what the lambda needs. Handle the case in
which no song matches.

## 5. Count and process

Use `count_if` to count songs by a chosen artist. Then use `for_each` to
calculate their total duration. Compare value capture with reference capture.

## 6. Maintain unique values

Build a `set<string>` containing the genres from a collection of songs. Print
the genres in the order supplied by the set. Try inserting one genre twice and
explain the result.

## 7. Build a lookup table

Create a `map<string, Product>` indexed by product code. Implement operations
that add a product, find a product without accidentally inserting it, and
update the price of an existing product.

## 8. Traverse explicitly

Rewrite one range-based loop using explicit iterators. Identify the meaning of
`begin`, `end`, dereference, and increment in that loop.

## 9. Combine STL and polymorphism

Create a `vector<unique_ptr<MediaItem>>` containing at least two different
derived types. Use an STL algorithm and a lambda to invoke one virtual
operation on every object. Explain why the pointers must not be copied.

## 10. Make a design decision

Select a container for each collection and justify the decision:

- a queue of songs currently scheduled to play;
- a unique set of registered usernames;
- lookup of playlists by a unique numeric identifier;
- a history normally scanned in order but occasionally indexed.

For each, state one reasonable alternative and explain why the first choice
better matches the requirement.

## Completion check

You are ready to continue when you can justify a container using behavior and
complexity, use an iterator range, apply an algorithm with a callable, and
combine STL ownership with an object-oriented design.
