#include "Tests.h"
#include <cassert>

#include "Services.h"

#include <iostream>

using namespace std;

///Testing function for the domain of the application
void Tests::domain_tests() {
    Domain movie1 = Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4");
    movie1 = movie1;
    assert(movie1 == movie1);
    assert(movie1.toStr() == "Title : abc - Genre : action - Release year : 1995 - Number of likes : 20030 - Trailer : https://www.youtube.com/watch?v=9FXCSXuGTF4");

    assert(movie1.getTitle() == "abc");
    assert(movie1.getGenre() == "action");
    assert(movie1.getReleaseYear() == 1995);
    assert(movie1.getNrOfLikes() == 20030);
    assert(movie1.getTrailer() == "https://www.youtube.com/watch?v=9FXCSXuGTF4");

    ///Test the play function from the domain

    //assert(movie1.play() == 1);

    cout << "Domain tests passed !\n";
}

///Test function for the dynamic array template
void Tests::dyn_array_template_tests() {
    DynamicArray<Domain> da = DynamicArray<Domain>(2);
    Domain movie1 = Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4");
    Domain movie2 = Domain("kdas", "adventure", 1989, 1050, "https://www.youtube.com/watch?v=9FX43XuGTF4");
    da.addDynamic(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    da.addDynamic(Domain("kdas", "adventure", 1989, 1050, "https://www.youtube.com/watch?v=9FX43XuGTF4"));
    assert(da.getSize() == 2);
    da.removeDynamic(0);
    assert(da.getSize() == 1);

    DynamicArray<Domain> da2 = DynamicArray<Domain>(da);
    da2 = da;
    da = da;
    assert(da.getSize() == 1);
    assert(da2.getSize() == 1);

    da.addDynamic(Domain("kisi", "whatever", 2030, 4000, "https://www.youtube.com/watch?v=9FX435a0TF4"));
    da.addDynamic(Domain("sosi", "Losa", 1030, 1500, "https://www.youtube.com/watch?v=aFX435a0TF4"));

    da.updateDynamic(movie2,0);

    assert(da.getSize() == 3);


    cout << "Dynamic array (template) tests passed!\n";
}

///Test function for the admin repository
void Tests::admin_repo_tests() {
    DynamicArray<Domain> da1 = DynamicArray<Domain>(10);
    AdminRepo repo;
    repo.add_movie_to_repo(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    Domain movie1 = Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4");
    assert(repo.get_size_of_repo() == 1);
    assert(repo.add_movie_to_repo(movie1) == false);
    assert(repo.get_size_of_repo() == 1);
    assert(repo.get_size_of_repo() == 1);
    assert(repo.remove_movie_from_repo(movie1) == true);
    assert(repo.remove_movie_from_repo(movie1) == false);

    repo.add_movie_to_repo(movie1);
    assert(repo.get_size_of_repo() == 1);

    Domain movie2 = Domain("kdas", "adventure", 1989, 1050, "https://www.youtube.com/watch?v=9FX43XuGTF4");

    repo.update_movie_from_repo(movie1, movie2);
    assert(repo.getMovies().getElement(0).getNrOfLikes() == 1050);
    Domain movie3 = Domain("ids", "co", 421, 42, "https://www.youtube.com/watch?v=9FX43XuGdsa4");
    assert(repo.get_size_of_repo() == 1);
    repo.add_movie_to_repo(movie2);
    assert(repo.update_movie_from_repo(movie2, movie3) == true);
    Domain movie4 = Domain("ids", "csao", 421, 42, "https://www.youtube.com/watch?v=9FX4353XuGdsa4");
    assert(repo.update_movie_from_repo(movie2, movie3) == false);


    cout << "Admin repo tests passed !\n";
}

void Tests::user_repo_tests() {
    DynamicArray<Domain> da1 = DynamicArray<Domain>(10);
    UserRepo repo;
    Domain movie1 = Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4");
    repo.add_movie_user(movie1);
    assert(repo.get_size() == 1);
    Domain movie2 = Domain("dsi", "action", 1996, 20020, "https://www.youtube.com/watch?v=9FXCSXuGTF4");
    repo.update_movie_user(movie1, movie2);
    assert(repo.get_watch_list().getElement(0).getReleaseYear() == 1996);
    repo.remove_movie_user(movie1);
    assert(repo.get_size() == 0);

    cout << "All user repo tests passed ! \n";

}

void Tests::services_tests() {
    AdminRepo repo;
    Services serv;
    serv.add_admin_repo(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    Domain movie1 = Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4");
    assert(serv.get_admin_repo().get_size_of_repo() == 1);
    assert(serv.add_admin_repo(movie1) == false);
    assert(serv.get_admin_repo().get_size_of_repo() == 1);
    assert(serv.remove_admin_repo(movie1) == true);
    assert(serv.remove_admin_repo(movie1) == false);

    serv.add_admin_repo(movie1);
    assert(serv.get_admin_repo().get_size_of_repo() == 1);

    Domain movie2 = Domain("kdas", "adventure", 1989, 1050, "https://www.youtube.com/watch?v=9FX43XuGTF4");

    serv.update_admin_repo(movie1, movie2);
    assert(serv.get_admin_repo().getMovies().getElement(0).getNrOfLikes() == 1050);
    Domain movie3 = Domain("ids", "co", 421, 42, "https://www.youtube.com/watch?v=9FX43XuGdsa4");
    assert(serv.get_admin_repo().get_size_of_repo() == 1);
    serv.add_admin_repo(movie2);
    assert(serv.update_admin_repo(movie2, movie3) == true);
    Domain movie4 = Domain("ids", "csao", 421, 42, "https://www.youtube.com/watch?v=9FX4353XuGdsa4");
    assert(serv.update_admin_repo(movie2, movie3) == false);

    assert(serv.remove_admin_repo(movie3) == true);

    serv.generate_entries();

    assert(serv.get_admin_repo().get_size_of_repo() == 10);


    UserRepo repo2;
    serv.add_admin_repo(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    serv.add_user(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    serv.remove_admin_repo(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    assert(serv.get_user_repo().get_size() == 0);
    serv.delete_user(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    assert(serv.get_user_repo().get_size() == 0);

    serv.add_admin_repo(Domain("abc", "action", 1995, 25030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    serv.add_user(Domain("abc", "action", 1995, 25030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    assert(serv.delete_user(Domain("abc", "action", 1995, 25030, "https://www.youtube.com/watch?v=9FXCSXuGTF4")) == true);

    repo2 = serv.get_user_repo();
    assert(repo2.get_size() == 0);

    cout << "All service tests passed ! \n";
}

void Tests::run_all_tests() {
    domain_tests();
    dyn_array_template_tests();
    admin_repo_tests();
    user_repo_tests();
    services_tests();
    cout << "All tests passed ! \n";
}
