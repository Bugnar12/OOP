#include "Services.h"
#include <iostream>

Services::Services(std::string admin_filename, UserRepo *userRepo) : admin_repo{AdminRepo(admin_filename)},
                                                                    user_repo{userRepo} {}

///getter for the admin_repo
AdminRepo Services::get_admin_repo() const {
    return this->admin_repo;
}

///getter for the user_repo
UserRepo *Services::get_user_repo() const{
    return this->user_repo;
}
//
/////function to add a movie to the admin repository
/////input : one const object of type Domain : new_movie
/////returns true if the movie was added, false otherwise
void Services::add_admin_repo(const Domain &new_movie) {
    this->admin_repo.add_movie_to_repo(new_movie);
}

///function to remove to the admin repository, if it is in the user repo it will be removed from there too
///input : one object of type Domain : existing_movie
///returns true if the movie was removed, false otherwise
void Services::remove_admin_repo(Domain existing_movie) {
    std::vector<Domain>::iterator it = find(this->user_repo->get_watch_list().begin(), this->user_repo->get_watch_list().end(), existing_movie);

    ///if the movie desired to be deleted is found in the user repo, we delete it from there too
    if(it != this->user_repo->get_watch_list().end())
    {
        this->user_repo->remove_movie_user(existing_movie);
    }
    this->admin_repo.remove_movie_from_repo(existing_movie);
}

/////function to update the admin repository, and translate the update into the user repository
/////input : 2 objects of type Domain : existing_movie and new_movie
/////returns true if the movie was updated, false otherwise
void Services::update_admin_repo(Domain existing_movie, Domain new_movie) {
    auto it = find(this->user_repo->get_watch_list().begin(), this->user_repo->get_watch_list().end(), existing_movie);

    ///if the movie desired to be updated is found in the user repo, we update it from there too
    if(it != this->user_repo->get_watch_list().end())
        this->user_repo->update_movie_user(existing_movie, new_movie);

    this->admin_repo.update_movie_from_repo(existing_movie, new_movie);
}

/////function to add a movie to the user repository
/////input : one object of type Domain : movie
void Services::add_user(Domain movie) {
    this->user_repo->add_movie_user(movie);
}

/////function to remove a movie from the user repository
/////input : one object of type Domain : movie
/////returns true if the movie was removed, false otherwise
void Services::delete_user(Domain movie) {

    this->user_repo->remove_movie_user(movie);
}

std::vector<Domain> Services::genre_cascade(std::string genre) {
    std::vector<Domain> movies = this->admin_repo.getMovies();
    std::vector<Domain> movies_filtered;

    if(genre == "")
    {
        for(auto & movie : movies)
        {
            movies_filtered.push_back(movie);
        }
    }

    for(auto & movie : movies)
    {
        if(movie.getGenre() == genre)
            movies_filtered.push_back(movie);
    }

    return movies_filtered;
}

int Services::nr_movies_with_a_genre(std::string genre) {
    std::vector<Domain> movies = this->admin_repo.getMovies();
    int counter = 0;

    if(genre == "")
    {
        for(auto & movie : movies)
        {
            counter++;
        }
    }

    for(auto & movie : movies)
    {
        if(movie.getGenre() == genre)
            counter++;
    }

    return counter;
}
