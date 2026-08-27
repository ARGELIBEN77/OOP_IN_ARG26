#include "Audiobook.hpp"
#include "MusicLibrary.hpp"
#include "PodcastEpisode.hpp"
#include "Song.hpp"

#include <iostream>

int main()
{
    std::cout << "Inheritance and Runtime Polymorphism Demonstration\n";

    // These are complete derived objects stored directly on the stack.
    Song song("Imagine", 183, "John Lennon");
    PodcastEpisode podcast("Why Virtual Functions Matter",
                           1500,
                           "C++ Classroom",
                           7);
    Audiobook book("The Little Prince",
                   5400,
                   "Antoine de Saint-Exupery",
                   "Sample Narrator");

    // Create the library after the media objects. Local objects are destroyed
    // in reverse order, so the non-owning library disappears before them.
    MusicLibrary library;
    library.add(song);
    library.add(podcast);
    library.add(book);

    std::cout << "\nLibrary contents\n";
    std::cout << "----------------\n";
    library.printAll(std::cout);

    std::cout << "\nPlaying all items\n";
    std::cout << "-----------------\n";

    // playAll does not use if statements or type checks. Dynamic binding
    // selects the correct override from the object's real run-time type.
    library.playAll();

    // A base reference can refer to any derived object without copying it.
    // This preserves the complete object and avoids object slicing.
    const MediaItem& selectedItem = podcast;
    std::cout << "\nSelected through a MediaItem reference:\n";
    selectedItem.play();

    return 0;
}
