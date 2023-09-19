#include "ChatSession.h"

void ChatSession::addMessage(string u, string m) {
    this->messages.push_back(UserMessage(u, m));
    this->notify();
}

vector<UserMessage> ChatSession::removeMessage(string u, string m) {
    vector<UserMessage> removed;
    for(auto um : this->messages)
        if(um.getName() == u && um.getMessage() == m) {
            removed.push_back(um);
            this->messages.erase(std::find(this->messages.begin(), this->messages.end(), um));
        }
    return removed;
}

void ChatSession::generate_entries() {
    this->addMessage("Mark", "Hello");
    this->addMessage("Bob", "Hi");
    this->addMessage("Mark", "What's up?");
    this->addMessage("Bob", "Nothing much");
    this->addMessage("Mark", "How are you?");
    this->addMessage("Bob", "I'm fine");
}


