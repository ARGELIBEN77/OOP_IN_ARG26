# STL Media Organizer

This Unit 12 project demonstrates how container choice expresses application
requirements. It uses the same media-course theme while giving each standard
container a clear responsibility.

## What you will practise

- `vector` for an ordered collection with indexed access;
- `map` for lookup by a unique track identifier;
- `set` for unique, sorted genres;
- `list` for a play queue with front removal;
- `sort`, `find`, `count_if`, and `copy_if`;
- lambdas with value and reference capture;
- exceptions that preserve valid object state.

## Build and run

```bash
make
make run
make test
```

## Suggested reading order

1. `include/Track.hpp` — the object stored by the containers.
2. `include/MediaOrganizer.hpp` — why each container and algorithm is used.
3. `src/main.cpp` — a small demonstration.
4. `tests/test.cpp` — expected behavior and error cases.
5. `EXERCISES.md` — changes for you to implement.

Before changing a container, write down the required ordering, uniqueness,
lookup, insertion, and removal behavior. Then decide whether the alternative
actually fits those requirements better.
