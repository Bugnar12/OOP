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

    Domain movie2 = Domain("disa", "dsjia", 1990, 2900, "");
//    assert(movie1.play() == 1);
//    assert(movie2.play() == 0);

    ///Test the play function from the domain

    cout << "Domain tests passed !\n";
}

/////Test function for the dynamic array vector STL

//void Tests::dyn_array_stl_tests() {
//DynamicArray<Domain> elements;
//    Domain movie1 = Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4");
//    Domain movie2 = Domain("disa", "dsjia", 1990, 2900, "");
//    Domain movie3 = Domain("disa", "dsjia", 1990, 2900, "");
//    elements.addElementDynamic(movie1);
//    elements.addElementDynamic(movie2);
//    elements.addElementDynamic(movie3);
//    assert(elements.getSize() == 3);
//    elements.removeElementDynamic(1);
//    assert(elements.getSize() == 2);
//    assert(elements.getElement(0) == movie1);
//    assert(elements.getElement(1) == movie3);
//    elements.updateElementDynamic(movie2, 1);
//    assert(elements.getElement(1) == movie2);
//    elements.addElementDynamic(movie1);
//    assert(elements.getSize() == 3);
//    elements.removeElementDynamic(0);
//    assert(elements.getSize() == 2);
//
//    cout << "Dynamic array tests passed !\n";
//}


///Test function for the admin repository
void Tests::admin_repo_tests() {
    std::vector<Domain> elements;
    AdminRepo repo;
    repo.add_movie_to_repo(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    ///I want to test the throwing of an exception from the add function in the admin repo

    try {
        repo.add_movie_to_repo(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
        assert(false);
    }
    catch (const std::exception& e) {
        assert(true);
    }

    Domain movie1 = Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4");
    assert(repo.get_size_of_repo() == 1);

    Domain movie2 = Domain("dsi", "action", 1996, 20020, "https://www.youtube.com/watch?v=9FXCSXuGTF4");
    repo.update_movie_from_repo(movie1, movie2);

    assert(repo.getMovies()[0].getReleaseYear() == 1996);

    Domain movie3 = Domain("dsa", "action", 1996, 20020, "https://www.youtube.com/watch?v=9FXCSXuGTF4");

    ///I want to test the throwing of an exception from the update function in the admin repo

    repo.remove_movie_from_repo(movie1);

    try {
        repo.update_movie_from_repo(movie1, movie3);
        assert(false);
    }
    catch (const std::exception& e) {
        assert(true);
    }

    ///Same thing as above
    try {
        repo.remove_movie_from_repo(movie1);
        assert(false);
    }
    catch (const std::exception& e) {
        assert(true);
    }
    assert(repo.get_size_of_repo() == 0);

    cout << "Admin repo tests passed !\n";
}

void Tests::user_repo_tests() {
    ///Test the user repo just like the admin repo

    UserRepo repo;
    repo.add_movie_user(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    assert(repo.get_user_size() == 1);
    repo.remove_movie_user(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    assert(repo.get_user_size() == 0);
    ///Now test with try catch
    try {
        repo.remove_movie_user(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
        assert(false);
    }
    catch (const std::exception& e) {
        assert(true);
    }
    Domain movie1 = Domain("abcd", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4");
    repo.add_movie_user(movie1);
    ///Test the update function
    repo.update_movie_user(movie1, Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    assert(repo.get_user_size() == 1);
    assert(repo.get_watch_list()[0].getTitle() == "abc");
    ///Now test with try and catch

    repo.remove_movie_user(movie1);


    try {
        repo.update_movie_user(movie1, Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
        assert(false);
    }
    catch (const std::exception& e) {
        assert(true);
    }

    cout << "User repo tests passed !\n";


}

void Tests::services_tests() {
    AdminRepo admin_repo;
    UserRepo user_repo;
    Services serv;

    serv.add_admin_repo(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    serv.add_admin_repo(Domain("aosd", "adventure", 2002, 2030, "https://www.youtube.com/watch?v=9FXCSXjGTF4"));

    assert(serv.get_admin_repo().get_size_of_repo() == 2);
    assert(serv.get_user_repo().get_user_size() == 0);

    serv.add_user(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4"));
    serv.add_user(Domain("aosd", "adventure", 2002, 2030, "https://www.youtube.com/watch?v=9FXCSXjGTF4"));
    assert(serv.get_user_repo().get_user_size() == 2);

    serv.remove_admin_repo(Domain("abc", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGTF4")); ///first movie removed

    assert(serv.get_user_repo().get_user_size() == 1);
    assert(serv.get_admin_repo().get_size_of_repo() == 1);

    Domain movie = Domain("kdsa", "action", 1995, 20030, "https://www.youtube.com/watch?v=9FXCSXuGdF4");
    serv.add_user(movie);

    Domain movie1 = Domain("abcw", "aasd", 1935, 530, "https://www.youtube.com/watch?v=9ghXCSXuGTF4");
    serv.update_admin_repo(Domain("aosd", "adventure", 2002, 2030, "https://www.youtube.com/watch?v=9FXCSXjGTF4"), movie1);

    assert(serv.get_admin_repo().getMovies()[0].getTitle() == "abcw");
    assert(serv.get_admin_repo().getMovies()[0].getNrOfLikes() == 530);
    assert(serv.get_user_repo().get_watch_list()[0].getTitle() == "abcw");

    serv.delete_user(movie);
    assert(serv.get_user_repo().get_user_size() == 1);

    serv.generate_entries();

    assert(serv.get_admin_repo().get_size_of_repo() == 11);


    cout << "Services tests passed ! \n";
}

void Tests::run_all_tests() {
    domain_tests();
    admin_repo_tests();
    user_repo_tests();
    services_tests();
    cout << "All tests passed ! \n";
}
