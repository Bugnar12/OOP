#include "CSV_Repository.h"

CSV_Repository::CSV_Repository(const std::string &filename) : UserRepo(filename) {
    this->filename = filename;
}

void CSV_Repository::write_to_file() {
    std::ofstream file(this->filename);

    if(!file.is_open())
        throw FileError("The file was not opened correctly(CSV)!");

    for (auto movie : this->watchList)
        file << movie;

    file.close();
}

void CSV_Repository::print_file() const {
    std::string result = "Notepad \"" + this->filename + "\"";
    system(result.c_str());
}
