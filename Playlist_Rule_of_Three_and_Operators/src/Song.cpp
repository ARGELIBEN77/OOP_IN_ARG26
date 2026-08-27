#include "Song.hpp"

#include <ostream>
#include <stdexcept>
#include <utility>

Song::Song()
    : durationSeconds(0)
{
}

Song::Song(std::string songTitle,
           std::string songArtist,
           int songDuration)
    : title(std::move(songTitle)),
      artist(std::move(songArtist)),
      durationSeconds(songDuration)
{
    if (title.empty())
        throw std::invalid_argument("Song title must not be empty");

    if (durationSeconds <= 0)
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

int Song::getDurationSeconds() const
{
    return durationSeconds;
}

bool Song::operator==(const Song& other) const
{
    return title == other.title &&
           artist == other.artist &&
           durationSeconds == other.durationSeconds;
}

bool Song::operator!=(const Song& other) const
{
    // Reuse operator== so the definition of equality exists in one place.
    return !(*this == other);
}

bool Song::operator<(const Song& other) const
{
    if (title != other.title)
        return title < other.title;

    if (artist != other.artist)
        return artist < other.artist;

    return durationSeconds < other.durationSeconds;
}

std::ostream& operator<<(std::ostream& output, const Song& song)
{
    output << song.getTitle()
           << " by " << song.getArtist()
           << " (" << song.getDurationSeconds() << " seconds)";
    return output;
}
