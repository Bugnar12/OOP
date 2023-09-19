//
// Created by Praslea on 6/30/2023.
//

#ifndef E911_BUGNAR12_BACTERIA_H
#define E911_BUGNAR12_BACTERIA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bacteria {
private:
    string name;
    string species;
    int size;
    vector<string> diseases;

public:
    Bacteria(string name, string species, int size, vector<string> diseases) : name{name}, species{species}, size{size}, diseases{diseases} {};
    Bacteria(const Bacteria& bacteria) : name{bacteria.name}, species{bacteria.species}, size{bacteria.size}, diseases{bacteria.diseases} {};
    string getName() { return name;}
    string getSpecies() { return species;}
    int getSize() { return size;}
    vector<string> getDiseases() { return diseases;}
    void setName(string name) { this->name = name;}
    void setSpecies(string species) { this->species = species;}
    void setSize(int size) { this->size = size;}
    void setDiseases(vector<string> diseases) { this->diseases = diseases;}
    Bacteria& operator=(const Bacteria& bacteria) {
        this->name = bacteria.name;
        this->species = bacteria.species;
        this->size = bacteria.size;
        this->diseases = bacteria.diseases;
        return *this;
    }
    bool operator==(const Bacteria& bacteria) { return this->name == bacteria.name || this->species == bacteria.species;}

};


#endif //E911_BUGNAR12_BACTERIA_H
