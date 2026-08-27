#include "Audiobook.hpp"

#include <iostream>
#include <ostream>
#include <utility>

Audiobook::Audiobook(std::string bookTitle,
                     int bookDuration,
                     std::string bookAuthor,
                     std::string bookNarrator)
    : MediaItem(std::move(bookTitle), bookDuration),
      author(std::move(bookAuthor)),
      narrator(std::move(bookNarrator))
{
}

const std::string& Audiobook::getAuthor() const
{
    return author;
}

const std::string& Audiobook::getNarrator() const
{
    return narrator;
}

void Audiobook::play() const
{
    std::cout << "Playing audiobook: " << getTitle()
              << " by " << author
              << ", narrated by " << narrator << '\n';
}

void Audiobook::printDetails(std::ostream& output) const
{
    MediaItem::printDetails(output);
    output << ", author: " << author
           << ", narrator: " << narrator;
}
