#ifndef SHARED_PLAYLIST_HPP
#define SHARED_PLAYLIST_HPP

#include "Song.hpp"

#include <cstddef>
#include <iosfwd>
#include <memory>
#include <string>
#include <vector>

// A Playlist shares ownership of Song objects. The same Song may therefore
// remain alive while it is present in one or more playlists.
class Playlist
{
private:
    std::string name;
    std::vector<std::shared_ptr<Song>> songs;

public:
    explicit Playlist(const std::string& name);

    // Passing shared_ptr by value creates ownership for this operation. Moving
    // that local copy into the vector avoids one additional reference update.
    void addSong(std::shared_ptr<Song> song);

    const std::string& getName() const;
    std::size_t size() const;
    const Song& getSong(std::size_t index) const;
    void display(std::ostream& output) const;
};

#endif
