#include "UserRepo.h"
#include <iostream>

///just a getter for the watch_list of the user that will be used in services/UI
DynamicArray<Domain> UserRepo::get_watch_list() {
    return this->watch_list;
}

///getter for the size of the watch_list of the viewer
int UserRepo::get_size() {
    return this->watch_list.getSize();
}

///function that returns 1 if a movie is found in the watch list and 0 otherwise
///input : a movie object.
int UserRepo::find_movie_user(Domain movie) {
    for(int index = 0; index < this->watch_list.getSize(); index++)
        if(this->watch_list.getElement(index) == movie)
            return index;

    return -1;
}

///method for adding a movie to the user's watch_list
///Input : an object of type Domain (movie)
///just adds the movie to the watch list if desired so
void UserRepo::add_movie_user(Domain movie) {
    this->watch_list.addDynamic(movie);
}

///method for removing a movie from the watch_list
///returns true if the movie can be removed and false otherwise
///Input : an object of type Domain (existing_movie)
bool UserRepo::remove_movie_user(Domain existing_movie) {
    int result = find_movie_user(existing_movie);
    if(result == -1)
        return false;
    this->watch_list.removeDynamic(result);
    return true;

}

///method for updating a movie from the watch_list
///returns true if the movie can be updated and false otherwise
///Input : 2 objects of type Domain (existing_movie and new_movie)
bool UserRepo::update_movie_user(Domain existing_movie, Domain new_movie) {
    int result = find_movie_user(existing_movie);
    if (result == -1)
        return false;
    this->watch_list.updateDynamic(new_movie, result);
    return true;
}




