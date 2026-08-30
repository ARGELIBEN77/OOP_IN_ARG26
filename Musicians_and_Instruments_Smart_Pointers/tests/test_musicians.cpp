#include "Ensemble.hpp"
#include "Instrument.hpp"
#include "Musician.hpp"
#include "SharedPointer.hpp"
#include "UniquePointer.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

static_assert(!std::is_copy_constructible<UniquePointer<Instrument>>::value,
              "UniquePointer must not be copy constructible");
static_assert(!std::is_copy_assignable<UniquePointer<Instrument>>::value,
              "UniquePointer must not be copy assignable");
static_assert(std::is_move_constructible<UniquePointer<Instrument>>::value,
              "UniquePointer must be move constructible");
static_assert(std::is_copy_constructible<SharedPointer<Musician>>::value,
              "SharedPointer must be copy constructible");

void testUniquePointerImplementation()
{
    int startingCount = Instrument::getLivingObjectCount();

    UniquePointer<Instrument> first(new Instrument("Guitar"));
    assert(first != nullptr);
    assert(first->getName() == "Guitar");
    assert(Instrument::getLivingObjectCount() == startingCount + 1);

    UniquePointer<Instrument> second(std::move(first));
    assert(first == nullptr);
    assert(second->getName() == "Guitar");

    UniquePointer<Instrument> third(new Instrument("Piano"));
    assert(Instrument::getLivingObjectCount() == startingCount + 2);

    // Move assignment deletes the Piano before taking ownership of the Guitar.
    third = std::move(second);
    assert(second == nullptr);
    assert(third->getName() == "Guitar");
    assert(Instrument::getLivingObjectCount() == startingCount + 1);

    Instrument* released = third.release();
    assert(third == nullptr);
    assert(released->getName() == "Guitar");
    delete released;

    assert(Instrument::getLivingObjectCount() == startingCount);

    third.reset(new Instrument("Violin"));
    assert(third->getName() == "Violin");
    third.reset();
    assert(third == nullptr);
    assert(Instrument::getLivingObjectCount() == startingCount);
}

void testSharedPointerImplementation()
{
    int startingCount = Musician::getLivingObjectCount();

    SharedPointer<Musician> first(new Musician("Maya"));
    assert(first.useCount() == 1);

    SharedPointer<Musician> second(first);
    assert(first.useCount() == 2);
    assert(second.get() == first.get());

    SharedPointer<Musician> third;
    third = first;
    assert(first.useCount() == 3);

    SharedPointer<Musician> fourth(std::move(third));
    assert(third == nullptr);
    assert(fourth.useCount() == 3);

    SharedPointer<Musician> replacement(new Musician("Lior"));
    assert(Musician::getLivingObjectCount() == startingCount + 2);

    // Copy assignment releases Lior, then joins Maya's ownership group.
    replacement = first;
    assert(Musician::getLivingObjectCount() == startingCount + 1);
    assert(first.useCount() == 4);

    SharedPointer<Musician> moved;
    moved = std::move(replacement);
    assert(replacement == nullptr);
    assert(moved.useCount() == 4);

    first = first;
    assert(first.useCount() == 4);

    SharedPointer<Musician>* sameOwner = &first;
    first = std::move(*sameOwner);
    assert(first.useCount() == 4);

    second.reset();
    assert(first.useCount() == 3);

    fourth.reset();
    assert(first.useCount() == 2);

    moved.reset();
    assert(first.useCount() == 1);

    first.reset();
    assert(Musician::getLivingObjectCount() == startingCount);
}

void testExclusiveInstrumentTransfer()
{
    int startingInstruments = Instrument::getLivingObjectCount();
    int startingMusicians = Musician::getLivingObjectCount();

    {
        Musician first("Noa");
        Musician second("Daniel");
        UniquePointer<Instrument> guitar(new Instrument("Guitar"));

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
        SharedPointer<Musician> guest(new Musician("Maya"));
        guest->receiveInstrument(
            UniquePointer<Instrument>(new Instrument("Violin")));

        assert(guest.useCount() == 1);

        Ensemble first("Chamber Group");
        Ensemble second("Studio Group");

        first.addMusician(guest);
        assert(guest.useCount() == 2);

        second.addMusician(guest);
        assert(guest.useCount() == 3);

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
    SharedPointer<Musician> musician(new Musician("Lior"));
    musician->receiveInstrument(
        UniquePointer<Instrument>(new Instrument("Piano")));

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
        musician.receiveInstrument(UniquePointer<Instrument>());
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
        ensemble.addMusician(SharedPointer<Musician>());
    }
    catch (const std::invalid_argument&)
    {
        musicianExceptionCaught = true;
    }

    assert(musicianExceptionCaught);
}

int main()
{
    testUniquePointerImplementation();
    testSharedPointerImplementation();
    testExclusiveInstrumentTransfer();
    testSharedGuestMusician();
    testPerformanceOutput();
    testEmptyPointersAreRejected();

    assert(Musician::getLivingObjectCount() == 0);
    assert(Instrument::getLivingObjectCount() == 0);

    std::cout << "All musicians and smart-pointer tests passed.\n";
    return 0;
}
