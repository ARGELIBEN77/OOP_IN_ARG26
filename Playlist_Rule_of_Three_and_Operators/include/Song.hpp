#ifndef SONG_HPP
#define SONG_HPP

#include <iosfwd>
#include <string>

class Song
{
private:
    std::string title;
    std::string artist;
    int durationSeconds;

public:
    // A default constructor is needed because Playlist allocates an array of
    // Song objects before all positions contain real songs.
    Song();
    Song(std::string title, std::string artist, int durationSeconds);

    const std::string& getTitle() const;
    const std::string& getArtist() const;
    int getDurationSeconds() const;

    // Equality compares all three data members.
    bool operator==(const Song& other) const;
    bool operator!=(const Song& other) const;

    // The natural ordering used here is title, then artist, then duration.
    bool operator<(const Song& other) const;
};

// operator<< is non-member because the stream is the left operand. It uses
// Song's public getters, so friendship is unnecessary.
std::ostream& operator<<(std::ostream& output, const Song& song);

#endif
