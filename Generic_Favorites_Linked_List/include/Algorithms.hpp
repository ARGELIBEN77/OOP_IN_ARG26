#ifndef FAVORITES_ALGORITHMS_HPP
#define FAVORITES_ALGORITHMS_HPP

#include <cstddef>

namespace learning
{
// These algorithms depend only on iterator operations, not on a particular
// container. They can therefore work with FavoritesList or another container
// whose iterator supports *, ++, ==, and !=.

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
