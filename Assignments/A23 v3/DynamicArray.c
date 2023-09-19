#include "DynamicArray.h"
#include "string.h"

DynamicArray* createDynamicArray(int max_capacity)
///
/// \param max_capacity
/// \return a dynamically allocated array
{
    DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
    if(array == NULL)
        return array;

    array->maxCapacity = max_capacity;
    array->size = 0;
    array->estates = (TElement*)malloc(sizeof(TElement) * max_capacity);
    if(array->estates == NULL)
        return NULL;

    return array;
}

void destroyDynamicArray(DynamicArray* array)
///
/// param array : DynamicArray*
/// retrun : frees the dynamic array since it's dynamic allocation
{
    if(array == NULL)
        return;

    int i;
    for( i = 0; i < array->size; i++)
        destroyEstate(array->estates[i]);

    free(array->estates);

    free(array); //!! comentat
    array = NULL;
}

int resize(DynamicArray* array)
/// doubles the size of a dynamic array and copies the elements into it
/// \param array
/// \return 0 on success, -1 if the array was NULL
{
    if(array == NULL)
        return -1;

    array->maxCapacity *= 2;

    ///we must copy everything to the newly allocated vector

    TElement* aux = (TElement*)malloc(array->maxCapacity * sizeof(TElement));
    if(aux == NULL)
        return -1;
    for(int i = 0; i < array->size; i++)
        aux[i] = array->estates[i];

    free(array->estates);
    array->estates = aux;

    return 0;
}

int addElementDynamic(DynamicArray* array, TElement element)
/// \param array, TElement element
/// \return 0 on success, -1 if the array was NULL
{
    if(array == NULL)
        return -1;
    if(array->estates == NULL)
        return -1;
    if(array->size == array->maxCapacity)
        resize(array);
    array->estates[array->size++] = element;
    return 0;

}

int updateElementDynamic(DynamicArray* array, TElement element)
/// \param array, TElement element
/// \return 0 on success, -1 if the element was not found
{
    int elIndex;
    for(elIndex = 0; elIndex < array->size; elIndex++)
        if(strcmp(getAddress(array->estates[elIndex]), getAddress(element)) == 0)
        {
            array->estates[elIndex] = element;
            return 0;
        }
    return -1;
}

int deleteElementDynamic(DynamicArray* array, TElement element)
/// \param array, TElement element
/// \return 0 on success, -1 if the element was not found
{
    int elIndex;
    for(elIndex = 0; elIndex < array->size; elIndex++)
        if(strcmp(getAddress(array->estates[elIndex]), getAddress(element)) == 0)
        {
            destroyEstate(array->estates[elIndex]);
            for(int i = elIndex; i < array->size - 1; i++)
                array->estates[i] = array->estates[i + 1];
            array->size--;
            return 0;
        }
    return -1;
}

int getSizeDynamic(DynamicArray* array)
/// \param array
/// \return the size of the array
{
    if(array == NULL)
        return -1;
    return array->size;
}

TElement* getAllDynamic(DynamicArray* array)
{
    return array->estates;
}

TElement getByElementDynamic(DynamicArray* array, TElement element)
/// \param array, TElement element
/// \return the element if it was found, NULL otherwise
{
    for(int i = 0; i < array->size; i++)
        if(strcmp(getAddress(array->estates[i]), getAddress(element)) == 0)
            return array->estates[i];
    return NULL;
}

TElement getByPosition(DynamicArray* array, int index)
/// \param array, int index
/// \return the element at the given index, NULL if the index is invalid
{
    if(index < 0 || index >= array->size)
        return NULL;
    return array->estates[index];
}

int elementExistsDynamic(DynamicArray* array, TElement element)
/// \param array, TElement element
/// \return 1 if the element exists, 0 otherwise
{
    int elIndex;
    for(elIndex = 0; elIndex < array->size; elIndex++)
        if(strcmp(getAddress(array->estates[elIndex]), getAddress(element)) == 0)
            return 1;
    return 0;
}






