#ifndef T3_BUGNAR12_REPOSITORY_H
#define T3_BUGNAR12_REPOSITORY_H

#include "Domain.h"

class Repository {
private:
    void load_from_file();
    vector<Document> documents;
public:
    vector<Document> get_all_repo();
    vector<Document> partial_match_repo(string word);
    Repository();
    ~Repository() = default;
};


#endif //T3_BUGNAR12_REPOSITORY_H
