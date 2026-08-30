#ifndef LEARNING_SHARED_POINTER_HPP
#define LEARNING_SHARED_POINTER_HPP

#include <cstddef>

// SharedPointer is a compact learning implementation of shared ownership.
// Every owner points to the same ControlBlock, which stores the object address
// and the number of SharedPointer objects that currently own it.
template <typename T>
class SharedPointer
{
private:
    struct ControlBlock
    {
        T* pointer;
        std::size_t referenceCount;
    };

    ControlBlock* controlBlock;

    void addOwner() noexcept
    {
        if (controlBlock != nullptr)
            ++controlBlock->referenceCount;
    }

    void removeOwner() noexcept
    {
        if (controlBlock == nullptr)
            return;

        --controlBlock->referenceCount;

        if (controlBlock->referenceCount == 0)
        {
            delete controlBlock->pointer;
            delete controlBlock;
        }

        controlBlock = nullptr;
    }

public:
    SharedPointer() noexcept
        : controlBlock(nullptr)
    {
    }

    explicit SharedPointer(T* newPointer)
        : controlBlock(nullptr)
    {
        if (newPointer != nullptr)
        {
            try
            {
                controlBlock = new ControlBlock{newPointer, 1};
            }
            catch (...)
            {
                // Ownership was accepted by this constructor, so it also
                // releases the object if control-block allocation fails.
                delete newPointer;
                throw;
            }
        }
    }

    ~SharedPointer()
    {
        removeOwner();
    }

    // Copying creates another owner of the same object and control block.
    SharedPointer(const SharedPointer& other) noexcept
        : controlBlock(other.controlBlock)
    {
        addOwner();
    }

    SharedPointer& operator=(const SharedPointer& other) noexcept
    {
        if (this != &other)
        {
            removeOwner();
            controlBlock = other.controlBlock;
            addOwner();
        }

        return *this;
    }

    // Moving transfers this SharedPointer owner's place without changing the
    // reference count. The source becomes empty.
    SharedPointer(SharedPointer&& other) noexcept
        : controlBlock(other.controlBlock)
    {
        other.controlBlock = nullptr;
    }

    SharedPointer& operator=(SharedPointer&& other) noexcept
    {
        if (this != &other)
        {
            removeOwner();
            controlBlock = other.controlBlock;
            other.controlBlock = nullptr;
        }

        return *this;
    }

    T* get() const noexcept
    {
        return controlBlock == nullptr ? nullptr : controlBlock->pointer;
    }

    T& operator*() const
    {
        return *controlBlock->pointer;
    }

    T* operator->() const noexcept
    {
        return get();
    }

    explicit operator bool() const noexcept
    {
        return get() != nullptr;
    }

    bool operator==(std::nullptr_t) const noexcept
    {
        return get() == nullptr;
    }

    bool operator!=(std::nullptr_t) const noexcept
    {
        return get() != nullptr;
    }

    std::size_t useCount() const noexcept
    {
        return controlBlock == nullptr ? 0 : controlBlock->referenceCount;
    }

    void reset() noexcept
    {
        removeOwner();
    }

    void reset(T* newPointer)
    {
        if (get() == newPointer)
            return;

        SharedPointer replacement(newPointer);
        swap(replacement);
    }

    void swap(SharedPointer& other) noexcept
    {
        ControlBlock* temporary = controlBlock;
        controlBlock = other.controlBlock;
        other.controlBlock = temporary;
    }
};

#endif
