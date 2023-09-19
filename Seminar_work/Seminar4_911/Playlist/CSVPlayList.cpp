#include "CSVPlayList.h"
#include <fstream>
#include <Windows.h>
#include <shellapi.h>

using namespace std;

CSVPlayList::CSVPlayList(std::string filename) 
	: FilePlayList {filename}
{}

void CSVPlayList::writeToFile() const
{
	ofstream fout(filename);

	fout << "Artist,Title,Duration,Source" << endl;

	for (const auto &s : this->songs) {
		fout << s << endl;
	}

	fout.close();
}

void CSVPlayList::displayPlaylist() const
{
	ShellExecuteA(
		NULL,
		"open",
		"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE",
		filename.c_str(),
		NULL,
		SW_SHOWMAXIMIZED
	);
}
