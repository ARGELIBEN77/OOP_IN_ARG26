#include "Song.hpp"

#include <ostream>
#include <stdexcept>

Song::Song(const std::string& title, const std::string& artist, int duration)
    : title(title), artist(artist), duration(duration)
{
    if (title.empty())
        throw std::invalid_argument("Song title cannot be empty");

    if (artist.empty())
        throw std::invalid_argument("Song artist cannot be empty");

    if (duration <= 0)
        throw std::invalid_argument("Song duration must be positive");
}

const std::string& Song::getTitle() const
{
    return title;
}

const std::string& Song::getArtist() const
{
    return artist;
}

int Song::getDuration() const
{
    return duration;
}

bool Song::operator==(const Song& other) const
{
    return title == other.title && artist == other.artist &&
           duration == other.duration;
}

std::ostream& operator<<(std::ostream& output, const Song& song)
{
    output << song.getTitle() << " by " << song.getArtist()
           << " (" << song.getDuration() << " seconds)";
    return output;
}
