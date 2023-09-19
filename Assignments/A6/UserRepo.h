#ifndef A45_BUGNAR12_USERREPO_H
#define A45_BUGNAR12_USERREPO_H

#include "Domain.h"
#include <vector>
#include <algorithm>

class UserRepo {
private:
    std::vector<Domain> watchList;
public:
    std::vector<Domain> get_watch_list();

    void add_movie_user(Domain movie);

    void remove_movie_user(Domain existing_movie);

    void update_movie_user(Domain existing_movie, Domain new_movie);

    int get_user_size();


};


#endif //A45_BUGNAR12_USERREPO_H
