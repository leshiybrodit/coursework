#ifndef MEDIAITEM_H
#define MEDIAITEM_H

#include <string>

class MediaItem {
protected:
    std::string title;
    std::string genre;
    int rating;
    int releaseYear;
    std::string creator;
    bool completed;

    void validate() const;

public:
    MediaItem(const std::string& title,
              const std::string& genre,
              int rating,
              int releaseYear,
              const std::string& creator,
              bool completed);

    virtual ~MediaItem() = default;

    std::string getTitle() const;
    std::string getGenre() const;
    int getRating() const;
    int getReleaseYear() const;
    std::string getCreator() const;
    bool isCompleted() const;

    virtual std::string getCategory() const = 0;
    virtual void displayInfo() const;
};

#endif
