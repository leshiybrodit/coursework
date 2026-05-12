#ifndef MOVIE_H
#define MOVIE_H

#include "EntertainmentItem.h"

#include <string>

class Movie : public EntertainmentItem {
public:
    Movie(const std::string& title,
          const std::string& genre,
          int rating,
          int releaseYear,
          const std::string& creator,
          bool completed);

    std::string getCategory() const override;
};

#endif
