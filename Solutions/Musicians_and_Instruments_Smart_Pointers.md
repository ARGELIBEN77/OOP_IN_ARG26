# Musicians and Instruments — Self-Check Guidance

- Exercises 1–10: a custom `UniquePointer` has one owner, deleted copy
  operations, transfer by move, and an empty moved-from state.
- Exercises 11–20: custom `SharedPointer` copies share a control block; each
  release decreases the count and the final release destroys object and block.
- Exercises 21–23: `release` gives the raw pointer to the caller; `reset`
  releases the current object before taking another; `swap` exchanges state.
- Exercises 24–28: test copy, move, assignment over an existing owner,
  self-assignment, empty pointers, and final-owner destruction.
- Exercises 29–30: use control-block identity and count only for observation;
  compare behavior with the corresponding standard smart pointer.

For every operation, draw both the managed object and the ownership state
before and after the call.

