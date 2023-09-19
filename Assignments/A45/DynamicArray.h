#ifndef A45_BUGNAR12_DYNAMICARRAY_H
#define A45_BUGNAR12_DYNAMICARRAY_H

#include "Domain.h"
/*
 * Module for creating a DynamicArray using templates. Defining "typename T" means attribuiting to T any type and the vector being still the same;
 */

template <typename T>
class DynamicArray
{
private:
    ///Private fields of the vector
    int capacity;
    int size;
    T *elems;
    ///Resize the array in case this->size == this->capacity
    void resize(int factor = 2);
public:
    ///Constructor for the DynamicArray template vector
    DynamicArray(int capacity = 10);
    ///Copy by reference constructor(already exists a default one but this is more "accurate")
    DynamicArray(const DynamicArray &da);
    ///Destructor
    ~DynamicArray();
    ///Assigning operator
    DynamicArray &operator=(const DynamicArray &da);
    ///Getter for the size of the dynamically allocated array
    int getSize() const;
    T getElement(int index);
    ///CRUD operations related to the dynamic array
    void addDynamic(const T &element); ///add an element
    void removeDynamic(int index); ///remove an element
    void updateDynamic(const T &element, int index); ///update an element

};

///Constructor for the template DA( not empty )
template <typename T>
DynamicArray<T>::DynamicArray(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->elems = new T[capacity];
}

///The copy operator for the template DA
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &da)
{
    this->size = da.size;
    this->capacity = da.capacity;
    this->elems = new T[this->capacity]; ///allocating new dynamic space for the elems
    for(int i = 0; i < this->size; i++)
        this->elems[i] = da.elems[i];
}

///Destructor for the template
template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete [] this->elems;
}

///The assigning operator for the template DA
template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &da)
{
    if (this == &da)
        return *this;

    this->size = da.size;
    this->capacity = da.capacity;

    delete [] this->elems;
    this->elems = new T[this->capacity];
    for(int i = 0 ; i < this->size ; i++)
        this->elems[i] = da.elems[i];

    return *this;
}


///getter for the size template DA
///returns the size of the array
template <typename T>
int DynamicArray<T>::getSize() const {
    return this->size;
}

///getter for a movie object template DA
///returns the element from the DA
template <typename T>
T DynamicArray<T>::getElement(int index) {
    return this->elems[index];
}

///function for adding an element in the DA
///resizing if needed
///input : an index
template <typename T>
void DynamicArray<T>::addDynamic(const T &element) {
    if(this->size == this->capacity)
        this->resize();
    this->elems[this->size] = element;
    this->size++;
}

///function for removing an element from the DA
///input : an index
template <typename T>
void DynamicArray<T>::removeDynamic(int index) {
    for(int i = index; i < this->size - 1; i++)
        this->elems[i] = this->elems[i+1];
    this->size--;
}

///function for updating an element from the DA
///input : an object element and an index
template <typename T>
void DynamicArray<T>::updateDynamic(const T &element, int index) {
    this->elems[index] = element;
}


///function for resizing the DA data structure
///invoked if the size exceeds the capacity of the data structure(since it is not fixed)
template <typename T>
void DynamicArray<T>::resize(int factor) {
    this->capacity = this->capacity * factor;

    auto *new_elems = new T[this->capacity];
    for(int i = 0; i < this->size; i++)
        new_elems[i] = this->elems[i];
    delete [] this->elems;
    this->elems = new_elems;
}


#endif //A45_BUGNAR12_DYNAMICARRAY_H

