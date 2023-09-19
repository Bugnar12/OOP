#include "Services.h"

vector<Document> Services::get_all() {
    return repo.get_all_repo();
}

vector<Document> Services::partial_match_serv(string word) {
    return repo.partial_match_repo(word);
}

Document Services::perfect_match_serv(string word) {
    vector<Document> partial_match = this->repo.partial_match_repo(word);

    int minPos = -1;
    float maxCharacter = 0;

    for(int i = 0; i < partial_match.size(); i++) ///search in the whole vector for the best matching
    {
        int positionOfSubstring = 0;
        partial_match[i].get_name().find(word, positionOfSubstring);
        int nameLength = partial_match[i].get_name().length(); ///computes the lenght of the names where the word is found
        if(float((nameLength - positionOfSubstring)) / float(nameLength) > maxCharacter)
        {
            maxCharacter = float((nameLength - positionOfSubstring)) / float(nameLength); ///computes the position for the character
            minPos = i;
        }
    }

    return partial_match[minPos];
}