#include "Song.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>

Song::Song(std::string songTitle, std::string songArtist, int songDuration)
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

void Song::play() const
{
    std::cout << "Playing: " << title << " by " << artist << '\n';
}

std::ostream& operator<<(std::ostream& output, const Song& song)
{
    output << song.getTitle()
           << " | " << song.getArtist()
           << " | " << song.getDurationSeconds() << " seconds";
    return output;
}
