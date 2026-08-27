#include "Algorithms.hpp"
#include "Song.hpp"
#include "SongFunctors.hpp"
#include "SortedCatalog.hpp"

#include <cassert>
#include <iostream>
#include <string>

namespace
{
SortedCatalog<Song, CompareSongByTitle> makeCatalog()
{
    SortedCatalog<Song, CompareSongByTitle> catalog(CompareSongByTitle{});
    catalog.add(Song("One", "U2", 217));
    catalog.add(Song("Imagine", "John Lennon", 183));
    catalog.add(Song("Beautiful Day", "U2", 248));
    return catalog;
}

void testSortedInsertion()
{
    const auto catalog = makeCatalog();

    assert(catalog.size() == 3);
    assert(catalog.at(0).getTitle() == "Beautiful Day");
    assert(catalog.at(1).getTitle() == "Imagine");
    assert(catalog.at(2).getTitle() == "One");
}

void testIteratorTraversal()
{
    const auto catalog = makeCatalog();
    std::string titles;

    for (auto iterator = catalog.begin(); iterator != catalog.end(); ++iterator)
        titles += iterator->getTitle() + ";";

    assert(titles == "Beautiful Day;Imagine;One;");
}

void testGenericAlgorithms()
{
    const auto catalog = makeCatalog();

    const auto u2Count = teaching::countIf(
        catalog.begin(), catalog.end(), ArtistIs("U2"));
    assert(u2Count == 2);

    const auto found = teaching::findFirst(
        catalog.begin(),
        catalog.end(),
        [](const Song& song)
        {
            return song.getDurationSeconds() > 240;
        });

    assert(found != catalog.end());
    assert(found->getTitle() == "Beautiful Day");
}

void testEquivalentRemoval()
{
    auto catalog = makeCatalog();
    const Song sameTitle("Imagine", "Different Artist", 300);

    // CompareSongByTitle defines equivalence only by title.
    assert(catalog.containsEquivalent(sameTitle));
    assert(catalog.removeFirstEquivalent(sameTitle));
    assert(!catalog.containsEquivalent(sameTitle));
    assert(catalog.size() == 2);
}

void testEmptyRange()
{
    const SortedCatalog<Song, CompareSongByTitle> empty(CompareSongByTitle{});
    assert(empty.begin() == empty.end());
    assert(empty.empty());
}
}

int main()
{
    testSortedInsertion();
    testIteratorTraversal();
    testGenericAlgorithms();
    testEquivalentRemoval();
    testEmptyRange();

    std::cout << "All SortedCatalog tests passed.\n";
    return 0;
}
