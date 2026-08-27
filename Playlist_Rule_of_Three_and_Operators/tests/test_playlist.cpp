#include "Playlist.hpp"
#include "Song.hpp"

#include <cassert>
#include <sstream>
#include <string>

namespace
{
Playlist makePlaylist()
{
    Playlist playlist("Test Playlist", 2);
    playlist += Song("Imagine", "John Lennon", 183);
    playlist += Song("One", "U2", 217);
    playlist += Song("Yesterday", "The Beatles", 125);
    return playlist;
}

void testGrowthAndIndexing()
{
    Playlist playlist = makePlaylist();

    assert(playlist.size() == 3);
    assert(playlist.getCapacity() >= 3);
    assert(playlist[0].getTitle() == "Imagine");
    assert(playlist[2].getTitle() == "Yesterday");
}

void testCopyConstructorMakesDeepCopy()
{
    Playlist original = makePlaylist();
    Playlist copy(original);

    copy[0] = Song("Changed", "Different Artist", 200);

    // Changing the copy must not change the separately allocated original.
    assert(copy[0].getTitle() == "Changed");
    assert(original[0].getTitle() == "Imagine");
}

void testCopyAssignmentMakesDeepCopy()
{
    Playlist original = makePlaylist();
    Playlist assigned("Before Assignment");
    assigned += Song("Old Song", "Old Artist", 100);

    assigned = original;
    assigned[1] = Song("Changed Again", "Different Artist", 210);

    assert(assigned.getName() == original.getName());
    assert(assigned.size() == original.size());
    assert(original[1].getTitle() == "One");
}

void testSelfAssignment()
{
    Playlist playlist = makePlaylist();
    playlist = playlist;

    assert(playlist.size() == 3);
    assert(playlist[0].getTitle() == "Imagine");
}

void testSongOperators()
{
    const Song first("Imagine", "John Lennon", 183);
    const Song same("Imagine", "John Lennon", 183);
    const Song different("One", "U2", 217);

    assert(first == same);
    assert(first != different);
    assert(first < different);
}

void testStreamOperator()
{
    const Playlist playlist = makePlaylist();
    std::ostringstream output;
    output << playlist;

    assert(output.str().find("Playlist: Test Playlist") != std::string::npos);
    assert(output.str().find("Imagine by John Lennon") != std::string::npos);
}
}

int main()
{
    testGrowthAndIndexing();
    testCopyConstructorMakesDeepCopy();
    testCopyAssignmentMakesDeepCopy();
    testSelfAssignment();
    testSongOperators();
    testStreamOperator();
    return 0;
}
