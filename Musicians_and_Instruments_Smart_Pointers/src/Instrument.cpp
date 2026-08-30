#include "Instrument.hpp"

#include <stdexcept>

int Instrument::livingObjects = 0;

Instrument::Instrument(const std::string& name)
    : name(name)
{
    if (name.empty())
        throw std::invalid_argument("Instrument name cannot be empty");

    ++livingObjects;
}

Instrument::~Instrument()
{
    --livingObjects;
}

const std::string& Instrument::getName() const
{
    return name;
}

int Instrument::getLivingObjectCount()
{
    return livingObjects;
}
