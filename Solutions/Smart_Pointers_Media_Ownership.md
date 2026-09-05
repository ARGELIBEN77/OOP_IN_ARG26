# Smart Pointers and Media Ownership — Self-Check Guidance

- Exercises 1–5: draw the single owner before and after a move; destruction
  occurs when the final owning smart pointer is destroyed or reset.
- Exercises 6–10: creation and removal transfer `unique_ptr` by value and
  `std::move`; test that the source becomes empty.
- Exercises 11–15: copying `shared_ptr` shares one object and increases the
  owner count; the object survives until the final owner releases it.
- Exercises 16–20: choose ownership from the relationship. Reading alone needs
  a reference, not another owner. Verify shared mutation through both owners.

Your explanation should name the owner before, during, and after each transfer.

