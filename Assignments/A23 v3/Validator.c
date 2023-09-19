#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool validateType(char* type){
    if(strlen(type) < 1)
        return 0;
    if(strcmp(type, "house") != 0 && strcmp(type, "apartment") != 0 && strcmp(type, "penthouse") != 0)
        return 0;
    return 1;
}

bool validateAddress(char* address){
    if(strlen(address) < 1)
        return 0;
    return 1;
}

bool validateSurface(char* surface){
    if(strlen(surface) < 1)
        return 0;
    for(int i = 0; i < strlen(surface); i++)
        if(!isdigit(surface[i]))
            return 0;
    return 1;

}

bool validatePrice(char* price){
    if(strlen(price) < 1)
        return 0;
    for(int i = 0; i < strlen(price); i++)
        if(!isdigit(price[i]))
            return 0;
    return 1;
}


