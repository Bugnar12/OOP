//
// Created by Praslea on 5/11/2023.
//

#include "Engine.h"

Engine::Engine() : basePrice(3000) {};

Engine::Engine(double basePrice) {
    this->basePrice = basePrice;
}

ElectricEngine::ElectricEngine() : Engine(3000) {
}

ElectricEngine::ElectricEngine(int autonomy) : Engine(3000), autonomy(autonomy) {}

double ElectricEngine::getPrice() {
    return this->basePrice + (this->autonomy * 0.01);
}

std::string ElectricEngine::toString() {
    return "Engine type : electric, base price : " + std::to_string(this->basePrice) + " and autonomy : " + std::to_string(this->autonomy);
}

TurboEngine::TurboEngine() : Engine() {};

double TurboEngine::getPrice() {
    return this->basePrice + 100;
}

std::string TurboEngine::toString() {
    return "Engine type : turbo with base price : " + std::to_string(this->basePrice);
}
