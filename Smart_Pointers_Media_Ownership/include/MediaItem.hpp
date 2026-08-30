#ifndef SMART_POINTERS_MEDIA_ITEM_HPP
#define SMART_POINTERS_MEDIA_ITEM_HPP

#include <iosfwd>
#include <string>

class MediaItem
{
private:
    std::string title;
    static int livingObjects;

public:
    explicit MediaItem(const std::string& title);

    // Deleting a derived object through unique_ptr<MediaItem> calls the
    // correct derived destructor because the base destructor is virtual.
    virtual ~MediaItem();

    const std::string& getTitle() const;
    virtual void display(std::ostream& output) const = 0;

    // Used by the demonstration and tests to observe automatic destruction.
    static int getLivingObjectCount();
};

#endif
