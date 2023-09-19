#ifndef SEMINAR7_SUBJECT_H
#define SEMINAR7_SUBJECT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.h"

using namespace std;

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void registerObserver(Observer* obs);
    void unregisterObserver(Observer* obs);
    void notify();

};


#endif //SEMINAR7_SUBJECT_H
