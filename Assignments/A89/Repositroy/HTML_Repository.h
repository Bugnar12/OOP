#ifndef A45_BUGNAR12_HTML_REPOSITORY_H
#define A45_BUGNAR12_HTML_REPOSITORY_H

#include "UserRepo.h"
#include <fstream>
#include "Validator/Exceptions.h"

class HTML_Repository : public UserRepo{
public:

    ///Constructor for the HTML_Repository
    HTML_Repository(std::string const &filename);

    /* Method that inherits from the base class UserRepo and uses polymorphism
     * Goes through an HTML file and extracts the information that is used for the Domain objects(movies)
     * returns : a vector containing objects
     * */
    std::vector<Domain> read_from_file() override;

    /* Method that inherits from the base class UserRepo and uses polymorphism
     * Stores the objects from the HTML file to another HTML file
     * return : a vector containing objects
     * */
    void write_to_file() override;

    /* Method that inherits from the base class UserRepo and uses polymorphism
     * Displays IN THE BROWSER information about what it is found in the HTML file
     * */
    void print_file() const override;
};


#endif //A45_BUGNAR12_HTML_REPOSITORY_H
