#include "Services.h"

#ifndef A45_BUGNAR12_UI_H
#define A45_BUGNAR12_UI_H


class UI {
private:
    Services service;
public:
    void run();
    bool isNumber(const std::string &str);

    static void printMenu();
    static void printAdminRepo();
    static void printUserRepo();

    void addMovieAdminUI();
    void removeMovieAdminUI();
    void updateMovieAdminUI();

    static std::string genre_input();
    static std::string response_input();

    void get_user_genre();
    void remove_movie_user();

    void displayMoviesAdmin();
    void displayWatchList();
};


#endif //A45_BUGNAR12_UI_H
