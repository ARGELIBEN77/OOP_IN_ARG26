#ifndef MUSICIANS_INSTRUMENT_HPP
#define MUSICIANS_INSTRUMENT_HPP

#include <string>

class Instrument
{
private:
    std::string name;
    static int livingObjects;

public:
    explicit Instrument(const std::string& name);
    ~Instrument();

    const std::string& getName() const;

    // The demonstration uses this value to make automatic lifetime visible.
    static int getLivingObjectCount();
};

#endif
