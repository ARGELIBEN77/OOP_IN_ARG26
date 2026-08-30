#include "MediaItem.hpp"

#include <stdexcept>

int MediaItem::livingObjects = 0;

MediaItem::MediaItem(const std::string& title)
    : title(title)
{
    if (title.empty())
        throw std::invalid_argument("Media title cannot be empty");

    ++livingObjects;
}

MediaItem::~MediaItem()
{
    --livingObjects;
}

const std::string& MediaItem::getTitle() const
{
    return title;
}

int MediaItem::getLivingObjectCount()
{
    return livingObjects;
}
