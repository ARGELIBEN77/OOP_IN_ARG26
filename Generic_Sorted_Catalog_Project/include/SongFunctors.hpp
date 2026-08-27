#ifndef SONG_FUNCTORS_HPP
#define SONG_FUNCTORS_HPP

#include "Song.hpp"

#include <string>
#include <utility>

// A comparison functor controls the permanent ordering of a catalog.
struct CompareSongByTitle
{
    // Returning true means that first must appear before second.
    bool operator()(const Song& first, const Song& second) const
    {
        return first.getTitle() < second.getTitle();
    }
};

struct CompareSongByDuration
{
    // The container can be reused with a different ordering policy simply by
    // changing its Compare template argument.
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
    int minimumSeconds;

public:
    explicit LongerThan(int durationLimit)
        : minimumSeconds(durationLimit)
    {
    }

    bool operator()(const Song& song) const
    {
        return song.getDurationSeconds() > minimumSeconds;
    }
};

class ArtistIs
{
private:
    std::string requiredArtist;

public:
    explicit ArtistIs(std::string artistName)
        : requiredArtist(std::move(artistName))
    {
    }

    bool operator()(const Song& song) const
    {
        return song.getArtist() == requiredArtist;
    }
};

#endif
