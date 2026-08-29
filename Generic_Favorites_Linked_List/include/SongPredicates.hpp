#ifndef SONG_PREDICATES_HPP
#define SONG_PREDICATES_HPP

#include "Song.hpp"

#include <string>

// A functor is an object that acts like a function because it implements
// operator(). Unlike a plain function, it can remember configuration data.
class ArtistMatches
{
private:
    std::string artist;

public:
    explicit ArtistMatches(const std::string& wantedArtist)
        : artist(wantedArtist)
    {
    }

    bool operator()(const Song& song) const
    {
        return song.getArtist() == artist;
    }
};

#endif
