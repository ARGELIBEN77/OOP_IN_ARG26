# Unit 12 Exercises — Self-Check Guidance

Use this after completing the exercises. Several choices can be correct when
the justification matches the requirements.

## Exercises 1–2

- Indexed, insertion-ordered songs: `vector`; indexed access is O(1).
- Unique sorted artist names: `set`; lookup and insertion are O(log n).
- Product-code lookup: `map`; keyed lookup is O(log n).
- Frequent changes at known positions with stable iterators: `list`; insertion
  and removal at a known iterator are O(1).

## Exercises 3–5

The sort lambdas compare title and duration respectively. `find_if` must check
its result against `end()`. A predicate may capture the searched artist by
value or const reference; accumulating a total requires reference capture.

## Exercises 6–8

A `set` rejects a duplicate according to its comparison rule. Use `map::find`
or `map::at` when lookup must not insert a missing key. Explicit traversal
starts at `begin()`, stops at `end()`, dereferences, and increments.

## Exercise 9

`vector<unique_ptr<MediaItem>>` expresses exclusive ownership and supports
polymorphism without slicing. The algorithm's lambda receives each pointer by
reference and invokes the virtual operation through `->`.

## Exercise 10

Judge an answer from the access pattern rather than the noun. Reasonable first
choices include `list` for a changing play queue, `set` for unique usernames,
`map` for identifier lookup, and `vector` for an ordered history that is
occasionally indexed. Alternatives are valid when their trade-offs are
explained accurately.
