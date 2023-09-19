#include "Domain.h"

string Document::toStr() {
    return this->name + "|" + this->keywords + "|" + this->content;
}

vector<string> tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);
    return result;
}

istream &operator>>(istream &is, Document &d) {
    string line;
    getline(is, line);
    vector<string> tokens = tokenize(line, '|');
    if (tokens.size() != 3)
        return is;
    d.name = tokens[0];
    d.keywords = tokens[1];
    d.content = tokens[2];
    return is;
}
