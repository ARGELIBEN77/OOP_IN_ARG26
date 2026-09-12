#include "MediaOrganizer.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>

int main() {
    MediaOrganizer organizer;
    organizer.addTrack(Track(1, "Long", "A", "Rock", 300));
    organizer.addTrack(Track(2, "Short", "B", "Jazz", 120));
    organizer.addTrack(Track(3, "Middle", "A", "Rock", 200));

    assert(organizer.getTracks().size() == 3);
    assert(organizer.getGenres().size() == 2);
    assert(organizer.findById(2).getTitle() == "Short");
    assert(organizer.countLongerThan(180) == 2);
    assert(organizer.findByArtist("A").size() == 2);

    auto sorted = organizer.sortedByDuration();
    assert(sorted[0].getId() == 2);
    assert(sorted[1].getId() == 3);
    assert(sorted[2].getId() == 1);

    organizer.enqueue(3);
    organizer.enqueue(1);
    assert(organizer.queueSize() == 2);
    assert(organizer.playNext() == 3);

    bool duplicateRejected = false;
    try {
        organizer.addTrack(Track(1, "Duplicate", "C", "Pop", 90));
    } catch (const std::invalid_argument&) {
        duplicateRejected = true;
    }
    assert(duplicateRejected);

    bool missingRejected = false;
    try {
        organizer.findById(99);
    } catch (const std::out_of_range&) {
        missingRejected = true;
    }
    assert(missingRejected);

    std::cout << "All STL Media Organizer tests passed.\n";
}
