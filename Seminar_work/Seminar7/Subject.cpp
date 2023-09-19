#include "Subject.h"

void Subject::registerObserver(Observer *obs) {
    std::vector<Observer*>::iterator it;
    it = find(this->observers.begin(), this->observers.end(), obs);
    if(it == this->observers.end())
        this->observers.push_back(obs);
}

void Subject::unregisterObserver(Observer *obs) {
    std::vector<Observer*>::iterator it;
    it = find(this->observers.begin(), this->observers.end(), obs);
    if(it != this->observers.end())
        this->observers.erase(it);
}

void Subject::notify() {
    for(auto & obs : this->observers)
        obs->update();
}
