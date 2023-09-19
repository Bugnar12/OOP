#include "BiologistsRepo.h"

BiologistsRepo::BiologistsRepo(string filename) {
    this->filename = filename;
    this->readBiologistFile();
}

void BiologistsRepo::readBiologistFile() {
    ifstream file(this->filename);
    string line;
    while (getline(file, line)) {
        vector<string> tokens = tokenize(line, ',');
        ///the bacterial species should be a vector
        string name = tokens[0];
        vector<string> bacterialSpecies;
        ///provide a method that takes the whole vector as parameter and splits it but something like bacteriaSpecies = split(tokens[1], ';')
        bacterialSpecies = tokenize(tokens[1], ' ');
        Biologist b1(name, bacterialSpecies);
        this->biologists.push_back(b1);
    }
    file.close();

}

vector<string> BiologistsRepo::tokenize(string stringToSplit, char delimiter) {
    vector<string> result;
    stringstream ss(stringToSplit);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

Biologist BiologistsRepo::getBiologistByName(string biologistName) {
    for (auto& biologist : this->biologists) {
        if (biologist.getName() == biologistName)
            return biologist;
    }
}
