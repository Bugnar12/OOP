#include "Services.h"
#include "Repository.h"
#include "string.h"
#include "stdio.h"

Service* createService(Repository* r, OperationStack* undoStack, OperationStack* redoStack)
///Creates a new service
///input : repository, undoStack, redoStack
///output : the service
{
    Service* serv = (Service*)malloc(sizeof(Service));
    if (serv == NULL)
        return NULL;
    serv->repo = r;
    serv->undoStack = undoStack;
    serv->redoStack = redoStack;
    serv->recordOperation = 1;
    return serv;
}

void destroyService(Service* serv)
///Destroys the service and its elements
///Input: pointer to the service
{
    if(serv == NULL)
        return;
    destroyRepository(serv->repo);
    destroyStack(serv->undoStack);
    destroyStack(serv->redoStack);
    free(serv);
}

int addEstateService(Service* s, char* type, char* address, int surface, int price)
///Adds a new estate to the repository
///If the estate already exists, it will not be added
///Returns 1 if the estate was added, 0 otherwise
{
    Estate* e = createEstate(type, address, surface, price);
    int result = addEstate(s->repo, e);
    if(result == 0)
    {
        if(!checkEmpty(s->redoStack))
        {
            destroyStack(s->redoStack);
            s->redoStack = createStack();
        }
        Operation* op = createOperation(e, "add");
        push(s->undoStack, op);
    }
    return result;
}

int deleteEstateService(Service* s, char* address)
///Deletes an estate from the repository
///If the estate does not exist, it will not be deleted
///Returns 1 if the estate was deleted, 0 otherwise
{
    if(!elementExists(s->repo, createEstate("", address, 0, 0)))
        return -1;
    Estate* trashE = createEstate("", address, 0, 0);
    Estate* e = copyEstate(findEstate(s->repo, trashE));
    int result = deleteEstate(s->repo, e);
    if(result == 0 && s->recordOperation)
    {
        if(!checkEmpty(s->redoStack))
        {
            destroyStack(s->redoStack);
            s->redoStack = createStack();
        }
        Operation* op = createOperation(e, "delete");
        push(s->undoStack, op);
    }
    return result;
}

int updateEstateService(Service* s, char* type, char* address, int surface, int price)
///Updates an estate from the repository
///If the estate does not exist, it will not be updated
///Returns 1 if the estate was updated, 0 otherwise
{
    Estate* newEstate = createEstate(type, address, surface, price);
    Estate* oldEstate = copyEstate(findEstate(s->repo, newEstate));
    if(updateEstate(s->repo, newEstate) == 0 && s->recordOperation)
    {
        if(!checkEmpty(s->redoStack))
        {
            destroyStack(s->redoStack);
            s->redoStack = createStack();
        }
        Operation* op1 = createOperation(newEstate, "update");
        Operation* op2 = createOperation(oldEstate, "update");
        push(s->undoStack, op2);
        push(s->undoStack, op1);
        destroyOperation(op2);
        destroyOperation(op1);
    }
    return 0;

}


DynamicArray* filterIfAddressNull(Service* s)
///Function to sort the objects if the input address is NULL
///input : s - the service(pointer)
///Returns a pointer to the sorted array
{
    int nr;
    DynamicArray* AuxiliaryArray = createDynamicArray(s->repo->estates->size);

    nr = 0;
    for(int i = 0; i < s->repo->estates->size; i++)
        AuxiliaryArray->estates[nr++] = s->repo->estates->estates[i];

    AuxiliaryArray->size = nr;


    for(int i = 0; i < nr - 1; i ++)
        for(int j = i + 1; j < nr; j++)
            if(getPrice(AuxiliaryArray->estates[i]) > getPrice(AuxiliaryArray->estates[j]))
            {
                Estate* aux = AuxiliaryArray->estates[i];
                AuxiliaryArray->estates[i] = AuxiliaryArray->estates[j];
                AuxiliaryArray->estates[j] = aux;
            }
    return AuxiliaryArray;
}

