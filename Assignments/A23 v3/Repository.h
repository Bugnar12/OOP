#ifndef A23_V2_REPOSITORY_H
#define A23_V2_REPOSITORY_H

#include <stdbool.h>
#include "Domain.h"
#include "DynamicArray.h"

typedef struct {
    DynamicArray* estates;
}Repository;

///create function is a pointer since in the service the repository will be modified

Repository* createRepository();
void destroyRepository(Repository* repo);
int elementExists(Repository* repo, Estate* estate);
int getSize(Repository* repo);
int addEstate(Repository* repo, Estate* e);
int deleteEstate(Repository* repo, Estate* e);
int updateEstate(Repository* repo, Estate* e);
DynamicArray* getByAddress(Repository* repo, char* address); //!!! changed
DynamicArray* getAll(Repository* repo);
DynamicArray * getEstateByIndex(Repository* repo, int index);
Estate* findEstate(Repository* repo, Estate* estate);
Estate* findEstateContainingAddress(Repository* repo, char* address);

#endif //A23_V2_REPOSITORY_H
