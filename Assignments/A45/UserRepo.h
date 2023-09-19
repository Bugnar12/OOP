#ifndef A45_BUGNAR12_USERREPO_H
#define A45_BUGNAR12_USERREPO_H

#include "DynamicArray.h"

class UserRepo {
private:
    DynamicArray<Domain> watch_list;
public:
    DynamicArray<Domain> get_watch_list();

    int get_size();

    int find_movie_user(Domain movie);

    void add_movie_user(Domain movie);

    bool remove_movie_user(Domain existing_movie);

    bool update_movie_user(Domain existing_movie, Domain new_movie);



};


#endif //A45_BUGNAR12_USERREPO_H
