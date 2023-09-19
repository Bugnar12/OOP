#ifndef T1_BUGNAR12_1_REPOSITORY_H
#define T1_BUGNAR12_1_REPOSITORY_H

#include "Domain.h"
#include <vector>
#include <algorithm>

class Repository {
private:
    std::vector<Protein> data;
public:
    std::vector<Protein>& get_data();
    bool remove_repo(Protein protein);
    void add_repo(Protein protein);
};


#endif //T1_BUGNAR12_1_REPOSITORY_H
