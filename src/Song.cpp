#include "Song.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>

Song::Song(std::string title, std::string artist, int durationSeconds)
    : title_(std::move(title)),
      artist_(std::move(artist)),
      durationSeconds_(durationSeconds)
{
    if (title_.empty())
        throw std::invalid_argument("Song title must not be empty");

    if (durationSeconds_ <= 0)
        throw std::invalid_argument("Song duration must be positive");
}

const std::string& Song::getTitle() const
{
    return title_;
}

const std::string& Song::getArtist() const
{
    return artist_;
}

int Song::getDurationSeconds() const
{
    return durationSeconds_;
}

void Song::play() const
{
    std::cout << "Playing: " << title_ << " by " << artist_ << '\n';
}

std::ostream& operator<<(std::ostream& out, const Song& song)
{
    out << song.getTitle()
        << " | " << song.getArtist()
        << " | " << song.getDurationSeconds() << " seconds";
    return out;
}
