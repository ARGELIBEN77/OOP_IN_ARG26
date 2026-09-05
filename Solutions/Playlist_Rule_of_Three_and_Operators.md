# Playlist — Self-Check Guidance

- Exercises 1–2: `songs` is the owned resource; a shallow copy creates shared
  storage, double deletion, and unintended cross-object changes.
- Exercises 3–5: allocate independent storage, copy elements, handle
  self-assignment, and prove independence by modifying one copy.
- Exercise 6: allocate replacement storage before releasing the old array and
  preserve every existing element.
- Exercises 7–8: reuse equality logic where appropriate; stream insertion must
  return the stream and should not modify the playlist.
- Exercise 9: provide const and non-const access with consistent bounds rules.
- Exercise 10: define the meaning of combination before coding it, preserve
  operand state, and test capacity growth.

Use sanitizers if available to detect leaks, invalid access, and double delete.

