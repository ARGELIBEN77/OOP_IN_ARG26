# Complete-Course Review Bank

The 180-minute practice examination samples the course. This bank provides
additional assessment so every unit can be reviewed. The task titles are
neutral; decide which ideas are relevant before answering.

## Task 1

Redesign a public `struct StudentRecord` as a class. Protect its state, define
a small public interface, separate declaration from implementation, and
explain one invalid state that the new design prevents.

## Task 2

Add a checked modifying operation and two observer operations to the class
from Task 1. Mark every suitable operation `const`. Explain the class invariant
and show that client code cannot bypass it.

## Task 3

Provide default and parameterized constructors for a `Course` class. Delegate
where useful and use initializer lists. Trace which constructor is selected
for four different object declarations.

## Task 4

Predict the complete construction and destruction order for an `Album` that
contains three `Song` objects and is created inside a nested scope. Repeat the
trace when one object is dynamically allocated and explicitly deleted.

## Task 5

Given `Student`, `Course`, and `Registration`, draw a UML class diagram and
identify association, aggregation, or composition where appropriate. Add one
static data member, explain its shared state, and identify one short operation
that is suitable for an inline definition. Compare passing a `Student` by
value with passing it by `const` reference and returning an object by value.

## Task 6

Implement safe copying for a class that owns a dynamic array. Then implement
stream insertion, equality, checked subscript, and compound assignment.
Identify which operators should be members and which may be non-members.

## Task 7

Diagnose a hierarchy that accidentally uses private inheritance, slices a
derived object into a base value, mismatches an override signature, and deletes
through a base pointer with a non-virtual destructor. Correct every problem.

## Task 8

Design an abstract base class with two concrete derived classes. Store the
objects polymorphically and add a third derived class without changing the
processing algorithm. Explain static type, dynamic type, and runtime dispatch.

## Task 9

Trace an exception thrown by a lower-level function through two callers. Show
the order of local-object destruction, correct the order of two catch blocks,
and design a custom exception that carries useful context. Demonstrate that a
failed operation leaves the original object state unchanged.

## Task 10

Design a class template containing values of type `T`, provide a simple
iterator, and use it with a generic algorithm. State the operations required
from `T` and the iterator. Perform one search with a functor and another with a
capturing lambda.

## Task 11

For three relationships, choose between direct objects, `unique_ptr`, and
`shared_ptr`. Trace an ownership move and a shared reference count. Describe
the destructor, deleted copies, moves, and control block required by simplified
custom smart-pointer implementations.

## Task 12

Choose among `vector`, `list`, `set`, and `map` for four requirements. Justify
each choice using ordering, uniqueness, access, lookup, iterator behavior, and
complexity. Apply `sort`, `find_if`, `count_if`, and `for_each` with callables.

## Task 13

Design a small media application combining encapsulated classes, object
relationships, runtime polymorphism, exceptions, templates or generic
algorithms, smart-pointer ownership, and STL containers. Provide a UML sketch,
essential declarations, one error path, and tests for ownership and behavior.
