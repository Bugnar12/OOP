#include "Tests.h"
#include <cassert>

void Tests::test_remove() {
    Repository repository;
    Protein protein1("a", "b", "C");
    Protein protein2("d", "e", "F");
    repository.add_repo(protein1);
    repository.add_repo(protein2);
    assert(repository.get_data().size() == 2);
    repository.remove_repo(protein1); ///now remove the second protein
    assert(repository.get_data().size() == 1);
    assert(repository.get_data()[1].get_name() == "e");
    assert(repository.get_data()[1].get_organism() == "d");
    assert(repository.get_data()[1].get_sequence() == "F");

    ///test the sorting in the service
    Services services;
    services.generate_entries();

}
