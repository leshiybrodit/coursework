The project is called Media Collection Manager. 
It is a console application for managing a media collection of books, movies, and games. 
The user can add items, view the list, search by title, sort, filter, and count items by genre.
 

There are two levels of inheritance:
MediaItem → EntertainmentItem
EntertainmentItem → Book, Movie, Game


MediaItem is the base abstract class. It stores the common fields: title, genre, rating, releaseYear, creator, and completed. 
This is located in MediaItem.h (line 6).


EntertainmentItem is an intermediate class. It inherits from MediaItem. It exists to demonstrate the second level of inheritance. 
See EntertainmentItem.h (line 8).


Book, Movie, and Game are concrete classes. Each one returns its own type through getCategory(): "Book", "Movie", and "Game".



The project uses the following libraries:


<iostream — for input and output: std::cout, std::cin.


<string — for strings: title, genre, creator.


<vector — an STL container used to store a collection of media items.


<memory — for std::unique_ptr and std::make_unique. These are smart pointers used to avoid manual object deletion.


<algorithm — for STL algorithms: std::sort, std::find_if, std::copy_if, std::count_if.


<stdexcept — for exceptions: std::runtime_error, std::invalid_argument.


<limits — used in main.cpp to clear the input buffer after reading numbers.
