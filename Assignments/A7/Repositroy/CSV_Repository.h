#ifndef A45_BUGNAR12_CSV_REPOSITORY_H
#define A45_BUGNAR12_CSV_REPOSITORY_H

#include "UserRepo.h"
#include <fstream>
#include "Validator/Validators.h"


class CSV_Repository : public UserRepo{
public:
    ///Constructor for the CSV_Repository
    CSV_Repository(const std::string &filename);
    /*
     * overriden method write_to_file() that inherits from the UserRepo() base class
     * used for writing into the file (CSV type) the watchlist
     * return : vector of movies
    */
    void write_to_file() override;

    /* overriden method print_file() that inherits from the UserRepo() base class
     * used for displaying in a separate file the contents of the .csv file
     * */

    void print_file() const override;
};


#endif //A45_BUGNAR12_CSV_REPOSITORY_H
