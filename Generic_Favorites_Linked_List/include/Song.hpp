#ifndef FAVORITES_SONG_HPP
#define FAVORITES_SONG_HPP

#include <iosfwd>
#include <string>

class Song
{
private:
    std::string title;
    std::string artist;
    int duration;

public:
    Song(const std::string& title, const std::string& artist, int duration);

    const std::string& getTitle() const;
    const std::string& getArtist() const;
    int getDuration() const;

    bool operator==(const Song& other) const;
};

std::ostream& operator<<(std::ostream& output, const Song& song);

#endif
