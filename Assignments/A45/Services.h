#ifndef A45_BUGNAR12_SERVICES_H
#define A45_BUGNAR12_SERVICES_H
#include "AdminRepo.h"
#include "UserRepo.h"


class Services {
private:
    AdminRepo admin_repo;
    UserRepo user_repo;
public:
    AdminRepo get_admin_repo() const;

    UserRepo get_user_repo() const;

    bool add_admin_repo(const Domain &new_movie);

    bool remove_admin_repo(Domain existing_movie);

    bool update_admin_repo(Domain existing_movie, Domain new_movie);

    void generate_entries();

    void add_user(Domain movie);

    bool delete_user(Domain movie);


};


#endif //A45_BUGNAR12_SERVICES_H
