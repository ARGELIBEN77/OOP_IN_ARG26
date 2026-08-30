#ifndef SHARED_ENSEMBLE_HPP
#define SHARED_ENSEMBLE_HPP

#include "Musician.hpp"

#include <cstddef>
#include <iosfwd>
#include <memory>
#include <string>
#include <vector>

// Ensembles share the lifetime of guest musicians. One Musician object can
// therefore participate in several ensembles without being duplicated.
class Ensemble
{
private:
    std::string name;
    std::vector<std::shared_ptr<Musician>> musicians;

public:
    explicit Ensemble(const std::string& name);

    void addMusician(std::shared_ptr<Musician> musician);

    const std::string& getName() const;
    std::size_t size() const;
    const Musician& getMusician(std::size_t index) const;
    void performAll(std::ostream& output) const;
};

#endif
