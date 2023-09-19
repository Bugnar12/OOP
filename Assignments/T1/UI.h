
#ifndef T1_BUGNAR12_1_UI_H
#define T1_BUGNAR12_1_UI_H

#include "Services.h"
#include <iostream>

using namespace std;


class UI {
private:
    Services service;
public:
    void printings();
    void run();
    void remove_ui();
    void display_ui();
    void sequence_find_ui();

};


#endif //T1_BUGNAR12_1_UI_H
