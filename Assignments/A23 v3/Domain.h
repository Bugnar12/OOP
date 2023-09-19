//
// Created by Praslea on 3/13/2023.
//

#ifndef A23_V2_DOMAIN_H
#define A23_V2_DOMAIN_H

#include <stdlib.h>

typedef struct{
    char* type;
    char* address;
    int surface;
    int price;
}Estate;

Estate* createEstate(char* type, char* address, int surface, int price);

char* getAddress(Estate* e);

void destroyEstate(Estate* e);

char* getType(Estate* e);

int getSurface(Estate* e);

int getPrice(Estate* e);

void setAddress(Estate*e, char* new_address);

void setType(Estate* e, char* new_type);

void setSurface(Estate* e, int new_surface);

void setPrice(Estate* e, int new_price);

Estate* copyEstate(Estate* e);


#endif //A23_V2_DOMAIN_H
