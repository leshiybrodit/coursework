#include "Book.h"

Book::Book(const std::string& title,
           const std::string& genre,
           int rating,
           int releaseYear,
           const std::string& creator,
           bool completed)
    : EntertainmentItem(title, genre, rating, releaseYear, creator, completed) {
}

std::string Book::getCategory() const {
    return "Book";
}
