#ifndef T1_BUGNAR12_1_DOMAIN_H
#define T1_BUGNAR12_1_DOMAIN_H

#include <iostream>
#include <string>


class Protein {
private:
    std::string organism;
    std::string name;
    std::string sequence;
public:
    Protein();
    Protein(const std::string &organism, const std::string name, const std::string sequence);

    std::string get_organism() const;
    const std::string get_name() const;
    const std::string get_sequence() const;

    std::string toStr();

    Protein &operator=(const Protein &protein);

};

inline bool operator == (const Protein &protein1, const Protein &protein2)
{
    if(protein1.get_organism() == protein2.get_organism() && protein1.get_name() == protein2.get_name())
        return true;
    return false;
}

#endif //T1_BUGNAR12_1_DOMAIN_H
