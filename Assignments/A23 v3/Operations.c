#include "Operations.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Operation* createOperation(Estate* estate, char* operation)
///Creates a new operation
///Input: estate - Estate* and char* operation
///Output: Operation*
{
    Operation* op = (Operation*)malloc(sizeof(Operation));
    op->estate = copyEstate(estate);

    op->operationType = (char*)malloc(sizeof(char) * (strlen(operation) + 1));
    strcpy(op->operationType, operation);

    return op;
}

void destroyOperation(Operation* operation)
///Destroys an operation
///Input : Operation*
///Output : -
{
    destroyEstate(operation->estate);
    free(operation->operationType);
    free(operation);
}

Operation* copyOperation(Operation* operation)
///Copies an operation
///Input: Operation*
///Output: Operation*
{
    Operation* new_op = createOperation(getOperationEstate(operation), getOperationType(operation));
    return new_op;
}

char* getOperationType(Operation* operation)
///Returns the type of the operation(getter)
{
    return operation->operationType;
}

Estate* getOperationEstate(Operation* operation)
///Returns the estate of the operation(getter)
{
    return operation->estate;
}

OperationStack* createStack()
///Creates the stack of operations
/// Output : the corresponding stack
{
    OperationStack* stack = (OperationStack*)malloc(sizeof(OperationStack));
    stack->lengthOperations = 0;
    return stack;
}

void destroyStack(OperationStack* stack)
///Destroys the stack of operations
///Input : pointer to the stack
///Output : -
{
    int i;
    for(i = 0; i < stack->lengthOperations; i++)
        destroyOperation(stack->operations[i]);

    free(stack);
}

void push(OperationStack* stack, Operation* operation)
///Pushes an operation to the stack
///Input : pointer to the stack and the operation to be pushed
///Output : -
{
    stack->operations[stack->lengthOperations++] = copyOperation(operation);
}

Operation* pop(OperationStack* stack)
///Pops an operation from the stack
///Input : pointer to the stack
///Output : the popped operation(add, delete, update)
{
    if(checkEmpty(stack))
        return NULL;
    stack->lengthOperations--;
    return stack->operations[stack->lengthOperations];
}

int checkEmpty(OperationStack* stack)
///Checks if the stack is empty
///Input : pointer to the stack
///Output : 1 if empty, 0 otherwise
{
    return (stack->lengthOperations == 0);
}

int checkFull(OperationStack* stack)
///Checks if the stack is full
///Input : pointer to the stack
///Output : 1 if full, 0 otherwise
{
    return (stack->lengthOperations == 100);
}
