#ifndef A45_BUGNAR12_USERREPO_H
#define A45_BUGNAR12_USERREPO_H

#include "Domain/Domain.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include "Validator/Exceptions.h"

class UserRepo {
protected:
    std::vector<Domain> watchList;
    std::string filename;
public:
    UserRepo(const std::string &filename); ///constructor

    virtual ~UserRepo() {}; ///virtual destructor

    std::vector<Domain> get_watch_list();

    void add_movie_user(Domain movie);

    void remove_movie_user(Domain existing_movie);

    void update_movie_user(Domain existing_movie, Domain new_movie);

    int get_user_size();

    virtual std::vector<Domain> read_from_file();

    virtual void write_to_file();

    virtual void print_file() const = 0;

};


#endif //A45_BUGNAR12_USERREPO_H
