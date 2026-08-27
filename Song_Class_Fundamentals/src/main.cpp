#include "Song.hpp"

#include <iostream>

// Passing by const reference avoids copying and allows this function to work
// with const and non-const Song objects.
void printSong(const Song& song)
{
    song.display(std::cout);
    std::cout << '\n';
}

int main()
{
    std::cout << "Song Class Fundamentals\n\n";

    // Each object is initialized through the constructor. Client code cannot
    // assign directly to title, artist, durationSeconds, or rating.
    Song imagine("Imagine", "John Lennon", 183);
    const Song yesterday("Yesterday", "The Beatles", 125);

    printSong(imagine);
    printSong(yesterday);

    // Modification is performed through a public operation that checks the
    // requested value before changing the private member.
    if (imagine.setRating(5))
        std::cout << "\nRating accepted.\n";

    if (!imagine.setRating(8))
        std::cout << "Rating 8 rejected; the valid range is 1 to 5.\n";

    printSong(imagine);

    std::cout << "\nIs Imagine longer than Yesterday? "
              << (imagine.isLongerThan(yesterday) ? "yes" : "no")
              << '\n';

    return 0;
}
