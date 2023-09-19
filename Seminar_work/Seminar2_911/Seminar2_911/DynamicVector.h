#pragma once
#include "Song.h"

typedef Song TElem;

class DynamicVector
{
private:
	TElem* elems;
	int capacity, size;

    void resize();

public:
	DynamicVector(int cap = 10);
	~DynamicVector(); ///destructor
    DynamicVector(const DynamicVector& v); ///deep copy of the dynamic vector
    DynamicVector& operator=(const DynamicVector &v); ///assignment operator

    void add(TElem);

    int getSize() const;
    int getCapacity();
};

void testDV();

