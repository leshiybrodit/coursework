#ifndef ENTERTAINMENTITEM_H
#define ENTERTAINMENTITEM_H

#include "MediaItem.h"

#include <string>

class EntertainmentItem : public MediaItem {
public:
    EntertainmentItem(const std::string& title,
                      const std::string& genre,
                      int rating,
                      int releaseYear,
                      const std::string& creator,
                      bool completed);

    void displayInfo() const override;
};

#endif
