# Musicians and Instruments — Worked Self-Check

This project demonstrates the ownership machinery behind standard smart
pointers. Use the standard library versions in application code.

## Unique ownership

`UniquePointer<T>` stores one raw pointer. Copy operations are deleted because
copying would create two owners. Moving transfers the pointer and sets the
source to `nullptr`.

```cpp
UniquePointer(UniquePointer&& other) noexcept : pointer(other.pointer) {
    other.pointer = nullptr;
}
```

Move assignment must first release the destination's current object, then take
the source pointer, and leave the source empty. Check moving into an empty owner,
moving over an existing owner, and self-move protection.

## Shared ownership

`SharedPointer<T>` stores a managed pointer and a pointer to a shared count.
Copying shares both and increments the count. Releasing decrements it; the final
owner deletes both the managed object and the count.

For each operation, draw the owners, managed object, and control block. Two
different control blocks for the same raw pointer are a serious error because
each block will eventually delete it.

## Operations to verify

- `reset` releases the current ownership before accepting a replacement;
- `swap` exchanges pointer and ownership state without copying the object;
- `release` exists for unique ownership and transfers cleanup responsibility to
  the caller;
- empty pointers are safe to destroy and report a count of zero;
- assignment handles its previous ownership before adopting new ownership.

Compare every behavior with `std::unique_ptr` or `std::shared_ptr`. The learning
implementation explains ownership; it is not a replacement for the complete,
well-tested standard types.
