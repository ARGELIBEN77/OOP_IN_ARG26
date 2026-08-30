#include "Ensemble.hpp"
#include "Instrument.hpp"
#include "Musician.hpp"

#include <iostream>
#include <memory>
#include <utility>

int main()
{
    std::cout << std::boolalpha;

    std::cout << "Part 1: exclusive instrument ownership\n";
    {
        Musician noa("Noa");
        Musician daniel("Daniel");
        auto guitar = std::make_unique<Instrument>("Guitar");

        std::cout << "The local pointer owns the guitar: "
                  << (guitar != nullptr) << '\n';

        noa.receiveInstrument(std::move(guitar));

        std::cout << "After Noa receives it, the local pointer owns it: "
                  << (guitar != nullptr) << '\n';
        noa.perform(std::cout);
        std::cout << '\n';

        auto transferredInstrument = noa.releaseInstrument();
        daniel.receiveInstrument(std::move(transferredInstrument));

        std::cout << "After the transfer:\n";
        noa.perform(std::cout);
        std::cout << '\n';
        daniel.perform(std::cout);
        std::cout << '\n';
    }

    std::cout << "Living instruments after Part 1: "
              << Instrument::getLivingObjectCount() << "\n\n";

    std::cout << "Part 2: a guest musician shared by two ensembles\n";
    {
        auto guest = std::make_shared<Musician>("Maya");
        guest->receiveInstrument(std::make_unique<Instrument>("Violin"));

        Ensemble chamberGroup("Chamber Group");
        Ensemble studioGroup("Studio Group");

        chamberGroup.addMusician(guest);
        studioGroup.addMusician(guest);

        std::cout << "Number of guest owners: " << guest.use_count() << '\n';

        // The two ensembles remain owners after the original pointer releases
        // its share, so the Musician and Instrument remain alive.
        guest.reset();

        chamberGroup.performAll(std::cout);
        studioGroup.performAll(std::cout);
    }

    std::cout << "\nLiving musicians at the end: "
              << Musician::getLivingObjectCount() << '\n';
    std::cout << "Living instruments at the end: "
              << Instrument::getLivingObjectCount() << '\n';

    return 0;
}
