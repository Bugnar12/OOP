#pragma once
#include "FilePlayList.h"
#include <iostream>

class JSONPlayList :
    public FilePlayList
{
public:
    JSONPlayList(std::string filename);
    void writeToFile() const override;
    void displayPlaylist() const override;

private:
    void writeSongToStream(std::ostream& os, const Song& s) const;
};

