#ifndef PODCAST_EPISODE_HPP
#define PODCAST_EPISODE_HPP

#include "MediaItem.hpp"

#include <string>

class PodcastEpisode : public MediaItem
{
private:
    std::string podcastName;
    int episodeNumber;

public:
    PodcastEpisode(std::string title,
                   int durationSeconds,
                   std::string podcastName,
                   int episodeNumber);

    const std::string& getPodcastName() const;
    int getEpisodeNumber() const;

    void play() const override;
    void printDetails(std::ostream& output) const override;
};

#endif
