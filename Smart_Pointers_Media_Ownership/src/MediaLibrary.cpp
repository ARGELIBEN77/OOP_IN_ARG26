#include "MediaLibrary.hpp"

#include <ostream>
#include <stdexcept>
#include <utility>

void MediaLibrary::addItem(std::unique_ptr<MediaItem> item)
{
    if (item == nullptr)
        throw std::invalid_argument("Cannot add an empty media pointer");

    // unique_ptr cannot be copied. std::move transfers exclusive ownership to
    // the vector element. The parameter becomes empty after this operation.
    items.push_back(std::move(item));
}

std::size_t MediaLibrary::size() const
{
    return items.size();
}

const MediaItem& MediaLibrary::getItem(std::size_t index) const
{
    if (index >= items.size())
        throw std::out_of_range("Media item index is out of range");

    return *items[index];
}

void MediaLibrary::displayAll(std::ostream& output) const
{
    for (const auto& item : items)
    {
        // item is unique_ptr<MediaItem>, but virtual dispatch selects the
        // display implementation belonging to the actual derived object.
        item->display(output);
        output << '\n';
    }
}
