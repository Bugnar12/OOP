#ifndef T2_BUGNAR12_1_ENGINE_H
#define T2_BUGNAR12_1_ENGINE_H

#include <iostream>


class Engine {
protected:
    double basePrice;
public:
    Engine();
    Engine(double basePrice);
    virtual double getPrice() = 0; ///pure virtual method
    virtual std::string toString() = 0; ///pure virtual method
    virtual ~Engine() {}; ///virtual destructor of the base class
};

class ElectricEngine : public Engine {
private:
    int autonomy;
public:
    ElectricEngine();
    ElectricEngine(int autonomy);
    ~ElectricEngine() override {}; ///inherited destructor
    double getPrice() override; ///inherited from Engine
    std::string toString() override; ///inherited from Engine
};

class TurboEngine : public Engine {
public:
    TurboEngine();
    ~TurboEngine() override {}; ///inherited destructor
    double getPrice() override; ///inherited from Engine
    std::string toString() override; ///inherited from Engine
};


#endif //T2_BUGNAR12_1_ENGINE_H
