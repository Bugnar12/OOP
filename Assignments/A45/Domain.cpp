#include "Domain.h"

#include <sstream>
#include <string>
#include <cstdlib>


///The empty constructor (?)
Domain::Domain() : title{""}, genre{""}, releaseYear{0}, nrOfLikes{0}, trailer{""} {}

///The constructor of the Movie object(named Domain)
Domain::Domain(const std::string &title, const std::string &genre, int releaseYear, int nrOfLikes,
               const std::string &trailer) {
    this->title = title;
    this->genre = genre;
    this->releaseYear = releaseYear;
    this->nrOfLikes = nrOfLikes;
    this->trailer = trailer;
}
///Getter for the title field of the object
std::string Domain::getTitle() const {
    return this->title;
}
///Getter for the genre field of the object
std::string Domain::getGenre() const {
    return this->genre;
}
///Getter for the release_year field of the object
int Domain::getReleaseYear() const {
    return this->releaseYear;
}
///Getter for the nr_of_likes field of the object
int Domain::getNrOfLikes() const {
    return this->nrOfLikes;
}
///Getter for the trailer field of the object
///This is the identifier of the object
std::string Domain::getTrailer() const {
    return this->trailer;
}

///converts the object into a pretty-print
///returns a string with the object's fields that can be printed
std::string Domain::toStr(){
    std::ostringstream result;

    result << "Title : " << this->title << " - ";
    result << "Genre : " << this->genre << " - ";
    result << "Release year : " << this->releaseYear << " - ";
    result << "Number of likes : " << this->nrOfLikes << " - ";
    result << "Trailer : " << this->trailer;

    return result.str();

}


///assigning an object to another object of the same type
///input : a const reference to another object of the same type
///output : a reference to the current object
Domain &Domain::operator=(const Domain &movie)
{
    if(this == &movie)
        return *this;

    this->title = movie.title;
    this->genre = movie.genre;
    this->releaseYear = movie.releaseYear;
    this->nrOfLikes = movie.nrOfLikes;
    this->trailer = movie.trailer;

    return *this;

}

int Domain::play() {

    std::string url = getTrailer();
    std::string command = "start " + url;
    if(url != "") {
        system(command.c_str());
        return 1;
    }
    return 0;
}