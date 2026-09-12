# Inheritance and Polymorphism — Worked Self-Check

## Decide the call before running

For every virtual call, write two types:

- the **static type** of the pointer or reference;
- the **dynamic type** of the object it currently denotes.

When the operation is virtual, the dynamic type selects the override. When an
object is copied into a base object, its derived part is sliced and no dynamic
derived object remains.

## Correct override

```cpp
class MediaItem {
public:
    virtual ~MediaItem() = default;
    virtual void play() const = 0;
};

class Song : public MediaItem {
public:
    void play() const override;
};
```

`public` inheritance preserves the intended “Song is a MediaItem” relationship.
`override` asks the compiler to reject a signature mismatch. The virtual
destructor makes deletion through a base pointer safe.

## Extensibility check

A new derived type should be usable by existing code that processes
`MediaItem&` or `MediaItem*` without adding type tests. If processing contains
`if` statements for every derived type, move the changing behavior into a
virtual operation.

## Ownership check

Polymorphic access and ownership are separate decisions. A raw base pointer can
be a short-lived non-owning view, but ownership should be explicit. In later
units, `unique_ptr<MediaItem>` represents exclusive ownership and preserves
virtual dispatch.

Test an override, a signature mistake, base-reference access, attempted base
instantiation, and destruction through the chosen ownership type.
