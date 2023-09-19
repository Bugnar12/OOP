#include "Tests.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "Repository.h"
#include "Services.h"
#include "DynamicArray.h"
#include "Operations.h"
#include "Validator.h"


void testDomain()
///Test for domain
{
    Estate* e = createEstate("APARTAMENT", "M.Viteazu", 100, 10000);

    assert(getSurface(e) == 100);
    assert(getPrice(e) == 10000);
    assert(strcmp(getType(e), "APARTAMENT") == 0);
    assert(strcmp(getAddress(e), "M.Viteazu") == 0);

    setSurface(e, 50);
    assert(getSurface(e) == 50);

    setPrice(e, 50);
    assert(getPrice(e) == 50);

    setType(e, "HOUSE");
    assert(strcmp(getType(e), "HOUSE") == 0);

    setAddress(e, "M.Viteazu");
    assert(strcmp(getAddress(e), "M.Viteazu") == 0);

    Estate* e3 = createEstate("house", "G.Balan", 300, 200);
    Estate* e4 = copyEstate(e3);
    assert(strcmp(getAddress(e3), "G.Balan") == 0);
    assert(strcmp(getAddress(e4), "G.Balan") == 0);

    printf("Test Domain: OK\n");

    destroyEstate(e3);

    destroyEstate(e);
    destroyEstate(e4);

}

void testDynamicArray()
///Test for the D.S. Dynamic Array
{
    DynamicArray* array = createDynamicArray(15);

    Estate* e = createEstate("APARTAMENT", "M.Viteazu", 100, 10000);
    assert(addElementDynamic(array, e) == 0);
    assert(elementExistsDynamic(array, e) == 1);
    assert(array->size == 1);

    Estate* e1 = getByElementDynamic(array, e);
    assert(strcmp(getAddress(e1), "M.Viteazu") == 0);
    assert(getPrice(e1) == 10000);

    Estate* e2 = createEstate("APARTAMENT", "M.Eminescu", 100, 10000);
    assert(updateElementDynamic(array, e2) == -1);

    assert(updateElementDynamic(array, e) == 0);

    assert(deleteElementDynamic(array, e) == 0);
    assert(array->size == 0);

    assert(getSizeDynamic(array) == 0);
    assert(getAllDynamic(array) != NULL);

    assert(addElementDynamic(array, e2) == 0);
    assert(getByPosition(array, 0) == e2);
    assert(getByPosition(array, 1) == NULL);
    assert(elementExistsDynamic(array, e2) == 1);

    DynamicArray* array2 = createDynamicArray(5);
    assert(addElementDynamic(array2, e2) == 0);
    Estate* e3 = createEstate("APARTAMENT", "D.Voda", 100, 50);
//    DynamicArray* array3 = createDynamicArray(-1);
//    assert(addElementDynamic(array3, e3) == -1);

    assert(array2->maxCapacity == 5);
    assert(addElementDynamic(array2, e3) == 0);
    assert(array2->maxCapacity == 5);

    ///test the resize function
    assert(resize(array2) == 0);
    assert(array2->maxCapacity == 10);
    assert(addElementDynamic(array2, e3) == 0);
    assert(array2->maxCapacity == 10);
    assert(addElementDynamic(array2, e3) == 0);
    assert(array2->maxCapacity == 10);

    Estate* e4 = NULL;
    DynamicArray* array3 = NULL;
    assert(addElementDynamic(array3, e4) == -1);

    Estate* e5 = createEstate("APARTAMENT", "Marius", 150, 400);

    assert(getByElementDynamic(array2, e5) == NULL);



    destroyDynamicArray(array);



//    destroyDynamicArray(array3);
//
//    destroyDynamicArray(array2);
//    destroyEstate(e3);

    printf("Test Dynamic Array: OK\n");

}

void testRepository()
/// Tests the repository

