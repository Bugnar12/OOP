#ifndef T3_BUGNAR12_SERVICES_H
#define T3_BUGNAR12_SERVICES_H

#include "Repository.h"

class Services {
private:
    Repository &repo;
public:
    Services(Repository &r) : repo{r} {};
    vector<Document> get_all();
    vector<Document> partial_match_serv(string word);
    Document perfect_match_serv(string word);
};


#endif //T3_BUGNAR12_SERVICES_H
