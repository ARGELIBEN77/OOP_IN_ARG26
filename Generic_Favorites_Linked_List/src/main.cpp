#include "Algorithms.hpp"
#include "FavoritesList.hpp"
#include "Song.hpp"
#include "SongPredicates.hpp"

#include <iostream>
#include <string>

int main()
{
    FavoritesList<Song> favoriteSongs;

    favoriteSongs.add(Song("One", "U2", 276));
    favoriteSongs.add(Song("Africa", "Toto", 295));
    favoriteSongs.add(Song("Beautiful Day", "U2", 248));
    favoriteSongs.add(Song("Dreams", "Fleetwood Mac", 257));

    std::cout << "Favorite songs in insertion order:\n";

    // A range-based for loop calls begin(), compares with end(), increments
    // the iterator, and dereferences it behind the scenes.
    for (const Song& song : favoriteSongs)
        std::cout << "  " << song << '\n';

    ArtistMatches isByU2("U2");
    std::size_t u2Count = teaching::countIf(
        favoriteSongs.begin(), favoriteSongs.end(), isByU2);

    std::cout << "\nSongs by U2: " << u2Count << '\n';

    int minimumDuration = 270;

    // The lambda captures minimumDuration so the condition can be chosen at
    // runtime without defining another named class.
    auto longSong = [minimumDuration](const Song& song)
    {
        return song.getDuration() >= minimumDuration;
    };

    auto found = teaching::findFirst(
        favoriteSongs.begin(), favoriteSongs.end(), longSong);

    if (found != favoriteSongs.end())
        std::cout << "First song lasting at least " << minimumDuration
                  << " seconds: " << *found << '\n';

    std::cout << "\nTitles through a generic action:\n";
    teaching::forEach(
        favoriteSongs.begin(), favoriteSongs.end(),
        [](const Song& song)
        {
            std::cout << "  " << song.getTitle() << '\n';
        });

    // The same class template can create a completely different list type.
    FavoritesList<std::string> favoriteGenres;
    favoriteGenres.add("Rock");
    favoriteGenres.add("Jazz");

    std::cout << "\nFavorite genres:\n";
    for (const std::string& genre : favoriteGenres)
        std::cout << "  " << genre << '\n';

    return 0;
}
