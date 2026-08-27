#ifndef SORTED_CATALOG_HPP
#define SORTED_CATALOG_HPP

#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

// SortedCatalog has two template parameters:
//   T       - the type of element stored in the catalog.
//   Compare - a callable object that decides the ordering.
//
// Compare must support:
//     bool compare(const T& first, const T& second)
// and must define a strict weak ordering, like std::less.
template <typename T, typename Compare>
class SortedCatalog
{
private:
    // The vector owns the actual objects. Clients do not access it directly,
    // because every insertion must preserve the catalog's sorted order.
    std::vector<T> items;

    // The comparison object is part of the catalog's type and state. It may be
    // a named functor or a lambda supplied when the catalog is constructed.
    Compare compare;

    // Two elements are equivalent when neither is ordered before the other.
    // This is the standard equivalence rule used by ordered containers.
    bool equivalent(const T& first, const T& second) const
    {
        return !compare(first, second) && !compare(second, first);
    }

public:
    // The iterator stores a pointer to the current element. The catalog uses
    // vector internally, so its elements are stored in contiguous memory.
    //
    // The iterator deliberately provides read-only access. Changing a title
    // or duration through the iterator could violate the sorted invariant.
    class Iterator
    {
    private:
        // current points to the element represented by this iterator. end()
        // uses a pointer one position past the final element.
        const T* current;

        explicit Iterator(const T* position)
            : current(position)
        {
        }

        // SortedCatalog creates iterators from its internal storage.
        friend class SortedCatalog<T, Compare>;

    public:
        Iterator()
            : current(nullptr)
        {
        }

        const T& operator*() const
        {
            return *current;
        }

        const T* operator->() const
        {
            return current;
        }

        // Prefix increment: advance first and then return this iterator.
        Iterator& operator++()
        {
            ++current;
            return *this;
        }

        bool operator==(const Iterator& other) const
        {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const
        {
            return !(*this == other);
        }
    };

    // The comparison policy is stored inside the container. This permits a
    // stateful functor or a capturing lambda to control the ordering.
    explicit SortedCatalog(Compare comparison)
        : compare(std::move(comparison))
    {
    }

    // Passing by value is intentional: an lvalue is copied into value, while
    // an rvalue is moved into value. The final insertion then moves value into
    // the vector. This is a useful compact application of move semantics.
    void add(T value)
    {
        auto position = std::lower_bound(
            items.begin(), items.end(), value, compare);

        items.insert(position, std::move(value));
    }

    // Search for an element that is equivalent according to Compare. This is
    // not necessarily the same as calling operator== on T.
    bool containsEquivalent(const T& value) const
    {
        auto position = std::lower_bound(
            items.begin(), items.end(), value, compare);

        return position != items.end() && equivalent(*position, value);
    }

    // Remove the first equivalent element and report whether one was found.
    bool removeFirstEquivalent(const T& value)
    {
        auto position = std::lower_bound(
            items.begin(), items.end(), value, compare);

        if (position == items.end() || !equivalent(*position, value))
            return false;

        items.erase(position);
        return true;
    }

    std::size_t size() const
    {
        return items.size();
    }

    bool empty() const
    {
        return items.empty();
    }

    const T& at(std::size_t index) const
    {
        return items.at(index);
    }

    void clear()
    {
        items.clear();
    }

    Iterator begin() const
    {
        // begin() represents the first element. In an empty vector, data()
        // and the value used by end() are the same, so begin() == end().
        return Iterator(items.data());
    }

    Iterator end() const
    {
        // Avoid pointer arithmetic on a null data pointer in an empty vector.
        if (items.empty())
            return Iterator(items.data());

        return Iterator(items.data() + items.size());
    }
};

#endif
