#include "AdminRepo.h"
#include <exception>

///function to add a movie to the admin repository
///input : one object of type Domain : new_movie
///returns : true if the movie was added, false otherwise
void AdminRepo::add_movie_to_repo(Domain new_movie) {
    std::vector<Domain>::iterator it = find(this->data.begin(), this->data.end(), new_movie);
    if(it != this->data.end())
        throw std::runtime_error("Cannot add the same movie twice!");
    this->data.push_back(new_movie);
}

///function to remove to the admin repository
///input : one object of type Domain : existing_movie
///returns : true if the movie was removed, false otherwise
void AdminRepo::remove_movie_from_repo(Domain existing_movie) {
    auto it = find(this->data.begin(), this->data.end(), existing_movie);
    if(it == this->data.end())
        throw std::runtime_error("Cannot remove a movie that doesn't exist!");
    this->data.erase(it);
}

///function to update the admin repository
///input : 2 objects of type Domain : existing_movie and new_movie
///returns : true if the movie was updated, false otherwise
void AdminRepo::update_movie_from_repo(Domain existing_movie, Domain new_movie) {
    std::vector<Domain>::iterator it = find(this->data.begin(), this->data.end(), existing_movie);
    if(it == this->data.end())
        throw std::runtime_error("Cannot update a movie that doesn't exist!");

    *it = new_movie; ///dereferencing it ( with *it ) means we reffer to the object from the repository
}

///getter for the data
std::vector<Domain> AdminRepo::getMovies() {
    return this->data;
}

///getter for the size of the data ( admin repo )
int AdminRepo::get_size_of_repo(){
    return data.size();
}