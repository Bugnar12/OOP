#pragma once
#include "PlayList.h"
#include <string>
class FilePlayList :
    public PlayList
{

protected:
    std::string filename;

public:
    FilePlayList(std::string filename);
    virtual void writeToFile() const = 0;
    virtual void displayPlaylist() const = 0;
    virtual ~FilePlayList() {}
};

