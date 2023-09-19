#ifndef E911_BUGNAR12_BACTERIUMREPO_H
#define E911_BUGNAR12_BACTERIUMREPO_H

#include "Bacteria.h"
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


class BacteriumRepo {
private:
    vector<Bacteria> bacteria;
    string filename;
public:
    BacteriumRepo(string filename);
    void readBacteriaFile();

    vector<string> tokenize(string stringToSplit, char delimiter);
    int get_size() { return bacteria.size();}

    vector<Bacteria>& getBacteria() { return bacteria;}
    vector<Bacteria> getBiologist(string biologistName);

    void addBacteria(Bacteria bacteriaToAdd);

    void saveToFile();

};


#endif //E911_BUGNAR12_BACTERIUMREPO_H