{
    Repository* repo = createRepository();

    Estate* e = createEstate("APARTAMENT", "M.Viteazu", 100, 10000);
    assert(addEstate(repo, e) == 0);
    assert(elementExists(repo, e) == 1);
    assert(getSize(repo) == 1);

    Estate* e1 = findEstate(repo, e);
    assert(strcmp(getAddress(e1), "M.Viteazu") == 0);
    assert(getPrice(e1) == 10000);
    assert(strcmp(getType(e1), "APARTAMENT") == 0);
    assert(getSurface(e1) == 100);

    Estate* e2 = createEstate("APARTAMENT", "M.Eminescu", 100, 10000);
    assert(addEstate(repo, e2) == 0);
    assert(getSize(repo) == 2);

    assert(updateEstate(repo, e) == 0);
    assert(getSize(repo) == 2);

    assert(deleteEstate(repo, e) == 0);
    assert(getSize(repo) == 1);

    assert(addEstate(repo, e2) == -1);
    Estate* e3 = createEstate("house", "Rares", 100, 510);
    assert(deleteEstate(repo, e3) == -1);

    assert(getAll(repo) != NULL);

    assert(findEstateContainingAddress(repo, "M.Eminescu") == e2);

    printf("Test Repository: OK \n");

    destroyEstate(e3);
    destroyRepository(repo);
}


void testOperations()
///Tests the operations
{
    Estate *estate = createEstate("house", "Goga", 100, 510);
    Operation *operation = createOperation(estate, "add");

    OperationStack *stack = createStack();
    assert(checkEmpty(stack) == 1);
    assert(checkFull(stack) == 0);

    push(stack, operation);
    assert(checkEmpty(stack) == 0);
    assert(checkFull(stack) == 0);

    Operation *operation2 = createOperation(estate, "add");
    operation2 = pop(stack);
    assert(checkEmpty(stack) == 1);

    destroyEstate(estate);
    destroyOperation(operation);
    destroyOperation(operation2);
    destroyStack(stack);

    printf("Test Operations : OK\n");
}

void testService()
///Tests the service
{

    DynamicArray* array = createDynamicArray(10);
    Repository* repo = createRepository();
    OperationStack* undoStack = createStack();
    OperationStack* redoStack = createStack();


    Service* service = createService(repo, undoStack, redoStack);

    assert(addEstateService(service, "house", "Goga", 100, 510) == 0);
    assert(addEstateService(service, "house", "Goga", 100, 510) == -1);

    assert(deleteEstateService(service, "Goga") == 0);
    assert(deleteEstateService(service, "Goga") == -1);

    Estate* e1 = createEstate("penthouse", "Peter", 205, 4000);
    assert(addEstateService(service, "penthouse", "Peter", 205, 4000) == 0);
    assert(checkEmpty(service->undoStack) == 0);
    assert(updateEstateService(service, "penthouse", "Peter", 205, 500) == 0);
    assert(deleteEstateService(service, "Peter") == 0);
    assert(checkEmpty(service->undoStack) == 0);

    ///test the undo and redo functions
    assert(addEstateService(service, "penthouse", "Peter", 205, 4000) == 0);
    assert(updateEstateService(service, "penthouse", "Peter", 205, 500) == 0);
    assert(deleteEstateService(service, "Peter") == 0);
    assert(undoService(service) == 1);
    assert(undoService(service) == 1);
    assert(undoService(service) == 1);
    assert(undoService(service) == 1);
    assert(redoService(service) == 1);
    assert(redoService(service) == 1);
    assert(redoService(service) == 1);
    assert(redoService(service) == 1);

    Estate* e2 = createEstate("house", "John", 300, 4500);

    ///test the higherSurfaceEstates() function from service
    assert(addEstateService(service, "penthouse", "Peter", 205, 4000) == 0);
    assert(addEstateService(service, "house", "John", 300, 4500) == 0);
    assert(higherSurfaceEstates(service, 200) != NULL);
    assert(filterAddressAscendingByPrice(service, "house") != NULL);
    assert(filterIfAddressNull(service) != NULL);




    printf("Test Services: OK\n");

    destroyStack(undoStack);
    destroyStack(redoStack);
    destroyDynamicArray(array);
   // destroyService(service);
}

void testValidator()
{

    char* type = "house";
    char* address = "Goga";
    char* surface = "100";
    char* price = "510";

    assert(validateType(type) == 1);
    assert(validateAddress(address) == 1);
    assert(validateSurface(surface) == 1);
    assert(validatePrice(price) == 1);

    char* type2 = "";
    char* address2 = "";
    char* surface2 = "pa";
    char* price2 = "sd";

    assert(validateType(type2) == 0);
    assert(validateAddress(address2) == 0);
    assert(validateSurface(surface2) == 0);
    assert(validatePrice(price2) == 0);

    char* surface3 = "";
    char* price3 = "";
    assert(validateSurface(surface3) == 0);
    assert(validatePrice(price3) == 0);


    char* type3 = "housee";
    assert(validateType(type3) == 0);

    printf("Test Validator: OK\n");

}
