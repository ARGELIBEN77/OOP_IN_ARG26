#include "Algorithms.hpp"
#include "FavoritesList.hpp"
#include "Song.hpp"
#include "SongPredicates.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

void testEmptyList()
{
    FavoritesList<int> values;

    assert(values.empty());
    assert(values.size() == 0);
    assert(values.begin() == values.end());

    bool exceptionCaught = false;
    try
    {
        values.front();
    }
    catch (const std::out_of_range&)
    {
        exceptionCaught = true;
    }

    assert(exceptionCaught);
}

void testAddingAndIteration()
{
    FavoritesList<int> values;
    values.add(10);
    values.add(20);
    values.add(30);

    assert(!values.empty());
    assert(values.size() == 3);
    assert(values.front() == 10);

    int expected[] = {10, 20, 30};
    int index = 0;

    for (int value : values)
    {
        assert(value == expected[index]);
        ++index;
    }

    assert(index == 3);
}

void testRemovingElements()
{
    FavoritesList<std::string> values;
    values.add("first");
    values.add("middle");
    values.add("last");

    assert(values.removeFirst("first"));
    assert(values.front() == "middle");
    assert(values.removeFirst("last"));
    assert(values.size() == 1);
    assert(!values.removeFirst("missing"));
    assert(values.removeFirst("middle"));
    assert(values.empty());

    // Verify that adding still works after removing the final node.
    values.add("new");
    assert(values.front() == "new");
}

void testDeepCopy()
{
    FavoritesList<int> original;
    original.add(1);
    original.add(2);

    FavoritesList<int> copied(original);
    copied.front() = 100;

    assert(original.front() == 1);
    assert(copied.front() == 100);

    FavoritesList<int> assigned;
    assigned.add(999);
    assigned = original;
    assigned.removeFirst(1);

    assert(original.size() == 2);
    assert(assigned.size() == 1);
    assert(assigned.front() == 2);

    original = original;
    assert(original.size() == 2);
}

void testAlgorithmsAndPredicates()
{
    FavoritesList<Song> songs;
    songs.add(Song("One", "U2", 276));
    songs.add(Song("Africa", "Toto", 295));
    songs.add(Song("Beautiful Day", "U2", 248));

    assert(teaching::countIf(
               songs.begin(), songs.end(), ArtistMatches("U2")) == 2);

    int duration = 290;
    auto found = teaching::findFirst(
        songs.begin(), songs.end(),
        [duration](const Song& song)
        {
            return song.getDuration() >= duration;
        });

    assert(found != songs.end());
    assert(found->getTitle() == "Africa");

    int totalDuration = 0;
    teaching::forEach(
        songs.begin(), songs.end(),
        [&totalDuration](const Song& song)
        {
            totalDuration += song.getDuration();
        });

    assert(totalDuration == 819);
}

int main()
{
    testEmptyList();
    testAddingAndIteration();
    testRemovingElements();
    testDeepCopy();
    testAlgorithmsAndPredicates();

    std::cout << "All FavoritesList tests passed.\n";
    return 0;
}
