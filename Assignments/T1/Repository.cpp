#include "Repository.h"

std::vector<Protein>& Repository::get_data()
{
    return this->data;
}

/// Function to remove a protein in repo using stl
/// \param protein
/// \return true or false
bool Repository::remove_repo(Protein protein) {
    auto it = find(this->data.begin(), this->data.end(), protein);
    if(it == this->data.end())
        return false;
    this->data.erase(it);
    return true;
}

void Repository::add_repo(Protein protein) {
    this->data.push_back(protein);
}