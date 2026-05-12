#include "Book.h"
#include "Game.h"
#include "InvalidMediaException.h"
#include "MediaCollection.h"
#include "Movie.h"

#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

void showMenu() {
    std::cout << "\n===== Media Collection Manager =====\n";
    std::cout << "1. Add new media item\n";
    std::cout << "2. Display all media items\n";
    std::cout << "3. Search by title\n";
    std::cout << "4. Sort by rating\n";
    std::cout << "5. Sort by release year\n";
    std::cout << "6. Filter by genre\n";
    std::cout << "7. Filter completed/uncompleted items\n";
    std::cout << "8. Count items by genre\n";
    std::cout << "9. Exit\n";
}

std::string readLine(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

int readInt(const std::string& prompt) {
    int value;
    std::cout << prompt;

    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Please enter a valid number.");
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

bool readCompletedStatus() {
    std::string answer = readLine("Completed? (y/n): ");
    return answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes";
}

void displayResults(const std::vector<const MediaItem*>& results) {
    if (results.empty()) {
        std::cout << "No matching media items found.\n";
        return;
    }

    for (int i = 0; i < static_cast<int>(results.size()); ++i) {
        std::cout << "\nResult " << (i + 1) << ":\n";
        results[i]->displayInfo();
    }
}

void addMediaItem(MediaCollection& collection) {
    std::cout << "\nChoose media type:\n";
    std::cout << "1. Book\n";
    std::cout << "2. Movie\n";
    std::cout << "3. Game\n";

    int type = readInt("Type: ");
    std::string title = readLine("Title: ");
    std::string genre = readLine("Genre: ");
    int rating = readInt("Rating (1-10): ");
    int releaseYear = readInt("Release year: ");
    std::string creator = readLine("Creator/author/director: ");
    bool completed = readCompletedStatus();

    std::unique_ptr<MediaItem> item;

    if (type == 1) {
        item = std::make_unique<Book>(title, genre, rating, releaseYear, creator, completed);
    } else if (type == 2) {
        item = std::make_unique<Movie>(title, genre, rating, releaseYear, creator, completed);
    } else if (type == 3) {
        item = std::make_unique<Game>(title, genre, rating, releaseYear, creator, completed);
    } else {
        throw std::runtime_error("Unknown media type.");
    }

    collection.addItem(std::move(item));
    std::cout << "Media item added successfully.\n";
}

int main() {
    MediaCollection collection;
    bool running = true;

    while (running) {
        try {
            showMenu();
            int choice = readInt("Choose an option: ");

            if (choice == 1) {
                addMediaItem(collection);
            } else if (choice == 2) {
                collection.displayAll();
            } else if (choice == 3) {
                std::string title = readLine("Enter exact title to search: ");
                const MediaItem* found = collection.searchByTitle(title);

                if (found == nullptr) {
                    std::cout << "No item with that title was found.\n";
                } else {
                    found->displayInfo();
                }
            } else if (choice == 4) {
                collection.sortByRating();
                std::cout << "Items sorted by rating from highest to lowest.\n";
                collection.displayAll();
            } else if (choice == 5) {
                collection.sortByReleaseYear();
                std::cout << "Items sorted by release year from oldest to newest.\n";
                collection.displayAll();
            } else if (choice == 6) {
                std::string genre = readLine("Enter genre: ");
                displayResults(collection.filterByGenre(genre));
            } else if (choice == 7) {
                std::cout << "1. Completed\n";
                std::cout << "2. Uncompleted\n";
                int statusChoice = readInt("Choose status: ");

                if (statusChoice == 1) {
                    displayResults(collection.filterByCompleted(true));
                } else if (statusChoice == 2) {
                    displayResults(collection.filterByCompleted(false));
                } else {
                    throw std::runtime_error("Unknown completed status option.");
                }
            } else if (choice == 8) {
                std::string genre = readLine("Enter genre: ");
                std::cout << "Items in genre \"" << genre << "\": "
                          << collection.countByGenre(genre) << '\n';
            } else if (choice == 9) {
                running = false;
                std::cout << "Goodbye!\n";
            } else {
                std::cout << "Unknown menu option.\n";
            }
        } catch (const InvalidMediaException& error) {
            std::cout << "Invalid media item: " << error.what() << '\n';
        } catch (const std::exception& error) {
            std::cout << "Error: " << error.what() << '\n';
        }
    }

    return 0;
}
