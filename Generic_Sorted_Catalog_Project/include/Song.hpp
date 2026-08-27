#ifndef SONG_HPP
#define SONG_HPP

#include <iosfwd>
#include <string>

// A small domain class keeps the project focused on generic programming.
// SortedCatalog is not coupled to Song; Song is only one possible T.
class Song
{
private:
    std::string title_;
    std::string artist_;
    int durationSeconds_;

public:
    Song(std::string title, std::string artist, int durationSeconds);

    const std::string& getTitle() const;
    const std::string& getArtist() const;
    int getDurationSeconds() const;

    void play() const;
};

std::ostream& operator<<(std::ostream& out, const Song& song);

#endif
