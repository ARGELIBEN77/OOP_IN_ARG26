#pragma once

#include <string>
#include <utility>

class Track {
    int id;
    std::string title;
    std::string artist;
    std::string genre;
    int durationSeconds;

public:
    Track(int id, std::string title, std::string artist,
          std::string genre, int durationSeconds)
        : id(id), title(std::move(title)), artist(std::move(artist)),
          genre(std::move(genre)), durationSeconds(durationSeconds) {}

    int getId() const { return id; }
    const std::string& getTitle() const { return title; }
    const std::string& getArtist() const { return artist; }
    const std::string& getGenre() const { return genre; }
    int getDurationSeconds() const { return durationSeconds; }
};
