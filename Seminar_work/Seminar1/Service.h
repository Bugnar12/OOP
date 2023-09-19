#pragma once
#include "Repository.h"

#ifndef SEMINAR1_SERVICE_H
#define SEMINAR1_SERVICE_H

typedef struct
{
    Repository* repo;
}Service;

Service* createService(Repository* r);
void destroyService(Service *s);
void addPlanetService(Service* s, char* name, char* type, double dist);
int getsizeArray()





#endif //SEMINAR1_SERVICE_H
