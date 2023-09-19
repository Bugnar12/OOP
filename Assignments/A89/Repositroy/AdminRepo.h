#ifndef A45_BUGNAR12_ADMINREPO_H
#define A45_BUGNAR12_ADMINREPO_H

#include "Domain/Domain.h"
#include "Validator/Exceptions.h"
#include <vector>
#include <algorithm>
#include <fstream>


class AdminRepo {
private:
    ///the "database" of the application
    std::vector<Domain> data;
    std::string filename;
public:
    AdminRepo(const std::string &filename); ///constructor for the admin repo

    virtual ~AdminRepo() {}; ///destructor for the admin repo

    ///the add functionality of the repo ( no const for new_movie since it can get modified afterwards)
    void add_movie_to_repo(Domain new_movie);

    ///remove functionality of the repo
    void remove_movie_from_repo(Domain existing_movie);

    ///update functionality of the repo
    void update_movie_from_repo(Domain existing_movie, Domain new_movie);

    ///functionality for finding an element in the repo(to aid the implementation of other functionalities)
    ///returns the position on which an element is situated in the array
    int find_movie_in_repo(Domain movie);

    ///functionality to get all the objects from the repository
    std::vector<Domain> getMovies();

    ///method for getting the size of a repository using the STL method .size()
    int get_size_of_repo();

    ///method to read from a file the movie database list from the admin repo
    ///returns : a list of movies
    std::vector<Domain> read_from_file();

    ///method to write into a file the movie database from the admin repo
    ///does not return anything since it's void!
    void write_to_file();
};


#endif //A45_BUGNAR12_ADMINREPO_H
