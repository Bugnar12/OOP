#include "AdminRepo.h"
#include <exception>


AdminRepo::AdminRepo(const std::string &filename) {
    this->filename = filename;
    this->data = read_from_file();
}

///getter for the data
std::vector<Domain> AdminRepo::getMovies() {
    return this->data;
}


///getter for the size of the data ( admin repo )
int AdminRepo::get_size_of_repo(){
    return this->data.size();
}

///function to add a movie to the admin repository
///input : one object of type Domain : new_movie
///returns : true if the movie was added, false otherwise
void AdminRepo::add_movie_to_repo(Domain new_movie) {
    this->data = read_from_file();

    std::vector<Domain>::iterator it = find(this->data.begin(), this->data.end(), new_movie);
    if(it != this->data.end())
        throw OperationError("The movie you want to add is already in the repo!");
    this->data.push_back(new_movie);

    write_to_file();
}

///function to remove to the admin repository
///input : one object of type Domain : existing_movie
///returns : true if the movie was removed, false otherwise
void AdminRepo::remove_movie_from_repo(Domain existing_movie) {
    this->data = read_from_file();

    auto it = find(this->data.begin(), this->data.end(), existing_movie);
    if(it == this->data.end())
        throw OperationError("The movie you are trying to delete does not exist in the repo!");
    this->data.erase(it);

    write_to_file();
}

///function to update the admin repository
///input : 2 objects of type Domain : existing_movie and new_movie
///returns : true if the movie was updated, false otherwise
void AdminRepo::update_movie_from_repo(Domain existing_movie, Domain new_movie) {
    this->data = read_from_file();

    std::vector<Domain>::iterator it = find(this->data.begin(), this->data.end(), existing_movie);
    if (it == this->data.end())
        throw OperationError("The movie you are trying to update does not exist in the repo!");

    *it = new_movie; ///dereferencing it ( with *it ) means we reffer to the object from the repository

    write_to_file();
}

std::vector<Domain> AdminRepo::read_from_file() {
    std::ifstream file(this->filename);
    while(!file.is_open())
        throw FileError("The file is not opened correctly!");
    std::vector<Domain> movie_database2;
    Domain movie;

    ///adding each movie to the newly created movie database
    while(file >> movie)
        movie_database2.push_back(movie);

    file.close();
    return movie_database2;
}

void AdminRepo::write_to_file() {
    std::ofstream file(this->filename);
    while(!file.is_open())
        throw FileError("The file is not opened correctly!");

    ///looping through the repo and writing to the file using the overloaded extracting operator
    for(const auto &movie : this->data)
        file << movie;

    file.close();
}

