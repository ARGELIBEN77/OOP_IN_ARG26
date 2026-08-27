#include "Playlist.hpp"
#include "Song.hpp"

#include <iostream>

int main()
{
    std::cout << "Rule of Three and Operator Overloading Demonstration\n\n";

    const Song imagine("Imagine", "John Lennon", 183);
    const Song one("One", "U2", 217);
    const Song yesterday("Yesterday", "The Beatles", 125);

    // operator+= modifies the left operand and returns it by reference.
    Playlist favorites("Favorites", 2);
    favorites += imagine;
    favorites += one;
    favorites += yesterday; // Causes the dynamic array to grow.

    // operator<< makes Playlist work naturally with an output stream.
    std::cout << favorites << '\n';

    // The copy constructor creates a new independent dynamic array.
    Playlist copiedPlaylist(favorites);
    copiedPlaylist[0] = Song("Hallelujah", "Leonard Cohen", 282);

    std::cout << "Original after modifying its copy:\n";
    std::cout << favorites << '\n';
    std::cout << "Modified copy:\n";
    std::cout << copiedPlaylist << '\n';

    // Copy assignment must release assignedPlaylist's previous array and then
    // create a deep copy of favorites.
    Playlist assignedPlaylist("Temporary");
    assignedPlaylist += Song("Temporary Song", "Unknown", 60);
    assignedPlaylist = favorites;

    std::cout << "Assigned playlist:\n";
    std::cout << assignedPlaylist;

    // Related Song operators reuse one central definition of equality.
    std::cout << "\nAre Imagine and One equal? "
              << (imagine == one ? "yes" : "no") << '\n';

    return 0;
}
