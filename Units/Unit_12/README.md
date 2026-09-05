# Unit 12 — Standard Template Library (STL)

This unit brings together STL containers, iterators, algorithms, and callable
objects. Learners apply the generic-programming ideas from Unit 10 to standard
C++ components and select suitable containers for application requirements.

## Learning outcomes

After completing this unit, learners should be able to:

- explain how containers, iterators, algorithms, and callable objects work
  together;
- store and process objects using `std::vector`, `std::list`, `std::set`, and
  `std::map`;
- traverse containers with iterators and range-based loops;
- apply algorithms such as `std::sort`, `std::find_if`, `std::count_if`, and
  `std::for_each`;
- use lambdas and functors to customize an algorithm;
- choose a container according to ordering, uniqueness, access, and lookup
  requirements;
- recognize the basic performance implications of a container choice;
- integrate STL components into an object-oriented application.

## Main ideas

- The STL model: containers, iterators, algorithms, and callable objects
- Sequence containers and associative containers
- Iterator ranges and range-based loops
- Searching, counting, sorting, and processing elements
- Predicates, functors, and lambdas
- Container selection and basic complexity reasoning
- Combining STL components with classes and smart pointers

## Suggested learning activities

1. Store `Song` objects in a `vector` and sort them with different lambdas.
2. Use `find_if` to locate a song by artist or duration.
3. Use a `set` to maintain unique genres or artists.
4. Use a `map` to associate product codes with `Product` objects.
5. Compare the requirements that suggest `vector`, `list`, `set`, or `map`.
6. Store `unique_ptr<MediaItem>` in a vector and process the polymorphic
   objects with an STL algorithm.

## Supporting projects

- [Generic Sorted Catalog](../../Generic_Sorted_Catalog_Project/README.md)
- [Generic Favorites Linked List](../../Generic_Favorites_Linked_List/README.md)
- [Smart Pointers and Media Ownership](../../Smart_Pointers_Media_Ownership/README.md)

## Assessment

- [Unit 12 exercises](EXERCISES.md)
- [Self-check guidance](../../Solutions/Unit_12/EXERCISES_GUIDANCE.md)
