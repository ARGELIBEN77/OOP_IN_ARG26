#include "Playlist.hpp"

#include <ostream>
#include <stdexcept>
#include <utility>

Playlist::Playlist(const std::string& name)
    : name(name)
{
    if (name.empty())
        throw std::invalid_argument("Playlist name cannot be empty");
}

void Playlist::addSong(std::shared_ptr<Song> song)
{
    if (song == nullptr)
        throw std::invalid_argument("Cannot add an empty song pointer");

    songs.push_back(std::move(song));
}

const std::string& Playlist::getName() const
{
    return name;
}

std::size_t Playlist::size() const
{
    return songs.size();
}

const Song& Playlist::getSong(std::size_t index) const
{
    if (index >= songs.size())
        throw std::out_of_range("Playlist index is out of range");

    return *songs[index];
}

void Playlist::display(std::ostream& output) const
{
    output << name << ":\n";

    for (const auto& song : songs)
    {
        output << "  ";
        song->display(output);
        output << '\n';
    }
}
