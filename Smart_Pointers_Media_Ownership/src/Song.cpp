#include "Song.hpp"

#include <ostream>
#include <stdexcept>

Song::Song(const std::string& title, const std::string& artist, int duration)
    : MediaItem(title), artist(artist), duration(duration)
{
    if (artist.empty())
        throw std::invalid_argument("Song artist cannot be empty");

    if (duration <= 0)
        throw std::invalid_argument("Song duration must be positive");
}

const std::string& Song::getArtist() const
{
    return artist;
}

int Song::getDuration() const
{
    return duration;
}

void Song::display(std::ostream& output) const
{
    output << getTitle() << " by " << artist
           << " (" << duration << " seconds)";
}
