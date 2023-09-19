#ifndef SEMINAR7_CHATSESSION_H
#define SEMINAR7_CHATSESSION_H

#include <vector>
#include <algorithm>
#include "UserMessage.h"
#include "Subject.h"
#include "Observer.h"

using namespace std;

class ChatSession : public Subject {
private:
    vector<UserMessage> messages;
public:
    ChatSession() = default;
    void addMessage(string u, string m);
    vector<UserMessage> removeMessage(string u, string m);
    vector<UserMessage> getMessages() const { return messages; };

    void generate_entries();
};


#endif //SEMINAR7_CHATSESSION_H
