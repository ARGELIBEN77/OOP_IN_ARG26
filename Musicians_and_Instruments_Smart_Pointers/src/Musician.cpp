#include "Musician.hpp"

#include <ostream>
#include <stdexcept>
#include <utility>

int Musician::livingObjects = 0;

Musician::Musician(const std::string& name)
    : name(name), instrument(nullptr)
{
    if (name.empty())
        throw std::invalid_argument("Musician name cannot be empty");

    ++livingObjects;
}

Musician::~Musician()
{
    --livingObjects;
}

const std::string& Musician::getName() const
{
    return name;
}

bool Musician::hasInstrument() const
{
    return instrument != nullptr;
}

const Instrument& Musician::getInstrument() const
{
    if (!hasInstrument())
        throw std::logic_error("Musician currently has no instrument");

    return *instrument;
}

void Musician::receiveInstrument(UniquePointer<Instrument> newInstrument)
{
    if (newInstrument == nullptr)
        throw std::invalid_argument("Cannot receive an empty instrument pointer");

    // The member becomes the new exclusive owner. newInstrument is empty
    // after the move and is safely destroyed when this function returns.
    instrument = std::move(newInstrument);
}

UniquePointer<Instrument> Musician::releaseInstrument()
{
    // Returning UniquePointer transfers ownership to the caller.
    return std::move(instrument);
}

void Musician::perform(std::ostream& output) const
{
    output << name;

    if (hasInstrument())
        output << " plays " << instrument->getName();
    else
        output << " is waiting for an instrument";
}

int Musician::getLivingObjectCount()
{
    return livingObjects;
}
