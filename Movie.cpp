#include "Movie.h"

Movie::Movie(const std::string& title,
             const std::string& genre,
             int rating,
             int releaseYear,
             const std::string& creator,
             bool completed)
    : EntertainmentItem(title, genre, rating, releaseYear, creator, completed) {
}

std::string Movie::getCategory() const {
    return "Movie";
}
