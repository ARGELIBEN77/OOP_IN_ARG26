#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <cstddef>

namespace teaching
{
// The algorithm depends only on iterator operations and on the callable
// predicate. It does not know the container type or the element type.
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

// Action may be a function, functor, or lambda. It is called once for every
// element in the iterator range [first, last).
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
