#include "MediaItem.hpp"
#include "MediaLibrary.hpp"
#include "Playlist.hpp"
#include "Song.hpp"

#include <cassert>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <utility>

void testUniqueOwnershipTransfer()
{
    int startingCount = MediaItem::getLivingObjectCount();

    {
        MediaLibrary library;
        auto song = std::make_unique<Song>("One", "U2", 276);

        assert(song != nullptr);
        assert(MediaItem::getLivingObjectCount() == startingCount + 1);

        library.addItem(std::move(song));

        assert(song == nullptr);
        assert(library.size() == 1);
        assert(library.getItem(0).getTitle() == "One");

        std::ostringstream output;
        library.displayAll(output);
        assert(output.str().find("One by U2") != std::string::npos);
    }

    assert(MediaItem::getLivingObjectCount() == startingCount);
}

void testSharedOwnership()
{
    int startingCount = MediaItem::getLivingObjectCount();

    {
        auto song = std::make_shared<Song>("Africa", "Toto", 295);
        assert(song.use_count() == 1);

        Playlist favorites("Favorites");
        Playlist roadTrip("Road Trip");

        favorites.addSong(song);
        assert(song.use_count() == 2);

        roadTrip.addSong(song);
        assert(song.use_count() == 3);

        song.reset();

        assert(favorites.getSong(0).getTitle() == "Africa");
        assert(roadTrip.getSong(0).getTitle() == "Africa");
        assert(MediaItem::getLivingObjectCount() == startingCount + 1);
    }

    assert(MediaItem::getLivingObjectCount() == startingCount);
}

void testNullPointersAreRejected()
{
    MediaLibrary library;
    bool libraryExceptionCaught = false;

    try
    {
        library.addItem(nullptr);
    }
    catch (const std::invalid_argument&)
    {
        libraryExceptionCaught = true;
    }

    assert(libraryExceptionCaught);

    Playlist playlist("Favorites");
    bool playlistExceptionCaught = false;

    try
    {
        playlist.addSong(nullptr);
    }
    catch (const std::invalid_argument&)
    {
        playlistExceptionCaught = true;
    }

    assert(playlistExceptionCaught);
}

void testBoundsChecking()
{
    MediaLibrary library;
    bool exceptionCaught = false;

    try
    {
        library.getItem(0);
    }
    catch (const std::out_of_range&)
    {
        exceptionCaught = true;
    }

    assert(exceptionCaught);
}

int main()
{
    testUniqueOwnershipTransfer();
    testSharedOwnership();
    testNullPointersAreRejected();
    testBoundsChecking();

    assert(MediaItem::getLivingObjectCount() == 0);
    std::cout << "All smart-pointer tests passed.\n";
    return 0;
}
