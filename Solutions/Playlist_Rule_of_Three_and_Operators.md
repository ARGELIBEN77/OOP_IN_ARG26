# Playlist — Worked Self-Check

Open this page only after attempting the exercises and running your tests.

## Ownership and copying

The dynamic array is owned by one `Playlist`. Copying the pointer alone would
make two objects believe that they own the same array. That causes shared
changes and, eventually, two calls to `delete[]` for one allocation.

A correct copy constructor allocates new storage and copies every active
element. A useful test modifies the copy and verifies that the original does
not change.

```cpp
Playlist::Playlist(const Playlist& other)
    : songs(new Song[other.capacity]), count(other.count),
      capacity(other.capacity) {
    for (std::size_t index = 0; index < count; ++index) {
        songs[index] = other.songs[index];
    }
}
```

Adapt the member names to the project; do not paste this without understanding
which values describe allocated capacity and which describe active elements.

## Assignment reasoning

Assignment must work for self-assignment and must not destroy the old value
until replacement storage is ready. One safe sequence is allocate, copy,
release old storage, then install the new state.

Check these cases: empty to empty, non-empty to empty, empty to non-empty,
assignment over existing data, and `playlist = playlist`.

## Operators

- Equality compares the logical song sequence, not pointer addresses.
- Stream insertion receives a `const Playlist&`, writes to the supplied stream,
  and returns that same stream.
- Const and non-const subscripts use the same bounds rule but return different
  reference types.
- Combination creates a result without changing either operand.

Run with sanitizers when available. A correct visible result is not enough if
the program leaks, double-deletes, or reads beyond the array.
