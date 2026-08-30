#ifndef SMART_POINTERS_MUSICIAN_HPP
#define SMART_POINTERS_MUSICIAN_HPP

#include "Instrument.hpp"

#include <iosfwd>
#include <memory>
#include <string>

class Musician
{
private:
    std::string name;
    std::unique_ptr<Instrument> instrument;
    static int livingObjects;

public:
    explicit Musician(const std::string& name);
    ~Musician();

    // The unique_ptr member gives each Musician exclusive ownership of an
    // Instrument. Copying would create two supposed owners, so it is disabled.
    Musician(const Musician&) = delete;
    Musician& operator=(const Musician&) = delete;

    const std::string& getName() const;
    bool hasInstrument() const;
    const Instrument& getInstrument() const;

    // Ownership enters and leaves a Musician explicitly through unique_ptr.
    void receiveInstrument(std::unique_ptr<Instrument> newInstrument);
    std::unique_ptr<Instrument> releaseInstrument();

    void perform(std::ostream& output) const;
    static int getLivingObjectCount();
};

#endif
