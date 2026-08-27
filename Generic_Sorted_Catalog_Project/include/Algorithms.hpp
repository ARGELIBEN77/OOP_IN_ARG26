#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <cstddef>

namespace teaching
{
// All three algorithms work with the half-open range [first, last): first
// refers to the current element, while last marks the position after the final
// element. The algorithms do not need to know which container created the
// iterators or which element type the container stores.

// Search from first to last and return an iterator to the first element for
// which predicate returns true. If no element matches, return last.
template <typename Iterator, typename Predicate>
Iterator findFirst(Iterator first, Iterator last, Predicate predicate)
{
    while (first != last)
    {
        if (predicate(*first))
            return first;

        ++first;
    }

    return last;
}

// Count how many elements satisfy a condition. Predicate may be a functor or
// a lambda, as long as it can be called with *first and returns true or false.
template <typename Iterator, typename Predicate>
std::size_t countIf(Iterator first, Iterator last, Predicate predicate)
{
    std::size_t count = 0;

    while (first != last)
    {
        if (predicate(*first))
            ++count;

        ++first;
    }

    return count;
}

// Perform an action once for every element. Unlike a predicate, Action does
// not have to return a value; printing or calling Song::play are valid actions.
template <typename Iterator, typename Action>
void forEach(Iterator first, Iterator last, Action action)
{
    while (first != last)
    {
        action(*first);
        ++first;
    }
}
}

#endif
