# Musicians and Instruments — Guided Exercises

Run `make test` after each code change.

## Part 1 — Trace exclusive ownership

1. Draw the owner of the guitar immediately after the `UniquePointer`
   constructor.
2. Draw the ownership state after `noa.receiveInstrument(std::move(guitar))`.
3. Explain why `guitar == nullptr` after the transfer.
4. Trace the value returned by `releaseInstrument`.
5. Explain why returning `UniquePointer` transfers ownership safely.

## Part 2 — Extend the instrument transfer

6. Add a third musician and transfer the instrument again.
7. Add a `replaceInstrument` scenario and observe when the previous instrument
   is destroyed.
8. Write a function `createInstrument` that returns
   `UniquePointer<Instrument>`.
9. Add a test proving that one instrument remains alive throughout several
   transfers.
10. Explain how the `UniquePointer` member affects copying a `Musician`.

## Part 3 — Trace shared ownership

11. Add the guest musician to a third ensemble and predict `useCount()`.
12. Place one ensemble in a nested scope and observe the owner count when that
    scope ends.
13. Release the original `SharedPointer` and verify that the ensemble owners keep
    the musician alive.
14. Verify that two ensembles refer to the same object rather than two copies.
15. Add a `removeMusician` operation and test its effect on lifetime.

## Part 4 — Apply the ownership model

16. Add a second guest musician with a different instrument.
17. Write a function that receives `const Musician&` to print a musician
    without becoming an owner.
18. Decide which pointer type represents each relationship: a musician's
    instrument, a guest in several ensembles, and a temporary search result.
19. Draw a complete ownership diagram for two ensembles sharing one guest.
20. Add tests showing that all musicians and instruments are destroyed after
    their final owners leave scope.

## Part 5 — Complete the pointer implementations

21. Trace the `UniquePointer` move constructor line by line.
22. Add a test for `UniquePointer::release` and delete the released raw pointer
    at the correct point.
23. Add tests for `UniquePointer::reset` and `swap`.
24. Trace the `SharedPointer` copy constructor and record the counter value.
25. Test shared copy assignment when the destination already owns another
    object.
26. Test both `SharedPointer` move operations and verify the source is empty.
27. Test self-copy-assignment and self-move-assignment.
28. Draw the control block before and after the final owner is destroyed.
29. Add a debug function that prints the control-block address and count.
30. Compare each learning operation with the corresponding operation of
    `std::unique_ptr` or `std::shared_ptr`.

## Review questions

1. What does exclusive ownership mean?
2. Why is `UniquePointer` moved rather than copied?
3. What remains unchanged when ownership of an instrument moves?
4. What does copying a `SharedPointer` copy?
5. When is a shared musician destroyed?
6. Why does `getMusician` return a reference instead of another shared owner?
7. How do the living-object counters help verify lifetime?
8. Which ownership relationship is represented by each smart pointer?
