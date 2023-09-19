#ifndef E911_BUGNAR12_BIOLOGISTSREPO_H
#define E911_BUGNAR12_BIOLOGISTSREPO_H

#include "Biologist.h"
#include <string>
#include <sstream>
#include <fstream>

class BiologistsRepo {
private:
    vector<Biologist> biologists;
    string filename;
public:
    BiologistsRepo(string filename);
    void readBiologistFile();

    vector<string> tokenize(string stringToSplit, char delimiter);
    vector<Biologist>& getBiologists() { return biologists;}


    Biologist getBiologistByName(string biologistName);

};


#endif //E911_BUGNAR12_BIOLOGISTSREPO_H
