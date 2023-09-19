#include "Planet.h"
#include <stdlib.h>
#include <string.h>

///malloc calloc realloc


Planet createPlanet(char*    name   , char*   type       , double dist)
{
    Planet p;
    p.name = malloc(sizeof(char) * (strlen((name))+1));
    if(p.name == NULL)
        return p;
    strcpy(p.name, name);

    p.type = malloc(sizeof(char) * (strlen((type))+1));
    if(p.type == NULL)
        return p;
    strcpy(p.type, type);

    p.distToEarth = dist;

    return p;
}

void destroyPlanet(Planet* p)
{
    if(p == NULL)
        return;

    free(p->name);
    free(p->type);
}

char* getName(Planet* p)
{
    if(p == NULL)
        return NULL;
    return p->name;
}