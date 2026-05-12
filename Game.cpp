#include "Game.h"

Game::Game(const std::string& title,
           const std::string& genre,
           int rating,
           int releaseYear,
           const std::string& creator,
           bool completed)
    : EntertainmentItem(title, genre, rating, releaseYear, creator, completed) {
}

std::string Game::getCategory() const {
    return "Game";
}
