#ifndef T3_BUGNAR12_DOMAIN_H
#define T3_BUGNAR12_DOMAIN_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Document {
private:
    string name;
    string keywords;
    string content;
public:
    Document() = default;
    Document(string name, string keywords, string content) : name{name}, keywords{keywords}, content{content} {}
    ~Document() = default;
    string get_name() const { return name; }
    string get_keywords() const { return keywords; }
    string get_content() const { return content; }

    string toStr();
    friend istream& operator>>(istream& is, Document& d);
};


#endif //T3_BUGNAR12_DOMAIN_H
