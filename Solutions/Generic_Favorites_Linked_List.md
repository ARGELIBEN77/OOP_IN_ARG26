# Generic Favorites Linked List — Worked Self-Check

## Template reasoning

Every declaration that depends on the stored type must use `T`, and template
definitions must be visible where the compiler instantiates them. This is why
the project keeps implementations in the header.

## Link invariants

After every operation, verify these facts:

- an empty list has both `first` and `last` equal to `nullptr`;
- a non-empty list has a reachable last node;
- the last node's `next` is `nullptr`;
- `size` equals the number of reachable nodes.

Draw the links before changing them. Most list errors are easier to see in the
drawing than in the debugger.

## Deep copying

Copy values into newly allocated nodes in their original order. Never copy only
`first`, because that makes both lists share the same chain. Assignment must
also release the previous chain exactly once and remain safe for self-assignment.

## Iterator meaning

An iterator stores the current node. Dereference accesses that node's value;
prefix increment moves to `next`; `end()` is represented by `nullptr`.

```cpp
for (auto iterator = list.begin(); iterator != list.end(); ++iterator) {
    use(*iterator);
}
```

The generic algorithm should depend only on these iterator expressions—not on
the list's node type. Test empty, one-node, and many-node lists with at least two
stored types and both a functor and a capturing lambda.
