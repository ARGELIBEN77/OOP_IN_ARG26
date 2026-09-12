#include "MediaOrganizer.hpp"

#include <iostream>

int main() {
    MediaOrganizer organizer;
    organizer.addTrack(Track(101, "Northern Lights", "Maya", "Ambient", 245));
    organizer.addTrack(Track(102, "City Steps", "Noam", "Jazz", 198));
    organizer.addTrack(Track(103, "Quiet Room", "Maya", "Ambient", 310));

    std::cout << "Genres:\n";
    for (const auto& genre : organizer.getGenres()) {
        std::cout << "  " << genre << '\n';
    }

    std::cout << "\nTracks ordered by duration:\n";
    for (const auto& track : organizer.sortedByDuration()) {
        std::cout << "  " << track.getTitle() << " ("
                  << track.getDurationSeconds() << " seconds)\n";
    }

    organizer.enqueue(102);
    organizer.enqueue(101);
    std::cout << "\nNext track: "
              << organizer.findById(organizer.playNext()).getTitle() << '\n';
}
