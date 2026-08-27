#include <iostream>
#include <string>

// In the procedural version, the data is public and separate functions operate
// on it. Any part of the program may change any field to any value.
struct SongData
{
    std::string title;
    std::string artist;
    int durationSeconds;
    int rating;
};

void displaySong(const SongData& song)
{
    std::cout << song.title << " by " << song.artist
              << " (" << song.durationSeconds << " seconds)"
              << " - rating: " << song.rating << '\n';
}

int main()
{
    SongData song{"Imagine", "John Lennon", 183, 5};
    displaySong(song);

    // Both assignments compile because every field is public. The struct cannot
    // protect its own rules, so invalid state is easy to create accidentally.
    song.durationSeconds = -20;
    song.rating = 100;

    std::cout << "After uncontrolled modification:\n";
    displaySong(song);
    return 0;
}
