//
// Created by Praslea on 5/6/2023.
//

#include "Validators.h"

bool Validators::is_number(const std::string &result) {
    for (char const &c : result)
    {
        if(std::isdigit(c) == 0)
            return false;
    }
    return true;
}

void Validators::input_validator(std::string input, std::vector<std::string> vector1) {
    std::vector<std::string>::iterator it = find(vector1.begin(), vector1.end(), input);
    if(it == vector1.end())
        throw InputError("Invalid input!");
}
