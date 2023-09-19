#include "Services.h"

Repository Services::get_repo() {
    return this->repo;
}

/// function to remove a protein in service
/// \param protein
/// \return true or false
bool Services::remove_service(Protein protein) {
    if(this->repo.remove_repo(protein) == false)
        return false;
    return true;
}

void Services::generate_entries() {
    this->repo.add_repo(Protein("Human", "Myosin", "AKFLAMMFCS"));
    this->repo.add_repo(Protein("Human", "Keratin", "TCGSGFGGRAFSCIACGPRPGRCC"));
    this->repo.add_repo(Protein("Mouse", "Keratin", "MLWWEEVEDCYEREDVQKK"));
    this->repo.add_repo(Protein("E_coli", "Tufa", "VTILHPIAMDDGLRFAIRE"));
    this->repo.add_repo(Protein("E_coli", "cspE", "MSKIKGNVKWFNESKGFGFITPEDG"));
}

/// function to return all proteins with a given sequence
/// \param sequence
/// \return vector of proteins
std::vector<Protein> Services::proteins_with_sequence_input(std::string sequence) {
    std::vector<Protein> proteins = this->repo.get_data();
    std::vector<Protein> proteins_with_sequence;
    for(auto protein : proteins)
        if(protein.get_sequence().find(sequence) != std::string::npos)
            proteins_with_sequence.push_back(protein);

    ///now sort by name and by sequence size

    std::sort(proteins_with_sequence.begin(), proteins_with_sequence.end(), [](const Protein& protein1, const Protein& protein2) {
        if(protein1.get_name() == protein2.get_name())
            return protein1.get_sequence().size() < protein2.get_sequence().size();
    });

    return proteins_with_sequence;
}
