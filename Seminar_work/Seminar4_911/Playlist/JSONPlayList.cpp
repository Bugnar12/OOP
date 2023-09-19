#include "JSONPlayList.h"
#include <Windows.h>
#include <shellapi.h>
#include <fstream>
#include <string>

JSONPlayList::JSONPlayList(std::string filename): FilePlayList{filename}
{
}

void JSONPlayList::writeToFile() const
{
	std::ofstream f{filename};

	if (!f.is_open())
		throw std::runtime_error{"File could not be opened!"};

	f << "{\"songs\":\n[";

	int size = this->songs.size();
	for (int i = 0; i < size - 1; i++)
	{
		this->writeSongToStream(f, this->songs[i]);
		f << ",";
	}
	this->writeSongToStream(f, this->songs[size - 1]);

	f << "]}";

	f.close();
}

void JSONPlayList::displayPlaylist() const
{
	ShellExecuteA(
		NULL,
		"open",
		"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe",
		filename.c_str(),
		NULL,
		SW_SHOWMAXIMIZED
	);
}

void JSONPlayList::writeSongToStream(std::ostream& os, const Song& s) const
{
	os << "\t{";
	os << "\t\t\"artist\":";
	os << "\"" + s.getArtist() + "\",";
	os << "\t\t\"title\":";
	os << "\"" + s.getTitle() + "\",";
	os << "\t\t\"minutes\":";
	os << "\"" + std::to_string(s.getDuration().getMinutes()) + "\",";
	os << "\t\t\"seconds\":";
	os << "\"" + std::to_string(s.getDuration().getSeconds());
	os << "\t}";
}
