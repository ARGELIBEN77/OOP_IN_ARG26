#include "Playlist.hpp"

#include <cassert>
#include <ostream>
#include <stdexcept>
#include <utility>

Playlist::Playlist(std::string playlistName, std::size_t requestedCapacity)
    : name(std::move(playlistName)),
      songs(nullptr),
      count(0),
      capacity(requestedCapacity)
{
    if (name.empty())
        throw std::invalid_argument("Playlist name must not be empty");

    if (capacity == 0)
        capacity = initialCapacity;

    songs = new Song[capacity];
}

Playlist::Playlist(const Playlist& other)
    : name(other.name),
      songs(new Song[other.capacity]),
      count(other.count),
      capacity(other.capacity)
{
    // Copy every active Song into the new array. The two Playlist objects now
    // own different arrays and may be modified or destroyed independently.
    for (std::size_t index = 0; index < count; ++index)
        songs[index] = other.songs[index];
}

Playlist& Playlist::operator=(const Playlist& other)
{
    // Self-assignment must leave the object unchanged.
    if (this == &other)
        return *this;

    // Allocate and copy first. If allocation fails, the current Playlist still
    // owns its original valid array.
    Song* newSongs = new Song[other.capacity];
    for (std::size_t index = 0; index < other.count; ++index)
        newSongs[index] = other.songs[index];

    // Only after the new array is ready do we release the old resource.
    delete[] songs;

    name = other.name;
    songs = newSongs;
    count = other.count;
    capacity = other.capacity;

    // Returning *this by reference permits chained assignment: a = b = c.
    return *this;
}

Playlist::~Playlist()
{
    delete[] songs;
}

const std::string& Playlist::getName() const
{
    return name;
}

std::size_t Playlist::size() const
{
    return count;
}

std::size_t Playlist::getCapacity() const
{
    return capacity;
}

bool Playlist::empty() const
{
    return count == 0;
}

void Playlist::ensureCapacity()
{
    if (count < capacity)
        return;

    const std::size_t newCapacity = capacity * 2;
    Song* largerArray = new Song[newCapacity];

    for (std::size_t index = 0; index < count; ++index)
        largerArray[index] = songs[index];

    delete[] songs;
    songs = largerArray;
    capacity = newCapacity;
}

Playlist& Playlist::operator+=(const Song& song)
{
    ensureCapacity();
    songs[count] = song;
    ++count;
    return *this;
}

Song& Playlist::operator[](std::size_t index)
{
    // Bounds checking with exceptions belongs to the later exceptions unit.
    // For now, operator[] has the precondition index < size().
    assert(index < count);
    return songs[index];
}

const Song& Playlist::operator[](std::size_t index) const
{
    assert(index < count);
    return songs[index];
}

std::ostream& operator<<(std::ostream& output, const Playlist& playlist)
{
    output << "Playlist: " << playlist.getName()
           << " (" << playlist.size() << " songs)\n";

    for (std::size_t index = 0; index < playlist.size(); ++index)
        output << "  " << index + 1 << ". " << playlist[index] << '\n';

    return output;
}
