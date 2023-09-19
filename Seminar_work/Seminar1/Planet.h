#ifndef SEMINAR1_PLANET_H
#define SEMINAR1_PLANET_H

typedef struct{
    char* name; ///pointer to the first element in the array
    char* type;
    double distToEarth;
}Planet;

Planet createPlanet(char*   name    , char*    type      , double dist);
void destroyPlanet(Planet* p); ///passing by value => a copy of the planet is made, not correct

char* getName(Planet* p);


#endif //SEMINAR1_PLANET_H
