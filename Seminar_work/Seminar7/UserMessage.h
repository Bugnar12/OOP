#ifndef SEMINAR7_USERMESSAGE_H
#define SEMINAR7_USERMESSAGE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class UserMessage {
private:
    string message;
    string name;
public:
    UserMessage() = default;
    UserMessage(string name, string message) : name{name}, message{message} {};
    string getMessage() const { return message; };
    string getName() const { return name; };
    string toString() const { return name + ": " + message; };
    inline bool operator==(const UserMessage& um) const { return this->name == um.name && this->message == um.message; };
};


#endif //SEMINAR7_USERMESSAGE_H
