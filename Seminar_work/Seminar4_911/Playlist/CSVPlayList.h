#pragma once
#include "FilePlayList.h"
#include <string>
class CSVPlayList :
    public FilePlayList
{

public:
    CSVPlayList(std::string filename);
    void writeToFile() const override;
    void displayPlaylist() const override;
};

