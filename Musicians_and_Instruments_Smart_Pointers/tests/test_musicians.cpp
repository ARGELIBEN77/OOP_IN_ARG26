#include "Ensemble.hpp"
#include "Instrument.hpp"
#include "Musician.hpp"

#include <cassert>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

void testExclusiveInstrumentTransfer()
{
    int startingInstruments = Instrument::getLivingObjectCount();
    int startingMusicians = Musician::getLivingObjectCount();

    {
        Musician first("Noa");
        Musician second("Daniel");
        auto guitar = std::make_unique<Instrument>("Guitar");

        assert(Instrument::getLivingObjectCount() == startingInstruments + 1);
        assert(Musician::getLivingObjectCount() == startingMusicians + 2);

        first.receiveInstrument(std::move(guitar));
        assert(guitar == nullptr);
        assert(first.hasInstrument());

        auto transferred = first.releaseInstrument();
        assert(!first.hasInstrument());
        assert(transferred != nullptr);

        second.receiveInstrument(std::move(transferred));
        assert(transferred == nullptr);
        assert(second.getInstrument().getName() == "Guitar");
    }

    assert(Instrument::getLivingObjectCount() == startingInstruments);
    assert(Musician::getLivingObjectCount() == startingMusicians);
}

void testSharedGuestMusician()
{
    int startingInstruments = Instrument::getLivingObjectCount();
    int startingMusicians = Musician::getLivingObjectCount();

    {
        auto guest = std::make_shared<Musician>("Maya");
        guest->receiveInstrument(std::make_unique<Instrument>("Violin"));

        assert(guest.use_count() == 1);

        Ensemble first("Chamber Group");
        Ensemble second("Studio Group");

        first.addMusician(guest);
        assert(guest.use_count() == 2);

        second.addMusician(guest);
        assert(guest.use_count() == 3);

        assert(&first.getMusician(0) == guest.get());
        assert(&second.getMusician(0) == guest.get());

        guest.reset();

        assert(first.getMusician(0).getName() == "Maya");
        assert(second.getMusician(0).getInstrument().getName() == "Violin");
        assert(Musician::getLivingObjectCount() == startingMusicians + 1);
        assert(Instrument::getLivingObjectCount() == startingInstruments + 1);
    }

    assert(Musician::getLivingObjectCount() == startingMusicians);
    assert(Instrument::getLivingObjectCount() == startingInstruments);
}

void testPerformanceOutput()
{
    auto musician = std::make_shared<Musician>("Lior");
    musician->receiveInstrument(std::make_unique<Instrument>("Piano"));

    Ensemble ensemble("Jazz Trio");
    ensemble.addMusician(musician);

    std::ostringstream output;
    ensemble.performAll(output);

    assert(output.str().find("Jazz Trio") != std::string::npos);
    assert(output.str().find("Lior plays Piano") != std::string::npos);
}

void testEmptyPointersAreRejected()
{
    Musician musician("Noa");
    bool instrumentExceptionCaught = false;

    try
    {
        musician.receiveInstrument(nullptr);
    }
    catch (const std::invalid_argument&)
    {
        instrumentExceptionCaught = true;
    }

    assert(instrumentExceptionCaught);

    Ensemble ensemble("Quartet");
    bool musicianExceptionCaught = false;

    try
    {
        ensemble.addMusician(nullptr);
    }
    catch (const std::invalid_argument&)
    {
        musicianExceptionCaught = true;
    }

    assert(musicianExceptionCaught);
}

int main()
{
    testExclusiveInstrumentTransfer();
    testSharedGuestMusician();
    testPerformanceOutput();
    testEmptyPointersAreRejected();

    assert(Musician::getLivingObjectCount() == 0);
    assert(Instrument::getLivingObjectCount() == 0);

    std::cout << "All musicians and smart-pointer tests passed.\n";
    return 0;
}
