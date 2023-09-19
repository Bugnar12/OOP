#include "SongValidator.h"

SongException::SongException(const std::vector<std::string>& e):
    errors{e}
{
}

std::vector<std::string> SongException::getErrors() const
{
    return this->errors;
}

void SongValidator::validate(const Song& s)
{
    std::vector<std::string> errors{};

    if (s.getArtist().size() < 2)
        errors.push_back("Artist name is invalid!");
    char firstLetterInTitle = s.getTitle()[0];
    if (firstLetterInTitle != toupper(firstLetterInTitle))
        errors.push_back("Title must start with a capital letter!");

    if (errors.size() > 0)
        throw SongException{errors};
}
