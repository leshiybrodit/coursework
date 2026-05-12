#include "MediaCollection.h"

#include <iostream>
#include <stdexcept>

void MediaCollection::addItem(std::unique_ptr<MediaItem> item) {
    if (!item) {
        throw std::invalid_argument("Cannot add an empty media item.");
    }

    items.push_back(std::move(item));
}

void MediaCollection::displayAll() const {
    if (items.empty()) {
        std::cout << "The media collection is empty.\n";
        return;
    }

    for (int i = 0; i < static_cast<int>(items.size()); ++i) {
        std::cout << "\nItem " << (i + 1) << ":\n";
        items[i]->displayInfo();
    }
}

const MediaItem* MediaCollection::searchByTitle(const std::string& title) const {
    auto found = std::find_if(items.begin(), items.end(),
        [&](const std::unique_ptr<MediaItem>& item) {
            return item->getTitle() == title;
        });

    if (found == items.end()) {
        return nullptr;
    }

    return found->get();
}

void MediaCollection::sortByRating() {
    std::sort(items.begin(), items.end(),
        [](const std::unique_ptr<MediaItem>& first,
           const std::unique_ptr<MediaItem>& second) {
            return first->getRating() > second->getRating();
        });
}

void MediaCollection::sortByReleaseYear() {
    std::sort(items.begin(), items.end(),
        [](const std::unique_ptr<MediaItem>& first,
           const std::unique_ptr<MediaItem>& second) {
            return first->getReleaseYear() < second->getReleaseYear();
        });
}

std::vector<const MediaItem*> MediaCollection::filterByGenre(const std::string& genre) const {
    std::vector<const MediaItem*> allItems;
    std::vector<const MediaItem*> result;

    for (const auto& item : items) {
        allItems.push_back(item.get());
    }

    std::copy_if(allItems.begin(), allItems.end(), std::back_inserter(result),
        [&](const MediaItem* item) {
            return item->getGenre() == genre;
        });

    return result;
}

std::vector<const MediaItem*> MediaCollection::filterByCompleted(bool completed) const {
    std::vector<const MediaItem*> allItems;
    std::vector<const MediaItem*> result;

    for (const auto& item : items) {
        allItems.push_back(item.get());
    }

    std::copy_if(allItems.begin(), allItems.end(), std::back_inserter(result),
        [&](const MediaItem* item) {
            return item->isCompleted() == completed;
        });

    return result;
}

int MediaCollection::countByGenre(const std::string& genre) const {
    return countMatching(items, [&](const MediaItem& item) {
        return item.getGenre() == genre;
    });
}

bool MediaCollection::isEmpty() const {
    return items.empty();
}

int MediaCollection::size() const {
    return static_cast<int>(items.size());
}
