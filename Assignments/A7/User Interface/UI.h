#ifndef A45_BUGNAR12_UI_H
#define A45_BUGNAR12_UI_H

#include "Service/Services.h"
#include <vector>
#include <algorithm>
#include "Repositroy/CSV_Repository.h"
#include "Repositroy/HTML_Repository.h"
#include "Validator/Validators.h"

class UI {
private:
    Services service;
    Validators validator;
public:
    UI(Services service);

    void run();
    int find(std::vector<Domain>, Domain m);

    static void printMenu();
    static void printAdminRepo();
    static void printUserRepo();

    int input_releaseYear();
    int input_nrOfLikes();

    void addMovieAdminUI();
    void removeMovieAdminUI();
    void updateMovieAdminUI();

    std::string genre_input();
    std::string response_input();

    void get_user_genre();
    void remove_movie_user();

    void displayMoviesAdmin();
    void displayWatchList();
};


#endif //A45_BUGNAR12_UI_H
