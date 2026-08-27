#ifndef SONG_HPP
#define SONG_HPP

#include "MediaItem.hpp"

#include <string>

// Song is-a MediaItem. It inherits the title and duration behavior and adds
// the information that belongs only to songs.
class Song : public MediaItem
{
private:
    std::string artist;

public:
    Song(std::string title, int durationSeconds, std::string artist);

    const std::string& getArtist() const;

    // override asks the compiler to verify that these signatures exactly
    // match virtual functions declared in MediaItem.
    void play() const override;
    void printDetails(std::ostream& output) const override;
};

#endif