DynamicArray* filterAddressAscendingByPrice(Service* s, char* address)
///Function to sort the objects if the input address is not NULL
///Input : s - the service(pointer)
///returns a pointer to the sorted array
{
    int nr;

    DynamicArray* AuxiliaryArray = createDynamicArray(s->repo->estates->size);

    nr = 0;
    for(int i = 0; i < s->repo->estates->size; i++)
        if(strstr(getAddress(s->repo->estates->estates[i]), address) != NULL)
            AuxiliaryArray->estates[nr++] = s->repo->estates->estates[i];

    AuxiliaryArray->size = nr;

    for(int i = 0; i < nr - 1; i ++)
        for(int j = i + 1; j < nr; j++)
            if(getPrice(AuxiliaryArray->estates[i]) > getPrice(AuxiliaryArray->estates[j]))
            {
                Estate* aux = AuxiliaryArray->estates[i];
                AuxiliaryArray->estates[i] = AuxiliaryArray->estates[j];
                AuxiliaryArray->estates[j] = aux;
            }
    return AuxiliaryArray;
}

DynamicArray* higherSurfaceEstates(Service* s, int surface)
///Function to sort the objects if the input surface is not NULL
///Input : s - the service(pointer), and the surface
///returns a pointer to the sorted array
{
    int nr;
    DynamicArray* AuxiliaryArray = createDynamicArray(s->repo->estates->size);

    nr = 0;
    for(int i = 0; i < s->repo->estates->size; i++)
        if(getSurface(s->repo->estates->estates[i]) > surface)
            AuxiliaryArray->estates[nr++] = s->repo->estates->estates[i];

    AuxiliaryArray->size = nr;

    return AuxiliaryArray;
}

int undoService(Service* s)
///Undoes the last operation
///Input : service
///Output : 1 if the operation was undone, 0 otherwise
{
    if(checkEmpty(s->undoStack))
        return 0;
    Operation* op = pop(s->undoStack);
    if(strcmp(getOperationType(op), "add") == 0)
    {
        Estate* estate = getOperationEstate(op);
        Operation* op2 = createOperation(estate, "delete");
        push(s->redoStack, op2);
        //destroyOperation(op2);
        deleteEstate(s->repo, estate);
    }
    else if(strcmp(getOperationType(op), "delete") == 0)
    {
        Estate* estate = getOperationEstate(op);
        Operation* op2 = createOperation(estate, "add");
        push(s->redoStack, op2);
        //destroyOperation(op2);
        addEstate(s->repo, estate);
    }
    else if(strcmp(getOperationType(op), "update") == 0)
    {
        Operation* newOperation = pop(s->undoStack);
        Estate* estate = getOperationEstate(newOperation);
        updateEstate(s->repo, estate);
        push(s->redoStack, op);
        //destroyOperation(newOperation);
    }
    //destroyOperation(op);
    s->recordOperation = 1;
    return 1;
}

int redoService(Service* s)
///Redoes the last operation
///Input : service
///Returns 1 if the operation was redone, 0 otherwise
{
    if(checkEmpty(s->redoStack))
        return 0;
    Operation* op = pop(s->redoStack);
    if(strcmp(getOperationType(op), "add") == 0)
    {
        Estate* estate = getOperationEstate(op);
        deleteEstate(s->repo, estate);
    }
    else if(strcmp(getOperationType(op), "delete") == 0)
    {
        Estate* estate = getOperationEstate(op);
        addEstate(s->repo, estate);
    }
    else if(strcmp(getOperationType(op), "update") == 0)
    {
        Estate* estate = getOperationEstate(op);
        //printf("%s %s %d %d", getType(estate), getAddress(estate), getSurface(estate), getPrice(estate));
        updateEstate(s->repo, estate);
    }
    //destroyOperation(op);
    s->recordOperation = 1;
    return 1;
}


