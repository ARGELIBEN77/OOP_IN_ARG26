# Unit 4 — Object Lifetime and Destructors

This unit follows objects from construction through scope exit and destruction.

## Learning outcomes

After completing this unit, you should be able to:

- distinguish automatic and dynamic object lifetime;
- predict construction and destruction order in nested scopes;
- explain how composition affects lifetime;
- use RAII so a resource is tied to an object's lifetime;
- implement a destructor when a class directly owns a resource.

## Main ideas

- Automatic and dynamic object lifetime
- Destructor syntax and responsibilities
- Destruction order and LIFO behavior
- Lifetime of composed objects
- RAII and deterministic cleanup

## Study resources

- [Lecture](Unit_4_OOP_Destructors.pdf)
- [Focused lifetime exercises](EXERCISES.md)
- [Self-check solutions](../../Solutions/Unit_04/EXERCISES_SOLUTIONS.md)
- [Song Class Fundamentals](../../Song_Class_Fundamentals/README.md)
- [Playlist — Rule of Three and Operators](../../Playlist_Rule_of_Three_and_Operators/README.md)

Predict every trace on paper before compiling it. The purpose is to learn to
reason about lifetime, not merely to copy the program's output.
