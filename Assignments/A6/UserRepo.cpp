#include "UserRepo.h"

#include <vector>
#include <algorithm>

///just a getter for the watch_list of the user that will be used in services/UI
std::vector<Domain> UserRepo::get_watch_list() {
    return this->watchList;
}

///method for adding a movie to the user's watch_list
///Input : an object of type Domain (movie)
///just adds the movie to the watch list if desired so
void UserRepo::add_movie_user(Domain movie) {
    this->watchList.push_back(movie);
}

///method for removing a movie from the watch_list
///returns true if the movie can be removed and false otherwise
///Input : an object of type Domain (existing_movie)
void UserRepo::remove_movie_user(Domain existing_movie) {
    std::vector<Domain>::iterator it = find(this->watchList.begin(), this->watchList.end(), existing_movie);
    if(it == this->watchList.end())
        throw std::runtime_error("Cannot remove a movie that doesn't exist!");
    this->watchList.erase(it);

}

///method for updating a movie from the watch_list
///returns true if the movie can be updated and false otherwise
///Input : 2 objects of type Domain (existing_movie and new_movie)
void UserRepo::update_movie_user(Domain existing_movie, Domain new_movie) {
    auto it = find(this->watchList.begin(), this->watchList.end(), existing_movie);
    if(it == this->watchList.end())
        throw std::runtime_error("Cannot update a movie that doesn't exist!");
    *it = new_movie; ///dereferencing it ( with *it ) means we reffer to the object from the repository
}

int UserRepo::get_user_size() {
    return this->watchList.size();
}




