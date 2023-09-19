#include "AdminRepo.h"

///function to add a movie to the admin repository
///input : one object of type Domain : new_movie
///returns : true if the movie was added, false otherwise
bool AdminRepo::add_movie_to_repo(Domain new_movie) {
    int index = find_movie_in_repo(new_movie);
    if(index != -1)
        return false;
    this->data.addDynamic(new_movie);
    return true;
}

///function to remove to the admin repository
///input : one object of type Domain : existing_movie
///returns : true if the movie was removed, false otherwise
bool AdminRepo::remove_movie_from_repo(Domain existing_movie) {
    int index = find_movie_in_repo(existing_movie);
    if(index == -1)
        return false;

    this->data.removeDynamic(index);
    return true;
}

///function to update the admin repository
///input : 2 objects of type Domain : existing_movie and new_movie
///returns : true if the movie was updated, false otherwise
bool AdminRepo::update_movie_from_repo(Domain existing_movie, Domain new_movie) {
    int index = find_movie_in_repo(existing_movie);
    if(index == -1)
        return false;
    this->data.updateDynamic(new_movie, index);
    return true;
}

///getter for the data
DynamicArray<Domain> AdminRepo::getMovies() {
    return this->data;
}

///getter for the size of the data ( admin repo )
int AdminRepo::get_size_of_repo(){
    return this->data.getSize();
}

///function to find a movie object in the admin repository
///input : one object of type Domain : movie
///returns : the index of the movie in the admin repository, -1 if the movie is not in the admin repository
int AdminRepo::find_movie_in_repo(Domain movie) {
    for(int index = 0 ; index < this->data.getSize(); index++)
        if(this->data.getElement(index) == movie)
            return index;
    return -1;
}
