#pragma once

#include "Track.hpp"

#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

class MediaOrganizer {
    // vector preserves playlist order and supports efficient indexed access.
    std::vector<Track> tracks;

    // map expresses lookup by a unique identifier.
    std::map<int, std::size_t> positionById;

    // set keeps each genre once and presents genres in sorted order.
    std::set<std::string> genres;

    // list models a queue where elements are removed from the front.
    std::list<int> playQueue;

public:
    void addTrack(const Track& track) {
        if (positionById.count(track.getId()) != 0) {
            throw std::invalid_argument("track id already exists");
        }

        positionById[track.getId()] = tracks.size();
        tracks.push_back(track);
        genres.insert(track.getGenre());
    }

    const Track& findById(int id) const {
        // find does not insert a missing key; operator[] would.
        auto position = positionById.find(id);
        if (position == positionById.end()) {
            throw std::out_of_range("track id not found");
        }
        return tracks.at(position->second);
    }

    std::vector<Track> sortedByDuration() const {
        auto result = tracks;
        std::sort(result.begin(), result.end(),
                  [](const Track& left, const Track& right) {
                      return left.getDurationSeconds() < right.getDurationSeconds();
                  });
        return result;
    }

    std::vector<Track> findByArtist(const std::string& artist) const {
        std::vector<Track> matches;
        std::copy_if(tracks.begin(), tracks.end(), std::back_inserter(matches),
                     [&artist](const Track& track) {
                         return track.getArtist() == artist;
                     });
        return matches;
    }

    std::size_t countLongerThan(int seconds) const {
        return static_cast<std::size_t>(std::count_if(
            tracks.begin(), tracks.end(),
            [seconds](const Track& track) {
                return track.getDurationSeconds() > seconds;
            }));
    }

    void enqueue(int id) {
        findById(id); // Validate before changing the queue.
        playQueue.push_back(id);
    }

    int playNext() {
        if (playQueue.empty()) {
            throw std::out_of_range("play queue is empty");
        }
        int id = playQueue.front();
        playQueue.pop_front();
        return id;
    }

    const std::vector<Track>& getTracks() const { return tracks; }
    const std::set<std::string>& getGenres() const { return genres; }
    std::size_t queueSize() const { return playQueue.size(); }
};
