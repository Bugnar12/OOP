#include "UI.h"
#include <Windows.h>
#include "RepositoryExceptions.h"
#include "CSVPlayList.h"
#include "JSONPlayList.h"

using namespace std;

//class Base
//{
//public:
//	virtual void fct()
//	{
//		cout << "1";
//	}
//	virtual ~Base() {
//		cout << "Destructor of Base";
//	}
//};
//
//class Derived : public Base
//{
//private:
//	int* x;
//
//public:
//	Derived()
//	{
//		x = new int{ 50 };
//	}
//
//	void fct() override
//	{
//		cout << "2";
//	}
//	~Derived() {
//		delete x;
//		cout << "Destructor of Base";
//	}
//};



int main()
{
	/*Base* obj = new Derived{};
	obj->fct();
	delete obj;*/



	system("color f4");

	try
	{
		Repository repo("Songs.txt");
		FilePlayList* p = nullptr;
		cout << "What type of file would you like to use to store the playlist (CSV/JSON)?";
		string fileType{};
		cin >> fileType;
		if (fileType == "JSON")
			p = new JSONPlayList{ "playlist.json" };
		else
			p = new CSVPlayList{ "playlist.csv" };
		SongValidator val{};
		Service serv(repo, p, val);
		UI ui(serv);
		ui.run();
		delete p;
	}
	catch (FileException&)
	{
		cout << "Repository file could not be opened! The application will terminate." << endl;
		return 1;
	}

	return 0;
}