//
// Created by Praslea on 6/30/2023.
//

#include "BacteriumRepo.h"
#include <algorithm>

BacteriumRepo::BacteriumRepo(string filename) {
    this->filename = filename;
    this->readBacteriaFile();
}

void BacteriumRepo::readBacteriaFile() {
    ifstream file(this->filename);
    string line;
    while (getline(file, line)) {
        vector<string> tokens = this->tokenize(line, ',');
        string name = tokens[0];
        string species = tokens[1];
        int size = stoi(tokens[2]);
        vector<string> diseases;
        diseases = this->tokenize(tokens[3], ' ');
        Bacteria bacteria(name, species, size, diseases);
        this->bacteria.push_back(bacteria);
    }
    file.close();
}

vector<string> BacteriumRepo::tokenize(string stringToSplit, char delimiter) {
    vector<string> result;
    stringstream ss(stringToSplit);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

void BacteriumRepo::addBacteria(Bacteria bacteriaToAdd) {

    for (auto& bacteria : this->bacteria) {
        if (bacteria == bacteriaToAdd)
            throw std::runtime_error("Bacteria already exists!");

        this->bacteria.push_back(bacteriaToAdd);

        sort(this->bacteria.begin(), this->bacteria.end(), [](Bacteria& b1, Bacteria& b2) { return b1.getName() < b2.getName(); });
    }
    this->saveToFile();

}

void BacteriumRepo::saveToFile() {
    ofstream file(this->filename);
    for (auto& bacteria : this->bacteria) {
        file << bacteria.getName() << "," << bacteria.getSpecies() << "," << bacteria.getSize() << ",";
        for (auto& disease : bacteria.getDiseases())
            file << disease << " ";
        file << endl;
    }
    file.close();

}

//vector<Bacteria> BacteriumRepo::getBiologist(string biologistName) {
//    vector<Bacteria> result;
//    for (auto& bacteria : this->bacteria) {
//        for (auto& biologist : bacteria.getBiologists()) {
//            if (biologist == biologistName)
//                result.push_back(bacteria);
//        }
//    }
//    return result;
//}
