#ifndef GAME_H
#define GAME_H

#include "EntertainmentItem.h"

#include <string>

class Game : public EntertainmentItem {
public:
    Game(const std::string& title,
         const std::string& genre,
         int rating,
         int releaseYear,
         const std::string& creator,
         bool completed);

    std::string getCategory() const override;
};

#endif
