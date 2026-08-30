# Smart Pointers and Media Ownership — Exercises

Complete the exercises in order and run `make test` after each code change.

## Part 1 — Ownership tracing

1. Draw the owner and object immediately after `make_unique<Song>`.
2. Draw them again after `library.addItem(std::move(song))`.
3. Predict the value of `song == nullptr` before running the program.
4. Identify the exact scope in which the exclusively owned song is destroyed.
5. Explain the role of the virtual destructor when the vector stores
   `unique_ptr<MediaItem>`.

## Part 2 — Working with `unique_ptr`

6. Add a second `Song` to `MediaLibrary` using one expression.
7. Add an `Audiobook` class derived from `MediaItem` and store one in the same
   library.
8. Write a function `createSong` that returns `unique_ptr<MediaItem>`.
9. Add a `removeItem` operation that returns `unique_ptr<MediaItem>` and
   transfers ownership back to the caller.
10. Add tests for the new ownership transfer in both directions.

## Part 3 — Working with `shared_ptr`

11. Create one song and place it in three playlists. Predict and verify its
    owner count after each addition.
12. Release the original pointer and verify that every playlist still displays
    the song.
13. Place one playlist inside a nested scope and observe how its destruction
    changes the owner count.
14. Add a `removeSong` operation and verify the song lifetime after removal.
15. Explain why two playlists sharing one `Song` do not create two separate
    song objects.

## Part 4 — Choosing the ownership model

16. Choose a representation for each relationship and explain the decision:
    library item, temporary search result, playlist entry, and local song.
17. Change a shared song's title through one owner and observe it through the
    other playlist. Add a suitable setter only for this experiment.
18. Compare copying a `shared_ptr` with transferring a `unique_ptr`.
19. Write a function that receives a `const Song&` when it only needs to read a
    song. Explain why the parameter does not become an owner.
20. Create a small ownership diagram for the completed application.

## Review questions

1. What is ownership?
2. Why can a `unique_ptr` be moved but not copied?
3. What state does the source `unique_ptr` have after a move?
4. When is an object managed by `shared_ptr` destroyed?
5. Why is `make_unique` clearer than manually writing `new`?
6. How do smart pointers support RAII?
7. How do smart pointers and runtime polymorphism work together here?
8. Which ownership model best represents each relationship in the project?
