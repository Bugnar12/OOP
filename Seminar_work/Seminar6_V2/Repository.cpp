#include "Repository.h"
#include <string>
#include <fstream>

using namespace std;

Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}

void Repository::addStudent(const Student& s)
{
	this->students.push_back(s);
	this->writeToFile();
}

void Repository::readFromFile()
{
	ifstream file(this->filename);


	Student s;
	while (file >> s)
		this->students.push_back(s);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);

	for (auto s : this->students)
	{
		file << s;
	}

	file.close();
}