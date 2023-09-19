#include "Services.h"
#include <iostream>

///getter for the admin_repo
AdminRepo Services::get_admin_repo() const {
    return this->admin_repo;
}

///getter for the user_repo
UserRepo Services::get_user_repo() const{
    return this->user_repo;
}

///function to add a movie to the admin repository
///input : one const object of type Domain : new_movie
///returns true if the movie was added, false otherwise
bool Services::add_admin_repo(const Domain &new_movie) {
    if(this->admin_repo.add_movie_to_repo(new_movie))
        return true;
    return false;
}

///function to remove to the admin repository
///input : one object of type Domain : existing_movie
///returns true if the movie was removed, false otherwise
bool Services::remove_admin_repo(Domain existing_movie) {
    if(this->admin_repo.remove_movie_from_repo(existing_movie)) {
        this->user_repo.remove_movie_user(existing_movie);
        return true;
    }
    return false;
}

///function to update the admin repository
///input : 2 objects of type Domain : existing_movie and new_movie
///returns true if the movie was updated, false otherwise
bool Services::update_admin_repo(Domain existing_movie, Domain new_movie) {
    if(this->admin_repo.update_movie_from_repo(existing_movie, new_movie))
    {
        this->user_repo.update_movie_user(existing_movie, new_movie);
        return true;
    }
    return false;
}

///function to add a movie to the user repository
///input : one object of type Domain : movie
void Services::add_user(Domain movie) {
    this->user_repo.add_movie_user(movie);
}

///function to remove a movie from the user repository
///input : one object of type Domain : movie
///returns true if the movie was removed, false otherwise
bool Services::delete_user(Domain movie) {

    //std::cout << this->user_repo.remove_movie_user(movie) << '\n';
    if(this->user_repo.remove_movie_user(movie))
        return true;
    return false;
}

///function to generate some entries in the admin repository
///adds 10 movies to the admin repository
void Services::generate_entries(){
    this->admin_repo.add_movie_to_repo(Domain("The Curious Case of Benjamin Button", "Fantasy", 2008, 12000, "https://www.youtube.com/watch?v=iH6FdW39Hag"));
    this->admin_repo.add_movie_to_repo(Domain("X-Men : Days of Future Past", "Superhero", 2014, 8000, "https://www.youtube.com/watch?v=pK2zYHWDZKo"));
    this->admin_repo.add_movie_to_repo(Domain("Interstellar", "Dystopian future", 2014, 15000, "https://www.youtube.com/watch?v=2LqzF5WauAw"));
    this->admin_repo.add_movie_to_repo(Domain("Mirciulica", "Drama", 2022, 500, "https://www.youtube.com/watch?v=PU9Mzd1g1Fc"));
    this->admin_repo.add_movie_to_repo(Domain("Scarface", "Crime", 1983, 20000, "https://www.youtube.com/watch?v=a_z4IuxAqpE"));
    this->admin_repo.add_movie_to_repo(Domain("Avatar", "Epic", 2009, 60000, "https://www.youtube.com/watch?v=5PSNL1qE6VY"));
    this->admin_repo.add_movie_to_repo(Domain("Logan", "Superhero", 2017, 10000, "https://www.youtube.com/watch?v=Div0iP65aZo"));
    this->admin_repo.add_movie_to_repo(Domain("The pianist", "Drama", 2002, 4500, "https://www.youtube.com/watch?v=BFwGqLa_oAo"));
    this->admin_repo.add_movie_to_repo(Domain("The social network", "Drama", 2010, 7500, "https://www.youtube.com/watch?v=lB95KLmpLR4"));
    this->admin_repo.add_movie_to_repo(Domain("The imitation game", "Historical", 2014, 2500, "https://www.youtube.com/watch?v=nuPZUUED5uk"));
}
