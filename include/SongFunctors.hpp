#ifndef SONG_FUNCTORS_HPP
#define SONG_FUNCTORS_HPP

#include "Song.hpp"

#include <string>
#include <utility>

// A comparison functor controls the permanent ordering of a catalog.
struct CompareSongByTitle
{
    bool operator()(const Song& first, const Song& second) const
    {
        return first.getTitle() < second.getTitle();
    }
};

struct CompareSongByDuration
{
    bool operator()(const Song& first, const Song& second) const
    {
        return first.getDurationSeconds() < second.getDurationSeconds();
    }
};

// A predicate functor represents a yes/no question about one Song.
// It stores state, so different LongerThan objects may use different limits.
class LongerThan
{
private:
    int minimumSeconds_;

public:
    explicit LongerThan(int minimumSeconds)
        : minimumSeconds_(minimumSeconds)
    {
    }

    bool operator()(const Song& song) const
    {
        return song.getDurationSeconds() > minimumSeconds_;
    }
};

class ArtistIs
{
private:
    std::string artist_;

public:
    explicit ArtistIs(std::string artist)
        : artist_(std::move(artist))
    {
    }

    bool operator()(const Song& song) const
    {
        return song.getArtist() == artist_;
    }
};

#endif
