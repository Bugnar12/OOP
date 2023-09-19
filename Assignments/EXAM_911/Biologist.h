#ifndef E911_BUGNAR12_BIOLOGIST_H
#define E911_BUGNAR12_BIOLOGIST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Biologist {
private:
    string name;
    vector<string> bacteria_species;
public:
    Biologist(string name, vector<string> bacteria_species) : name{name}, bacteria_species{bacteria_species} {};
    Biologist(const Biologist& biologist) : name{biologist.name}, bacteria_species{biologist.bacteria_species} {};
    string getName() { return name;}
    vector<string> getBacteriaSpecies() { return bacteria_species;}
    void setName(string name) { this->name = name;}
    void setBacteriaSpecies(vector<string> bacteria_species) { this->bacteria_species = bacteria_species;}
    Biologist& operator=(const Biologist& biologist) {
        this->name = biologist.name;
        this->bacteria_species = biologist.bacteria_species;
        return *this;
    }
    bool operator==(const Biologist& biologist) { return this->name == biologist.name;}
};


#endif //E911_BUGNAR12_BIOLOGIST_H
