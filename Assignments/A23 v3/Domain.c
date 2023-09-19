#include "Domain.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Estate* createEstate(char* type, char* address, int surface, int price)
///Creates a new estate
///Input : type(str), address(str), surface(int), price(int)
///Output : a new created estate

{
    Estate* e = (Estate*)malloc(sizeof(Estate));
    if (e == NULL)
        return NULL;
    e->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));

    strcpy(e->type, type);
    e->address = (char*)malloc(sizeof(char) * (strlen(address) + 1));
    strcpy(e->address, address);
    e->surface = surface;
    e->price = price;
    return e;
}

char* getAddress(Estate* e)
///getters for address
{
    return e->address;
}

void destroyEstate(Estate* e)
///free memory
{
    free(e->type);
    free(e->address);

    free(e);
}

char* getType(Estate* e)
///getters for type
{
    return e->type;
}

int getSurface(Estate* e)
///getters for surface
{
    return e->surface;
}

int getPrice(Estate* e)
///getters for price
{
    return e->price;
}

void setAddress(Estate* e, char* new_address)
///setters for address
{
    strcpy(e->address, new_address);
}

void setType(Estate* e, char* new_type)
///setters for type
{
    strcpy(e->type, new_type);
}

void setSurface(Estate* e, int new_surface)
///setters for surface
{
    e->surface = new_surface;
}

void setPrice(Estate* e, int new_price)
///setters for price
{
    e->price = new_price;
}


Estate* copyEstate(Estate* e)
///copy an estate
///Input : pointer to an estate
///Output : a new estate
{
    Estate* new_estate = createEstate(getType(e), getAddress(e), getSurface(e), getPrice(e));
    return new_estate;
}


