#ifndef SMART_POINTERS_MUSICIAN_HPP
#define SMART_POINTERS_MUSICIAN_HPP

#include "Instrument.hpp"
#include "UniquePointer.hpp"

#include <iosfwd>
#include <string>

class Musician
{
private:
    std::string name;
    UniquePointer<Instrument> instrument;
    static int livingObjects;

public:
    explicit Musician(const std::string& name);
    ~Musician();

    // The UniquePointer member gives each Musician exclusive ownership of an
    // Instrument. Copying would create two supposed owners, so it is disabled.
    Musician(const Musician&) = delete;
    Musician& operator=(const Musician&) = delete;

    const std::string& getName() const;
    bool hasInstrument() const;
    const Instrument& getInstrument() const;

    // Ownership enters and leaves a Musician explicitly through UniquePointer.
    void receiveInstrument(UniquePointer<Instrument> newInstrument);
    UniquePointer<Instrument> releaseInstrument();

    void perform(std::ostream& output) const;
    static int getLivingObjectCount();
};

#endif
