#include "Song.hpp"

#include <iostream>
#include <ostream>
#include <utility>

Song::Song(std::string songTitle, int songDuration, std::string songArtist)
    : MediaItem(std::move(songTitle), songDuration),
      artist(std::move(songArtist))
{
}

const std::string& Song::getArtist() const
{
    return artist;
}

void Song::play() const
{
    std::cout << "Playing song: " << getTitle()
              << " by " << artist << '\n';
}

void Song::printDetails(std::ostream& output) const
{
    // Reuse the shared base implementation, then append Song-specific data.
    MediaItem::printDetails(output);
    output << ", artist: " << artist;
}
