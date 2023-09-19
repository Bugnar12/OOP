//
// Created by Praslea on 3/22/2023.
//


#include "Service.h"

Service::Service(const Repository& r) {
    this->repo = r;
}

void Service::addSong(const Song &s) {
    this->repo.addSong(s);
}

int Service::getSize() const {
    return this->repo.getSize();
}