#ifndef SMART_POINTERS_SONG_HPP
#define SMART_POINTERS_SONG_HPP

#include "MediaItem.hpp"

#include <string>

class Song : public MediaItem
{
private:
    std::string artist;
    int duration;

public:
    Song(const std::string& title, const std::string& artist, int duration);

    const std::string& getArtist() const;
    int getDuration() const;
    void display(std::ostream& output) const override;
};

#endif
