#pragma once
#include <vector>
#include <string>
#include "Song.h"

class SongException
{
private:
	std::vector<std::string> errors;

public:
	SongException(const std::vector<std::string>& e);
	std::vector<std::string> getErrors() const;
};

class SongValidator
{
public:
	static void validate(const Song& s);
};

