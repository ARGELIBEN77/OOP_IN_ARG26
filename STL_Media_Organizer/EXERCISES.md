# STL Media Organizer — Exercises

Run `make test` after each change. Add your own assertions before reading any
self-check guidance.

1. Add `findByTitle` with `std::find_if`. Return a pointer or throw an exception;
   explain your choice.
2. Add `titlesByArtist`, using `std::transform` or a loop after `findByArtist`.
3. Sort a copy of the tracks by title without changing their stored order.
4. Count tracks in a genre with a capturing lambda.
5. Reject non-positive durations without partially changing the organizer.
6. Add `removeFromQueue(int id)` and choose a suitable standard algorithm.
7. Replace the play queue's `list` with `deque`. Compare the operations used by
   this project before deciding which version is clearer.
8. Add a `map<string, size_t>` containing the number of tracks per artist.
9. Print every track with `for_each` and a lambda.
10. Add at least five tests covering empty containers, missing identifiers,
    duplicate identifiers, ordering, and lambda-based queries.

## Reflection

For each container, state the requirement it represents and one requirement
that would make a different container preferable.
