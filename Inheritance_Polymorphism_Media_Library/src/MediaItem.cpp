#include "MediaItem.hpp"

#include <ostream>
#include <stdexcept>
#include <utility>

MediaItem::MediaItem(std::string itemTitle, int itemDuration)
    : title(std::move(itemTitle)),
      durationSeconds(itemDuration)
{
    if (title.empty())
        throw std::invalid_argument("Media item title must not be empty");

    if (durationSeconds <= 0)
        throw std::invalid_argument("Media item duration must be positive");
}

const std::string& MediaItem::getTitle() const
{
    return title;
}

int MediaItem::getDurationSeconds() const
{
    return durationSeconds;
}

void MediaItem::printDetails(std::ostream& output) const
{
    output << "Title: " << title
           << ", duration: " << durationSeconds << " seconds";
}
