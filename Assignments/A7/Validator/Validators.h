#ifndef A45_BUGNAR12_VALIDATORS_H
#define A45_BUGNAR12_VALIDATORS_H

#include "Exceptions.h"
#include <string>
#include <vector>
#include <algorithm>

class Validators {
public:
    bool is_number(const std::string &result);
    void input_validator(std::string input, std::vector<std::string> vector1);
};


#endif //A45_BUGNAR12_VALIDATORS_H
