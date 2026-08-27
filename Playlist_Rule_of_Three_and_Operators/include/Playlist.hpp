#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include "Song.hpp"

#include <cstddef>
#include <iosfwd>
#include <string>

// Playlist owns a dynamically allocated array. Because the compiler-generated
// copy operations would copy only the pointer, Playlist implements the Rule of
// Three: destructor, copy constructor, and copy assignment operator.
class Playlist
{
private:
    std::string name;
    Song* songs;
    std::size_t count;
    std::size_t capacity;

    static constexpr std::size_t initialCapacity = 4;

    // Allocate a larger array when the current array becomes full.
    void ensureCapacity();

public:
    explicit Playlist(std::string name,
                      std::size_t capacity = initialCapacity);

    // Rule of Three member 1: create an independent copy of other's array.
    Playlist(const Playlist& other);

    // Rule of Three member 2: replace the current resource with a deep copy.
    Playlist& operator=(const Playlist& other);

    // Rule of Three member 3: release the owned array exactly once.
    ~Playlist();

    const std::string& getName() const;
    std::size_t size() const;
    std::size_t getCapacity() const;
    bool empty() const;

    // += naturally means adding one Song to the end of this Playlist.
    Playlist& operator+=(const Song& song);

    // Both overloads return references to the actual stored Song. The const
    // version prevents modification when the Playlist itself is const.
    Song& operator[](std::size_t index);
    const Song& operator[](std::size_t index) const;
};

// Print a complete playlist without granting direct access to private data.
std::ostream& operator<<(std::ostream& output, const Playlist& playlist);

#endif
