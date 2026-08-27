#include "Song.hpp"

#include <cassert>
#include <ostream>
#include <utility>

Song::Song(std::string songTitle,
           std::string songArtist,
           int songDuration)
    // The initializer list constructs each data member directly. Assignment
    // inside the constructor body would initialize first and assign later.
    : title(std::move(songTitle)),
      artist(std::move(songArtist)),
      durationSeconds(songDuration),
      rating(0)
{
    // These are constructor preconditions. Exception handling is deliberately
    // left for a later unit, so assertions expose programming errors here.
    assert(!title.empty());
    assert(!artist.empty());
    assert(durationSeconds > 0);
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

int Song::getRating() const
{
    return rating;
}

bool Song::setRating(int newRating)
{
    if (newRating < 1 || newRating > 5)
        return false;

    rating = newRating;
    return true;
}

int Song::getDurationMinutes() const
{
    return durationSeconds / 60;
}

int Song::getRemainingSeconds() const
{
    return durationSeconds % 60;
}

bool Song::isLongerThan(const Song& other) const
{
    // other is passed by const reference: it is not copied and cannot be
    // modified by this function.
    return durationSeconds > other.durationSeconds;
}

void Song::display(std::ostream& output) const
{
    output << title << " by " << artist
           << " [" << getDurationMinutes() << ':';

    if (getRemainingSeconds() < 10)
        output << '0';

    output << getRemainingSeconds() << ']';

    if (rating == 0)
        output << " - not rated";
    else
        output << " - rating: " << rating << "/5";
}
