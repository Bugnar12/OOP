#include "Domain.h"
#include <sstream>


Protein::Protein() : organism{}, name{}, sequence{} {};

Protein::Protein(const std::string &organism, const std::string name, const std::string sequence) {
    this->organism = organism;
    this->name = name;
    this->sequence = sequence;
}

std::string Protein::get_organism() const {
    return this->organism;
}

const std::string Protein::get_name()const {
    return this->name;
}

const std::string Protein::get_sequence() const {
    return this->sequence;
}

std::string Protein::toStr() {
    std::ostringstream result;
    result << this->organism << "|";
    result << this->name << "|";
    result << this->sequence << "|";

    return result.str();
}

Protein &Protein::operator=(const Protein &protein)
{
    if(this == &protein)
        return *this;
    this->organism = protein.organism;
    this->name = protein.name;
    this->sequence = protein.sequence;

    return *this;
}
