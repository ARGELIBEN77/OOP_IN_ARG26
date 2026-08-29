#ifndef FAVORITES_LIST_HPP
#define FAVORITES_LIST_HPP

#include <cstddef>
#include <stdexcept>
#include <utility>

// FavoritesList is a generic singly linked list. The container owns every
// Node that it creates, so it is responsible for copying and deleting nodes.
template <typename T>
class FavoritesList
{
private:
    struct Node
    {
        T value;
        Node* next;

        explicit Node(const T& newValue)
            : value(newValue), next(nullptr)
        {
        }
    };

    Node* first;
    Node* last;
    std::size_t count;

    void copyFrom(const FavoritesList& other)
    {
        try
        {
            for (Node* current = other.first; current != nullptr;
                 current = current->next)
            {
                add(current->value);
            }
        }
        catch (...)
        {
            // If copying an element fails, release nodes already created.
            clear();
            throw;
        }
    }

    void swap(FavoritesList& other) noexcept
    {
        using std::swap;
        swap(first, other.first);
        swap(last, other.last);
        swap(count, other.count);
    }

public:
    // The iterator stores the node currently being visited. nullptr is the
    // end position. Only the operations needed by this project are included.
    class Iterator
    {
    private:
        Node* current;

    public:
        explicit Iterator(Node* node)
            : current(node)
        {
        }

        T& operator*() const
        {
            return current->value;
        }

        T* operator->() const
        {
            return &current->value;
        }

        // Prefix increment follows the link to the next node.
        Iterator& operator++()
        {
            if (current != nullptr)
                current = current->next;

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

    FavoritesList()
        : first(nullptr), last(nullptr), count(0)
    {
    }

    // A linked list must create its own nodes when it is copied. Sharing the
    // same nodes would cause accidental changes and double deletion.
    FavoritesList(const FavoritesList& other)
        : first(nullptr), last(nullptr), count(0)
    {
        copyFrom(other);
    }

    FavoritesList& operator=(const FavoritesList& other)
    {
        if (this != &other)
        {
            // Copy first, then exchange resources. The old nodes are deleted
            // when temporaryCopy leaves this block.
            FavoritesList temporaryCopy(other);
            swap(temporaryCopy);
        }

        return *this;
    }

    ~FavoritesList()
    {
        clear();
    }

    // Add at the end so iteration preserves insertion order.
    void add(const T& value)
    {
        Node* newNode = new Node(value);

        if (empty())
            first = newNode;
        else
            last->next = newNode;

        last = newNode;
        ++count;
    }

    // This operation requires T to provide operator==. It removes only the
    // first matching element and reports whether an element was removed.
    bool removeFirst(const T& value)
    {
        Node* current = first;
        Node* previous = nullptr;

        while (current != nullptr && !(current->value == value))
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
            return false;

        if (previous == nullptr)
            first = current->next;
        else
            previous->next = current->next;

        if (current == last)
            last = previous;

        delete current;
        --count;
        return true;
    }

    T& front()
    {
        if (empty())
            throw std::out_of_range("FavoritesList is empty");

        return first->value;
    }

    const T& front() const
    {
        if (empty())
            throw std::out_of_range("FavoritesList is empty");

        return first->value;
    }

    bool empty() const
    {
        return count == 0;
    }

    std::size_t size() const
    {
        return count;
    }

    void clear()
    {
        while (first != nullptr)
        {
            Node* nodeToDelete = first;
            first = first->next;
            delete nodeToDelete;
        }

        last = nullptr;
        count = 0;
    }

    Iterator begin()
    {
        return Iterator(first);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }
};

#endif
