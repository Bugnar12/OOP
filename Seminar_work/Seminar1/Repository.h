#include "Planet.h"

#ifndef SEMINAR1_REPOSITORY_H
#define SEMINAR1_REPOSITORY_H

typedef struct
{
    Planet planets[10];
    int size;
}Repository;

///create function is a pointer since in the service the repository will be modified

Repository* createRepository(int max_capacity);
void destroyRepository(Repository* which);

int getSize(Repository* which);
void addPlanet(Repository* repository, Planet* planet);
Planet* getAll(Repository* fromWhere);

void testRepository();

#endif //SEMINAR1_REPOSITORY_H
