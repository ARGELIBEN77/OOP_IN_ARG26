#include "MusicLibrary.hpp"

#include "MediaItem.hpp"

#include <ostream>

void MusicLibrary::add(const MediaItem& item)
{
    // MusicLibrary does not own item. The caller must ensure that the object
    // remains alive for as long as the library stores this address.
    items.push_back(&item);
}

std::size_t MusicLibrary::size() const
{
    return items.size();
}

void MusicLibrary::playAll() const
{
    for (const MediaItem* item : items)
        item->play();
}

void MusicLibrary::printAll(std::ostream& output) const
{
    for (const MediaItem* item : items)
    {
        item->printDetails(output);
        output << '\n';
    }
}
