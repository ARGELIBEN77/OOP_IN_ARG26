#include "PodcastEpisode.hpp"

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <utility>

PodcastEpisode::PodcastEpisode(std::string episodeTitle,
                               int episodeDuration,
                               std::string showName,
                               int number)
    : MediaItem(std::move(episodeTitle), episodeDuration),
      podcastName(std::move(showName)),
      episodeNumber(number)
{
    if (episodeNumber <= 0)
        throw std::invalid_argument("Episode number must be positive");
}

const std::string& PodcastEpisode::getPodcastName() const
{
    return podcastName;
}

int PodcastEpisode::getEpisodeNumber() const
{
    return episodeNumber;
}

void PodcastEpisode::play() const
{
    std::cout << "Playing podcast: " << podcastName
              << ", episode " << episodeNumber
              << " - " << getTitle() << '\n';
}

void PodcastEpisode::printDetails(std::ostream& output) const
{
    MediaItem::printDetails(output);
    output << ", podcast: " << podcastName
           << ", episode: " << episodeNumber;
}
