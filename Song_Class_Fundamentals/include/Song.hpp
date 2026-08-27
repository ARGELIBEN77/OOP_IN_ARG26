#ifndef SONG_HPP
#define SONG_HPP

#include <iosfwd>
#include <string>

// Song combines data and the operations that are allowed to use or modify it.
// The private section protects the object's state from uncontrolled access.
class Song
{
private:
    std::string title;
    std::string artist;
    int durationSeconds;
    int rating;

public:
    // There is intentionally no default constructor. A Song must be created
    // with the information needed to represent a meaningful song.
    Song(std::string title, std::string artist, int durationSeconds);

    // Getters are const because reading information does not change the Song.
    // Strings are returned by const reference to avoid unnecessary copying.
    const std::string& getTitle() const;
    const std::string& getArtist() const;
    int getDurationSeconds() const;
    int getRating() const;

    // A controlled modifying operation can validate a new value before
    // changing the private data. A rating of 0 means "not rated yet."
    bool setRating(int newRating);

    // These methods calculate or display information without changing state,
    // so they are also marked const.
    int getDurationMinutes() const;
    int getRemainingSeconds() const;
    bool isLongerThan(const Song& other) const;
    void display(std::ostream& output) const;
};

#endif
