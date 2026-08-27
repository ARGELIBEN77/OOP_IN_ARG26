#include "Song.hpp"

#include <cassert>
#include <sstream>
#include <string>

namespace
{
void testConstructorAndGetters()
{
    const Song song("Imagine", "John Lennon", 183);

    assert(song.getTitle() == "Imagine");
    assert(song.getArtist() == "John Lennon");
    assert(song.getDurationSeconds() == 183);
    assert(song.getRating() == 0);
}

void testControlledRatingChange()
{
    Song song("Imagine", "John Lennon", 183);

    assert(song.setRating(5));
    assert(song.getRating() == 5);

    // An invalid request is rejected and the previous valid state remains.
    assert(!song.setRating(7));
    assert(song.getRating() == 5);
}

void testConstCalculations()
{
    const Song song("Imagine", "John Lennon", 183);

    assert(song.getDurationMinutes() == 3);
    assert(song.getRemainingSeconds() == 3);
}

void testObjectComparisonMethod()
{
    const Song longer("Imagine", "John Lennon", 183);
    const Song shorter("Yesterday", "The Beatles", 125);

    assert(longer.isLongerThan(shorter));
    assert(!shorter.isLongerThan(longer));
}

void testDisplay()
{
    Song song("Imagine", "John Lennon", 183);
    song.setRating(5);

    std::ostringstream output;
    song.display(output);

    assert(output.str() == "Imagine by John Lennon [3:03] - rating: 5/5");
}
}

int main()
{
    testConstructorAndGetters();
    testControlledRatingChange();
    testConstCalculations();
    testObjectComparisonMethod();
    testDisplay();
    return 0;
}
