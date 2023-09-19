//
// Created by Praslea on 5/11/2023.
//

#include "Car.h"

Car::Car() : bodyStyle(""), engine(nullptr) {}

Car::Car(std::string bodyStyle, Engine *engine) {
    this->bodyStyle = bodyStyle;
    this->engine = engine;
}

double Car::computePrice() {
    double final_price = 0;
    if(this->bodyStyle == "Sedan")
        final_price = 8000 + this->engine->getPrice();
    else if(this->bodyStyle == "Convertible")
        final_price = 9000 + this->engine->getPrice();

    return final_price;
}

std::string Car::toString() {
    return "Body style : " + this->bodyStyle + " - " + this->engine->toString() + " - Total price:" + std::to_string(this->computePrice()) + '\n';
}
