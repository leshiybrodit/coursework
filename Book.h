#ifndef BOOK_H
#define BOOK_H

#include "EntertainmentItem.h"

#include <string>

class Book : public EntertainmentItem {
public:
    Book(const std::string& title,
         const std::string& genre,
         int rating,
         int releaseYear,
         const std::string& creator,
         bool completed);

    std::string getCategory() const override;
};

#endif
