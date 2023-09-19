#include "Repository.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

Repository* createRepository(){
    /// Creates a new repository
    /// Returns a pointer to the repository
    /// Returns NULL if the memory allocation fails

    Repository* repo = (Repository*)malloc(sizeof(Repository));
    if (repo == NULL)
        return NULL;
    repo->estates = createDynamicArray(100);
    return repo;

}

void destroyRepository(Repository* repo){
    ///Destroys the repository and its elements(estates)
    destroyDynamicArray(repo->estates);
    free(repo);
}

int elementExists(Repository* repo, Estate* estate)
///Checks if an estate exists in the repository
///Returns : 1 if the estate exists, 0 otherwise
{
    return elementExistsDynamic(repo->estates, estate);
}

int getSize(Repository* repo)
///returns the size of the repository
{
    return repo->estates->size;
}


int addEstate(Repository* repo, Estate* new_estate)
///Adds a new estate to the repository
///If the estate already exists, it will not be added
///Input : repo - the repository where the estate will be added and an estate
{
    if(elementExists(repo, new_estate))
        return -1;
    addElementDynamic(repo->estates, new_estate);
    return 0;

}

int deleteEstate(Repository* repo, Estate* new_estate)
///Deletes an estate from the repository
///If the estate does not exist, it will not be deleted
{
    if(!elementExists(repo, new_estate))
        return -1;
    deleteElementDynamic(repo->estates, new_estate);
    return 0;
}

int updateEstate(Repository* repo, Estate* estate)
///Updates an estate in the repository
///If the estate does not exist, it will not be updated
{
    if(!elementExists(repo, estate))
        return -1;
    updateElementDynamic(repo->estates, estate);
    return 0;
}

DynamicArray* getAll(Repository* repo)
///Input : repo - the repository where the estate will be added and an estate
///Returns a pointer to the repository
///Returns NULL if the memory allocation fails
{
    return repo->estates;
}

//DynamicArray* getByAddress(Repository* repo, char* address)
/////Input : repo - the repository where the estate will be added and an estate and an address
/////Returns a pointer to the repository
/////Returns NULL if the memory allocation fails
//{
//    for(int i = 0; i < repo->estates->size; i++)
//        if(strcmp(repo->estates->estates[i]->address, address) == 0)
//            return &(repo->estates[i]);
//    return NULL;
//}

//DynamicArray* getEstateByIndex(Repository* repo, int index)
//////Input : repo - the repository where the estate will be added and an estate and an index
/////Returns a pointer to the repository
/////Returns NULL if the memory allocation fails
//{
//    return &(repo->estates[index]);
//}

Estate* findEstate(Repository* repo, Estate* estate)
///Input : repo - the repository where the estate will be added and an estate
////Returns a pointer to the repository
{
    return getByElementDynamic(repo->estates, estate);
}

Estate* findEstateContainingAddress(Repository* repo, char* address)
///Returns NULL if the memory allocation fails
///Input : repo - the repository where the estate will be added and an estate and an address
{
    for(int i = 0; i < repo->estates->size; i++)
        if(strstr(repo->estates->estates[i]->address, address) != NULL)
            return repo->estates->estates[i];
    return NULL;
}