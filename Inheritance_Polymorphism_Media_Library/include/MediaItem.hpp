#ifndef MEDIA_ITEM_HPP
#define MEDIA_ITEM_HPP

#include <iosfwd>
#include <string>

// MediaItem represents the common idea shared by every playable item.
// It is abstract because a general MediaItem has no meaningful way to play.
class MediaItem
{
private:
    std::string title;
    int durationSeconds;

public:
    MediaItem(std::string title, int durationSeconds);

    // A polymorphic base class needs a virtual destructor. If a derived object
    // is ever deleted through a MediaItem pointer, its complete destructor
    // chain will run correctly.
    virtual ~MediaItem() = default;

    const std::string& getTitle() const;
    int getDurationSeconds() const;

    // = 0 makes play pure virtual and MediaItem abstract. Every concrete
    // derived class must provide its own implementation with the same
    // signature.
    virtual void play() const = 0;

    // Unlike play, this virtual function has a useful shared implementation.
    // Derived classes may extend it with their own details.
    virtual void printDetails(std::ostream& output) const;
};

#endif
