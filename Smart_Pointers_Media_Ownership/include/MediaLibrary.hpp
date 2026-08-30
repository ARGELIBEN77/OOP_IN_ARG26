#ifndef MEDIA_LIBRARY_OWNERSHIP_HPP
#define MEDIA_LIBRARY_OWNERSHIP_HPP

#include "MediaItem.hpp"

#include <cstddef>
#include <iosfwd>
#include <memory>
#include <vector>

// MediaLibrary has exclusive ownership of its polymorphic media objects.
class MediaLibrary
{
private:
    std::vector<std::unique_ptr<MediaItem>> items;

public:
    // Ownership moves from the caller into the library.
    void addItem(std::unique_ptr<MediaItem> item);

    std::size_t size() const;
    const MediaItem& getItem(std::size_t index) const;
    void displayAll(std::ostream& output) const;
};

#endif
