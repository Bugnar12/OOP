#include "UserRepo.h"

#include <vector>
#include <algorithm>

UserRepo::UserRepo(const std::string &filename) {
    this->filename = filename;
}

///just a getter for the watch_list of the user that will be used in services/UI
std::vector<Domain> UserRepo::get_watch_list() {
    return this->watchList;
}

///method for adding a movie to the user's watch_list
///Input : an object of type Domain (movie)
///just adds the movie to the watch list if desired so
void UserRepo::add_movie_user(Domain movie) {
    this->watchList = read_from_file();

    this->watchList.push_back(movie);

    write_to_file();
}

///method for removing a movie from the watch_list
///returns true if the movie can be removed and false otherwise
///Input : an object of type Domain (existing_movie)
void UserRepo::remove_movie_user(Domain existing_movie) {
    this->watchList = read_from_file();

    std::vector<Domain>::iterator it = find(this->watchList.begin(), this->watchList.end(), existing_movie);
    if(it == this->watchList.end())
        throw OperationError("The movie you are trying to remove is not in the watchlist!");
    this->watchList.erase(it);

    write_to_file();

}

///method for updating a movie from the watch_list
///returns true if the movie can be updated and false otherwise
///Input : 2 objects of type Domain (existing_movie and new_movie)
void UserRepo::update_movie_user(Domain existing_movie, Domain new_movie) {
    this->watchList = read_from_file();

    auto it = find(this->watchList.begin(), this->watchList.end(), existing_movie);
    if(it != this->watchList.end())
        *it = new_movie; ///dereferencing it ( with *it ) means we reffer to the object from the repository

    write_to_file();
}

int UserRepo::get_user_size() {
    return this->watchList.size();
}

///method to read from a file the movies from the .txt file
///it is a virtual method so it can be inherited
///return list of Movies
std::vector<Domain> UserRepo::read_from_file() {
    std::ifstream file(this->filename);
    if(!file.is_open())
    {
        throw FileError("The file was not opened correctly!");
    }
    std::vector<Domain> watchList2;

    Domain movie;
    while(file >> movie)
    {
        watchList2.push_back(movie);
    }

    file.close();
    return watchList2;
}

///method to write to a .txt file
///it is again a virtual method so it can be inherited
void UserRepo::write_to_file() {
    std::ofstream file(this->filename);
    if(!file.is_open())
    {
        throw FileError("The file was not opened correctly!");
    }
    ///extracting each movie from the watchlist and putting it into a file using the overloaded extractor operator
    for(const auto& movie : this->watchList)
    {
        file << movie;
    }

    file.close();
}


