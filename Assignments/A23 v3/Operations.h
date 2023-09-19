#include "Domain.h"
#include "DynamicArray.h"

#ifndef A23_V2_OPERATIONS_H
#define A23_V2_OPERATIONS_H

typedef struct{
    Estate* estate;
    char* operationType;
}Operation;

Operation* createOperation(Estate* estate, char* operation);

void destroyOperation(Operation* operation);

Operation* copyOperation(Operation* operation);

char* getOperationType(Operation* operation);

Estate* getOperationEstate(Operation* operation);

typedef struct{
    Operation* operations[100];
    int lengthOperations;
}OperationStack;

OperationStack* createStack();

void destroyStack(OperationStack* stack);

void push(OperationStack* stack, Operation* operation);

Operation* pop(OperationStack* stack);

int checkEmpty(OperationStack* stack);

int checkFull(OperationStack* stack);

#endif //A23_V2_OPERATIONS_H
