#include "Repository.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

Repository* createRepository(int max_capacity)
{
    Repository* repo = malloc(sizeof(Repository));
    if(repo == NULL)
        return repo;
    repo->size = 0;
    repo->planets = malloc(sizeof(Planet) * max_capacity);
    return repo;
}

void destroyRepository(Repository* which)
{
    if(which == NULL)
        return;
    for(int i = 0; i < getSize(which); i++)
        destroyPlanet(&(which->planets[i]));
    free(which->planets);
    free(which);
}

void testRepository(){
    Repository* repo = createRepository(10);
    Planet planet = createPlanet("MKSMADPOjd", "fkdosa932K", 10);
    addPlanet(repo, &planet);

    assert(getSize(repo) == 1);

    Planet planet2 = createPlanet("MKSMADPOjd", "fkdosa932K", 10);

    addPlanet(repo, &planet);

    Planet* planets = getAll(repo);
    assert(strcmp(getName(&planets[0]), getName(&planets[1])) == 0);

    destroyRepository(repo);

}

int getSize(Repository* which)
{
    if(which == NULL)
        return 0;
    return which->size;
}

void addPlanet(Repository* repository, Planet* planet)
{
    repository->planets[repository->size++] = *planet; ///asuming we have enough capacoty

}

Planet* getAll(Repository* fromWhere)
{
    if(fromWhere == NULL)

}
