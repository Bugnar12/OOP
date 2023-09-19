//
// Created by Praslea on 3/22/2023.
//

#ifndef SEMINAR2_911_SERVICE_H
#define SEMINAR2_911_SERVICE_H
#include "Repository.h"


class Service {
private:
    Repository& repo;
public:
    Service(const Repository& r);
    void addSong(const Song& s);

    int getSize() const;
};


#endif //SEMINAR2_911_SERVICE_H
