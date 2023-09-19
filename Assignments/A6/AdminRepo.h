#ifndef A45_BUGNAR12_ADMINREPO_H
#define A45_BUGNAR12_ADMINREPO_H

#include "Domain.h"
#include <vector>
#include <algorithm>

class AdminRepo {
private:
    ///the "database" of the application
    std::vector<Domain> data;
public:
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

    int get_size_of_repo();
};


#endif //A45_BUGNAR12_ADMINREPO_H
