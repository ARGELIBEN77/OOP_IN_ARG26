#ifndef LEARNING_UNIQUE_POINTER_HPP
#define LEARNING_UNIQUE_POINTER_HPP

#include <cstddef>
#include <utility>

// UniquePointer is a compact learning implementation of exclusive ownership.
// Exactly one UniquePointer owns the dynamically allocated object.
template <typename T>
class UniquePointer
{
private:
    T* pointer;

public:
    UniquePointer() noexcept
        : pointer(nullptr)
    {
    }

    explicit UniquePointer(T* newPointer) noexcept
        : pointer(newPointer)
    {
    }

    ~UniquePointer()
    {
        delete pointer;
    }

    // Exclusive ownership cannot be copied. The compiler reports an error if
    // client code attempts to create a second owner by copying.
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    // The move constructor takes the address and empties the source owner.
    UniquePointer(UniquePointer&& other) noexcept
        : pointer(other.pointer)
    {
        other.pointer = nullptr;
    }

    UniquePointer& operator=(UniquePointer&& other) noexcept
    {
        if (this != &other)
        {
            delete pointer;
            pointer = other.pointer;
            other.pointer = nullptr;
        }

        return *this;
    }

    T* get() const noexcept
    {
        return pointer;
    }

    T& operator*() const
    {
        return *pointer;
    }

    T* operator->() const noexcept
    {
        return pointer;
    }

    explicit operator bool() const noexcept
    {
        return pointer != nullptr;
    }

    bool operator==(std::nullptr_t) const noexcept
    {
        return pointer == nullptr;
    }

    bool operator!=(std::nullptr_t) const noexcept
    {
        return pointer != nullptr;
    }

    // release gives the raw address to the caller and stops owning it.
    T* release() noexcept
    {
        T* releasedPointer = pointer;
        pointer = nullptr;
        return releasedPointer;
    }

    // reset deletes the currently owned object and adopts a new address.
    void reset(T* newPointer = nullptr) noexcept
    {
        if (pointer != newPointer)
        {
            delete pointer;
            pointer = newPointer;
        }
    }

    void swap(UniquePointer& other) noexcept
    {
        using std::swap;
        swap(pointer, other.pointer);
    }
};

#endif
