#ifndef SONG_HPP
#define SONG_HPP

#include <iosfwd>
#include <string>

// A small domain class keeps the project focused on generic programming.
// SortedCatalog is not coupled to Song; Song is only one possible T.
class Song
{
private:
    std::string title;
    std::string artist;
    int durationSeconds;

public:
    // The constructor establishes the invariant that every Song has a title
    // and a positive duration.
    Song(std::string title, std::string artist, int durationSeconds);

    // Getters return read-only information. The strings are returned by const
    // reference to avoid making unnecessary copies.
    const std::string& getTitle() const;
    const std::string& getArtist() const;
    int getDurationSeconds() const;

    void play() const;
};

// Stream insertion lets the same printing code work for every Song.
std::ostream& operator<<(std::ostream& output, const Song& song);

#endif
