#include "MediaItem.hpp"
#include "MediaLibrary.hpp"
#include "Playlist.hpp"
#include "Song.hpp"

#include <iostream>
#include <memory>
#include <utility>

int main()
{
    std::cout << std::boolalpha;
    std::cout << "Living media objects at the beginning: "
              << MediaItem::getLivingObjectCount() << "\n\n";

    {
        std::cout << "Exclusive ownership with unique_ptr:\n";

        MediaLibrary library;
        auto song = std::make_unique<Song>("One", "U2", 276);

        std::cout << "Before transfer, the caller owns the song: "
                  << (song != nullptr) << '\n';

        library.addItem(std::move(song));

        std::cout << "After transfer, the caller owns the song: "
                  << (song != nullptr) << '\n';
        std::cout << "The library now contains:\n";
        library.displayAll(std::cout);
    }

    std::cout << "Living objects after the library leaves scope: "
              << MediaItem::getLivingObjectCount() << "\n\n";

    {
        std::cout << "Shared ownership with shared_ptr:\n";

        auto sharedSong =
            std::make_shared<Song>("Beautiful Day", "U2", 248);

        Playlist favorites("Favorites");
        Playlist roadTrip("Road Trip");

        favorites.addSong(sharedSong);
        roadTrip.addSong(sharedSong);

        std::cout << "Owners after adding the song to two playlists: "
                  << sharedSong.use_count() << '\n';

        // Releasing this owner's pointer leaves the two playlist owners.
        sharedSong.reset();

        std::cout << "The song remains available in both playlists:\n";
        favorites.display(std::cout);
        roadTrip.display(std::cout);
    }

    std::cout << "\nLiving media objects at the end: "
              << MediaItem::getLivingObjectCount() << '\n';
    return 0;
}
