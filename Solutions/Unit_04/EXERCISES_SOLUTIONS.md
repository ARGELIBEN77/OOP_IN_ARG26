# Unit 4 — Lifetime Exercise Solutions

Use this only after writing your own trace.

## 1. One scope

```text
construct first
construct second
destroy second
destroy first
```

Automatic objects in the same scope are destroyed in reverse construction
order.

## 2. Nested scope

`inner` is destroyed at the closing brace of its block. Leaving the inner block
does not leave `main`; objects in the outer block remain alive.

## 3. Function lifetime

The function's local objects are destroyed, in reverse order, before control
returns to `main`. The objects already created in `main` remain alive.

## 4. Composition

```text
engine starts
car ready
car leaves
engine stops
```

Members must exist before the containing constructor body can use them. The
destructor body runs while members are still valid; members are destroyed
afterwards in reverse declaration order.

## 5. Automatic and dynamic lifetime

The automatic object is destroyed at scope exit. The dynamically allocated
object remains alive until `delete` is applied to its owning pointer. Omitting
that action leaks the object. Later units replace manual ownership with RAII
types such as `unique_ptr`.

## 6. Early return

Returning normally still exits the scope, so destructors for completed local
objects run. This is why cleanup placed in a destructor is more reliable than
cleanup repeated at every return statement.

## 7. RAII

The `IntArray` object controls the resource. Its destructor uses `delete[]`, so
clients never release the array directly. Copying requires a deliberate copy
constructor and copy-assignment operator that create independent storage—the
Rule of Three studied in Unit 6.

## 8. Find the lifetime error

`local` is destroyed when `makeMarker` returns, so its address immediately
dangles. Safe alternatives are:

```cpp
Marker makeMarker() { return Marker("temporary"); }

std::unique_ptr<Marker> makeOwnedMarker() {
    return std::make_unique<Marker>("temporary");
}
```

The first transfers a value; the second transfers explicit ownership.
