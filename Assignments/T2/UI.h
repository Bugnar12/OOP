#ifndef T2_BUGNAR12_1_UI_H
#define T2_BUGNAR12_1_UI_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Service.h"

using namespace std;

class UI {
private:
    Service serv;
    string filename;
public:
    UI(Service serv, string filename);
    void printMenu();
    void run();
    void printToConsole();
    void addUi();
    void saveFileLowerPriceUi();
    void generateEntries();
};


#endif //T2_BUGNAR12_1_UI_H
