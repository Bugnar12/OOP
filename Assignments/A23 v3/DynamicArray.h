#ifndef A23_V2_DYNAMICARRAY_H
#define A23_V2_DYNAMICARRAY_H

#include "Domain.h"

typedef Estate* TElement;

typedef struct {
    TElement* estates;
    int size;
    int maxCapacity;
}DynamicArray;

DynamicArray* createDynamicArray(int max_capacity);

void destroyDynamicArray(DynamicArray* array);

int addElementDynamic(DynamicArray* array, TElement element);

int updateElementDynamic(DynamicArray* array, TElement element);

int resize(DynamicArray* array);

int deleteElementDynamic(DynamicArray* array, TElement element);

int getSizeDynamic(DynamicArray* array);

TElement* getAllDynamic(DynamicArray* array);

TElement getByElementDynamic(DynamicArray* array, TElement element);

TElement getByPosition(DynamicArray* array, int index);

int elementExistsDynamic(DynamicArray* array, TElement element);





#endif //A23_V2_DYNAMICARRAY_H
