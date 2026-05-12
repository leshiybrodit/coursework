#ifndef MEDIACOLLECTION_H
#define MEDIACOLLECTION_H

#include "MediaItem.h"

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

template <typename Predicate>
int countMatching(const std::vector<std::unique_ptr<MediaItem>>& items, Predicate predicate) {
    return static_cast<int>(std::count_if(items.begin(), items.end(),
        [&](const std::unique_ptr<MediaItem>& item) {
            return predicate(*item);
        }));
}

class MediaCollection {
private:
    std::vector<std::unique_ptr<MediaItem>> items;

public:
    void addItem(std::unique_ptr<MediaItem> item);
    void displayAll() const;

    const MediaItem* searchByTitle(const std::string& title) const;

    void sortByRating();
    void sortByReleaseYear();

    std::vector<const MediaItem*> filterByGenre(const std::string& genre) const;
    std::vector<const MediaItem*> filterByCompleted(bool completed) const;

    int countByGenre(const std::string& genre) const;
    bool isEmpty() const;
    int size() const;
};

#endif
