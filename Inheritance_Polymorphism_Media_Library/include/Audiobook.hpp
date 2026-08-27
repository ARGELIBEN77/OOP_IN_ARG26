#ifndef AUDIOBOOK_HPP
#define AUDIOBOOK_HPP

#include "MediaItem.hpp"

#include <string>

class Audiobook : public MediaItem
{
private:
    std::string author;
    std::string narrator;

public:
    Audiobook(std::string title,
              int durationSeconds,
              std::string author,
              std::string narrator);

    const std::string& getAuthor() const;
    const std::string& getNarrator() const;

    void play() const override;
    void printDetails(std::ostream& output) const override;
};

#endif
