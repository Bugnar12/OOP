#ifndef T1_BUGNAR12_1_SERVICES_H
#define T1_BUGNAR12_1_SERVICES_H

#include "Repository.h"

class Services {
private:
    Repository repo;
public:
    Repository get_repo();
    bool remove_service(Protein protein);
    void generate_entries();

    std::vector<Protein> proteins_with_sequence_input(std::string sequence);
};


#endif //T1_BUGNAR12_1_SERVICES_H
