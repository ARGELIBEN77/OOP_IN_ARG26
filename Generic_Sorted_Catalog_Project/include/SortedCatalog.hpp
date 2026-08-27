#ifndef SORTED_CATALOG_HPP
#define SORTED_CATALOG_HPP

#include <algorithm>
#include <cstddef>
#include <iterator>
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
    std::vector<T> items_;
    Compare compare_;

    // Two elements are equivalent when neither is ordered before the other.
    // This is the standard equivalence rule used by ordered containers.
    bool equivalent(const T& first, const T& second) const
    {
        return !compare_(first, second) && !compare_(second, first);
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
        const T* current_;

        explicit Iterator(const T* current)
            : current_(current)
        {
        }

        // SortedCatalog creates iterators from its internal storage.
        friend class SortedCatalog<T, Compare>;

    public:
        // These aliases allow standard algorithms to obtain information about
        // the iterator through std::iterator_traits.
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        Iterator()
            : current_(nullptr)
        {
        }

        reference operator*() const
        {
            return *current_;
        }

        pointer operator->() const
        {
            return current_;
        }

        // Prefix increment: advance first and then return this iterator.
        Iterator& operator++()
        {
            ++current_;
            return *this;
        }

        // Postfix increment returns the old iterator value.
        Iterator operator++(int)
        {
            Iterator old(*this);
            ++(*this);
            return old;
        }

        bool operator==(const Iterator& other) const
        {
            return current_ == other.current_;
        }

        bool operator!=(const Iterator& other) const
        {
            return !(*this == other);
        }
    };

    // The comparison policy is stored inside the container. This permits a
    // stateful functor or a capturing lambda to control the ordering.
    explicit SortedCatalog(Compare compare)
        : compare_(std::move(compare))
    {
    }

    // Passing by value is intentional: an lvalue is copied into value, while
    // an rvalue is moved into value. The final insertion then moves value into
    // the vector. This is a useful compact application of move semantics.
    void add(T value)
    {
        auto position = std::lower_bound(
            items_.begin(), items_.end(), value, compare_);

        items_.insert(position, std::move(value));
    }

    bool containsEquivalent(const T& value) const
    {
        auto position = std::lower_bound(
            items_.begin(), items_.end(), value, compare_);

        return position != items_.end() && equivalent(*position, value);
    }

    bool removeFirstEquivalent(const T& value)
    {
        auto position = std::lower_bound(
            items_.begin(), items_.end(), value, compare_);

        if (position == items_.end() || !equivalent(*position, value))
            return false;

        items_.erase(position);
        return true;
    }

    std::size_t size() const
    {
        return items_.size();
    }

    bool empty() const
    {
        return items_.empty();
    }

    const T& at(std::size_t index) const
    {
        return items_.at(index);
    }

    void clear()
    {
        items_.clear();
    }

    Iterator begin() const
    {
        return Iterator(items_.data());
    }

    Iterator end() const
    {
        // Avoid pointer arithmetic on a null data pointer in an empty vector.
        if (items_.empty())
            return Iterator(items_.data());

        return Iterator(items_.data() + items_.size());
    }
};

#endif
