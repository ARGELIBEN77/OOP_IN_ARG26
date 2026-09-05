# Unit 11 — Smart Pointers and Move Semantics

This unit introduces explicit ownership models and efficient resource transfer.

## Learning outcomes

After completing this unit, you should be able to:

- select exclusive or shared ownership for an object relationship;
- transfer a `unique_ptr` using move semantics;
- trace the reference count and lifetime of a `shared_ptr` object;
- implement the essential operations of simplified unique and shared pointers.

## Main ideas

- Exclusive ownership with `std::unique_ptr`
- Shared ownership with `std::shared_ptr`
- Transferring ownership with `std::move`
- Implementing a move-only `UniquePointer<T>`
- Implementing a reference-counted `SharedPointer<T>` and control block
- Choosing an ownership model for object relationships

## Unit materials

- [Lecture notes](LECTURE_NOTES.md)
- [Smart Pointers and Media Ownership project](../../Smart_Pointers_Media_Ownership/README.md)
- [Guided project exercises](../../Smart_Pointers_Media_Ownership/EXERCISES.md)
- [Custom smart-pointer implementation project](../../Musicians_and_Instruments_Smart_Pointers/README.md)
- [Musicians and Instruments exercises](../../Musicians_and_Instruments_Smart_Pointers/EXERCISES.md)
