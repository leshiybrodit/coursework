#include "EntertainmentItem.h"

EntertainmentItem::EntertainmentItem(const std::string& title,
                                     const std::string& genre,
                                     int rating,
                                     int releaseYear,
                                     const std::string& creator,
                                     bool completed)
    : MediaItem(title, genre, rating, releaseYear, creator, completed) {
}

void EntertainmentItem::displayInfo() const {
    MediaItem::displayInfo();
}
