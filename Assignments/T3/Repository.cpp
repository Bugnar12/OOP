#include "Repository.h"

Repository::Repository() {
    this->load_from_file();
}

void Repository::load_from_file() {
    ifstream file("C:/Users/Praslea/Documents/GitHub/t3-Bugnar12/cmake-build-debug/input.txt");
    Document current_document;
    this->documents.clear();
    while(file >> current_document)
        this->documents.push_back(current_document);

    file.close();
}

vector<Document> Repository::get_all_repo() {
    return this->documents;
}

vector<Document> Repository::partial_match_repo(string word) {
    vector<Document> aux_documents;
    for(auto &document : this->documents)
        if(document.get_name().find(word) != string::npos || document.get_keywords().find(word) != string::npos)
            aux_documents.push_back(document);

    return aux_documents;
}
