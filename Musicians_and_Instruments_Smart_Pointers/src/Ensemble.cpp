#include "Ensemble.hpp"

#include <ostream>
#include <stdexcept>
#include <utility>

Ensemble::Ensemble(const std::string& name)
    : name(name)
{
    if (name.empty())
        throw std::invalid_argument("Ensemble name cannot be empty");
}

void Ensemble::addMusician(std::shared_ptr<Musician> musician)
{
    if (musician == nullptr)
        throw std::invalid_argument("Cannot add an empty musician pointer");

    // The caller and the ensemble may both remain owners. Moving the local
    // parameter into the vector transfers this function's temporary share.
    musicians.push_back(std::move(musician));
}

const std::string& Ensemble::getName() const
{
    return name;
}

std::size_t Ensemble::size() const
{
    return musicians.size();
}

const Musician& Ensemble::getMusician(std::size_t index) const
{
    if (index >= musicians.size())
        throw std::out_of_range("Musician index is out of range");

    return *musicians[index];
}

void Ensemble::performAll(std::ostream& output) const
{
    output << name << ":\n";

    for (const auto& musician : musicians)
    {
        output << "  ";
        musician->perform(output);
        output << '\n';
    }
}
