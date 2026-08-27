#include "Algorithms.hpp"
#include "Song.hpp"
#include "SongFunctors.hpp"
#include "SortedCatalog.hpp"

#include <algorithm>
#include <iostream>
#include <string>

namespace
{
template <typename Catalog>
void printCatalog(const std::string& heading, const Catalog& catalog)
{
    std::cout << "\n" << heading << '\n';
    std::cout << std::string(heading.size(), '-') << '\n';

    // A range-based for loop asks the catalog for begin() and end(), then uses
    // the iterator's !=, *, and ++ operators behind the scenes.
    for (const auto& item : catalog)
        std::cout << item << '\n';
}
}

int main()
{
    std::cout << "Generic Sorted Catalog Demonstration\n";

    // The first catalog uses a named functor as its comparison policy.
    SortedCatalog<Song, CompareSongByTitle> byTitle(CompareSongByTitle{});

    byTitle.add(Song("Imagine", "John Lennon", 183));
    byTitle.add(Song("One", "U2", 217));
    byTitle.add(Song("Hallelujah", "Leonard Cohen", 282));
    byTitle.add(Song("Beautiful Day", "U2", 248));
    byTitle.add(Song("Yesterday", "The Beatles", 125));

    printCatalog("Songs ordered by title", byTitle);

    // A predicate lambda is convenient for a condition used in one location.
    // minimumDuration is captured by value, so the closure stores its own copy.
    const int minimumDuration = 240;
    auto firstLongSong = teaching::findFirst(
        byTitle.begin(),
        byTitle.end(),
        [minimumDuration](const Song& song)
        {
            return song.getDurationSeconds() > minimumDuration;
        });

    if (firstLongSong != byTitle.end())
        std::cout << "\nFirst song longer than " << minimumDuration
                  << " seconds: " << *firstLongSong << '\n';

    // The same generic algorithm also accepts a named, stateful functor.
    const std::size_t u2Songs = teaching::countIf(
        byTitle.begin(), byTitle.end(), ArtistIs("U2"));

    std::cout << "Number of U2 songs: " << u2Songs << '\n';

    // Action lambdas need not return bool. This one calls a member function.
    std::cout << "\nPlaying every song through a generic forEach algorithm:\n";
    teaching::forEach(
        byTitle.begin(),
        byTitle.end(),
        [](const Song& song)
        {
            song.play();
        });

    // Every lambda has a unique compiler-generated type. decltype supplies
    // that unnamed type as the Compare template argument.
    auto byArtistThenTitle = [](const Song& first, const Song& second)
    {
        if (first.getArtist() != second.getArtist())
            return first.getArtist() < second.getArtist();

        return first.getTitle() < second.getTitle();
    };

    SortedCatalog<Song, decltype(byArtistThenTitle)> byArtist(
        byArtistThenTitle);

    // Copy the Songs from one container into another. The destination applies
    // its own comparison policy, so its final order is different.
    for (const Song& song : byTitle)
        byArtist.add(song);

    printCatalog("Songs ordered by artist and then title", byArtist);

    // Explicit iterator syntax exposes what the range-based loop abbreviates.
    std::cout << "\nExplicit iterator traversal:\n";
    for (auto iterator = byArtist.begin();
         iterator != byArtist.end();
         ++iterator)
    {
        std::cout << iterator->getArtist()
                  << " - " << iterator->getTitle() << '\n';
    }

    // A standard algorithm can use the custom iterator because it satisfies
    // the forward-iterator operations and supplies iterator trait aliases.
    const auto standardCount = std::count_if(
        byArtist.begin(),
        byArtist.end(),
        LongerThan(200));

    std::cout << "\nstd::count_if found " << standardCount
              << " songs longer than 200 seconds.\n";

    return 0;
}
