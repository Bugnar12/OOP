#ifndef T2_BUGNAR12_1_CAR_H
#define T2_BUGNAR12_1_CAR_H

#include "Engine.h"


class Car {
private:
    std::string bodyStyle;
    Engine* engine;
public:
    Car();
    Car(std::string bodyStyle, Engine* engine);
    double computePrice();
    std::string toString();
};


#endif //T2_BUGNAR12_1_CAR_H
