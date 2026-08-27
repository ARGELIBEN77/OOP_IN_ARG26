#include "Audiobook.hpp"
#include "MusicLibrary.hpp"
#include "PodcastEpisode.hpp"
#include "Song.hpp"

#include <cassert>
#include <sstream>
#include <string>
#include <type_traits>

namespace
{
void testAbstractBaseClass()
{
    // MediaItem cannot be instantiated because play is pure virtual.
    static_assert(std::is_abstract<MediaItem>::value,
                  "MediaItem should remain abstract");
}

void testSharedBaseState()
{
    const Song song("Imagine", 183, "John Lennon");

    assert(song.getTitle() == "Imagine");
    assert(song.getDurationSeconds() == 183);
    assert(song.getArtist() == "John Lennon");
}

void testPolymorphicDetails()
{
    const Song song("Imagine", 183, "John Lennon");
    const PodcastEpisode podcast("Virtual Functions", 1200, "C++ Class", 4);
    const Audiobook book("The Little Prince", 5400, "Saint-Exupery", "Nora");

    MusicLibrary library;
    library.add(song);
    library.add(podcast);
    library.add(book);

    std::ostringstream output;
    library.printAll(output);
    const std::string text = output.str();

    // Each derived override appends different information even though
    // MusicLibrary calls printDetails through MediaItem pointers.
    assert(text.find("artist: John Lennon") != std::string::npos);
    assert(text.find("podcast: C++ Class") != std::string::npos);
    assert(text.find("author: Saint-Exupery") != std::string::npos);
    assert(library.size() == 3);
}

void testVirtualDestructor()
{
    static_assert(std::has_virtual_destructor<MediaItem>::value,
                  "A polymorphic base class needs a virtual destructor");
}
}

int main()
{
    testAbstractBaseClass();
    testSharedBaseState();
    testPolymorphicDetails();
    testVirtualDestructor();
    return 0;
}
