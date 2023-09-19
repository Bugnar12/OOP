//
// Created by Praslea on 3/22/2023.
//

#ifndef SEMINAR2_911_REPOSITORY_H
#define SEMINAR2_911_REPOSITORY_H
#include "DynamicVector.h"

class Repository {
private:
    DynamicVector songs;
public:
    void addSong(const Song& s);
    DynamicVector getAll() const;
    int getSize() const;
};


#endif //SEMINAR2_911_REPOSITORY_H
