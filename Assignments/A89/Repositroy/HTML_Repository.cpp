#include "HTML_Repository.h"

HTML_Repository::HTML_Repository(const std::string &filename) : UserRepo(filename) {
    this->filename = filename;
}

/*The following functions will be used to strip the contents of the HTML file
 * That will be striping ' ', new lines, tabs, .html extensions and other useless extensions and <html>, <head>, <body> tags from the HTML program
 * */

void strip(std::string &string)
{
    while(!string.empty() && (string.back() == ' ' || string.back() == '\t' || string.back() == '\n')) ///string.back() => gets the last character of a string
        string.pop_back(); ///string.pop_back() => deletes the last character of a string
    reverse(string.begin(), string.end());
    while(!string.empty() && (string.back() == ' ' || string.back() == '\t' || string.back() == '\n'))
        string.pop_back();
    reverse(string.begin(), string.end());
}

void html_strip(std::string &string)
{
    strip(string);
    string = string.substr(0, string.size() - 5);
    reverse(string.begin(), string.end());
    string = string.substr(0, string.size() - 4);
    reverse(string.begin(), string.end());
    strip(string);
}

void link_strip(std::string &string)
{
    string = string.substr(0, string.size() - 4);
    reverse(string.begin(), string.end());
    string = string.substr(0, string.size() - 9);
    reverse(string.begin(), string.end());
    int len = (string.size() - 2) / 2;
    string = string.substr(0, string.size() - len - 2);
}

std::vector<Domain> HTML_Repository::read_from_file() {
    std::ifstream file(this->filename);

    if(!file.is_open())
        throw FileError("The file was not opened correctly!");

    std::vector<Domain> watch_list;
    std::string line;

    for(int i = 1; i <= 7; i++)
        std::getline(file, line);

    do {
        std::getline(file, line);
        strip(line);
        if (line != "<tr>")
            break;

        std::string title, genre, yearOfRelease, nrOfLikes, trailer;

        std::getline(file, title);
        html_strip(title);

        std::getline(file, genre);
        html_strip(genre);

        std::getline(file, yearOfRelease);
        html_strip(yearOfRelease);

        std::getline(file, nrOfLikes);
        html_strip(nrOfLikes);

        std::getline(file, trailer);
        html_strip(trailer);
        link_strip(trailer);

        std::getline(file, line);
        watch_list.push_back(Domain(title, genre, stoi(yearOfRelease), stoi(nrOfLikes), trailer));
    } while(true);

    file.close();
    return watch_list;
}


void HTML_Repository::write_to_file() {
    std::ofstream file(this->filename);

    if (!file.is_open())
    {
        throw FileError("The file was not opened correctly!");
    }

    file << "<!DOCTYPE html>\n<html>\n<head>\n<title>WatchList</title>\n</head>\n<body>\n<table border=1>\n";

    for (auto movie : this->watchList)
    {
        file << "<tr>\n" << "<td>" << movie.getTitle() << "</td>\n" <<
                "<td>" << movie.getGenre() << "</td>\n" <<
                "<td>" << movie.getReleaseYear() << "</td>\n" <<
                "<td>" << movie.getNrOfLikes() << "</td>\n" <<
                "<td> <a href=\"" << movie.getTrailer() << "\">" << movie.getTrailer() << "</a></td>\n" << "</tr>\n";
    }

    file << "</table>\n</body>\n</html>";
    file.close();
}

void HTML_Repository::print_file() const {
    std::string result = "start \"\" \"" + this->filename + "\"";
    system(result.c_str());
}
