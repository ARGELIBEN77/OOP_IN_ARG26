#ifndef MUSIC_LIBRARY_HPP
#define MUSIC_LIBRARY_HPP

#include <cstddef>
#include <iosfwd>
#include <vector>

class MediaItem;

// MusicLibrary stores different derived object types through one common base
// pointer type. The pointers are non-owning: the library observes the objects
// but does not create or delete them.
class MusicLibrary
{
private:
    std::vector<const MediaItem*> items;

public:
    // A reference makes the caller provide a real object. Its address is then
    // stored for later polymorphic calls.
    void add(const MediaItem& item);

    std::size_t size() const;

    // The same call expression is used for every item. Virtual dispatch chooses
    // Song::play, PodcastEpisode::play, or Audiobook::play at run time.
    void playAll() const;
    void printAll(std::ostream& output) const;
};

#endif
