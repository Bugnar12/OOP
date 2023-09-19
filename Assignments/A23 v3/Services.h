
#ifndef A23_V2_SERVICES_H
#define A23_V2_SERVICES_H

#include "Repository.h"
#include "Domain.h"
#include "Operations.h"

typedef struct {
    Repository* repo;
    OperationStack *undoStack;
    OperationStack *redoStack;
    int recordOperation;

}Service;

Service* createService(Repository* r, OperationStack* undoStack, OperationStack* redoStack);
void destroyService(Service* s);

int addEstateService(Service* s, char* type, char* address, int surface, int price);
int deleteEstateService(Service* s, char* address);
int updateEstateService(Service* s, char* type, char* address, int surface, int price);
DynamicArray* filterAddressAscendingByPrice(Service* s, char* address);
DynamicArray* filterIfAddressNull(Service* s);
DynamicArray* higherSurfaceEstates(Service* s, int surface);

int undoService(Service* s);
int redoService(Service* s);


#endif //A23_V2_SERVICES_H
