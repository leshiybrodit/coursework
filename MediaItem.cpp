#include "MediaItem.h"
#include "InvalidMediaException.h"

#include <iostream>

MediaItem::MediaItem(const std::string& title,
                     const std::string& genre,
                     int rating,
                     int releaseYear,
                     const std::string& creator,
                     bool completed)
    : title(title),
      genre(genre),
      rating(rating),
      releaseYear(releaseYear),
      creator(creator),
      completed(completed) {
    validate();
}

void MediaItem::validate() const {
    if (title.empty()) {
        throw InvalidMediaException("Title cannot be empty.");
    }

    if (rating < 1 || rating > 10) {
        throw InvalidMediaException("Rating must be between 1 and 10.");
    }

    if (releaseYear < 1000 || releaseYear > 2100) {
        throw InvalidMediaException("Release year must be between 1000 and 2100.");
    }
}

std::string MediaItem::getTitle() const {
    return title;
}

std::string MediaItem::getGenre() const {
    return genre;
}

int MediaItem::getRating() const {
    return rating;
}

int MediaItem::getReleaseYear() const {
    return releaseYear;
}

std::string MediaItem::getCreator() const {
    return creator;
}

bool MediaItem::isCompleted() const {
    return completed;
}

void MediaItem::displayInfo() const {
    std::cout << "Category: " << getCategory() << '\n';
    std::cout << "Title: " << title << '\n';
    std::cout << "Genre: " << genre << '\n';
    std::cout << "Rating: " << rating << "/10\n";
    std::cout << "Release year: " << releaseYear << '\n';
    std::cout << "Creator/author/director: " << creator << '\n';
    std::cout << "Completed: " << (completed ? "Yes" : "No") << '\n';
}
