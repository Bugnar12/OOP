#include "Header.h"
#include <iostream>
#include "DynamicVector.h"
#include <crtdbg.h>
#include "Repository.h"
#include "Service.h"
#include "assert.h"


using namespace std;

int main()
{
	/*Song s{"Pink Floyd", "Comfortably numb", 360};
	cout << s.getArtist() << endl;

	Song* songs = new Song[10];*/
//
//	{
//		DynamicVector vect1{};
//
//		DynamicVector vect2{ vect1 };
//
//        DynamicVector vect3{ };
//        vect3 = vect2 = vect1;
//        vect3.operator=(vect2.operator=(vect1)); ///line 21 == line 22
//	}



    testDV();

    Song s1{"A1", "B1", 102};
    Song s2{"A2", "B2", 203};
    Song s3{"A3", "B3", 304};

    Repository repo{};
    repo.addSong(s1);
    repo.addSong(s2);

    Service service{repo};
    assert(service.getSize() == 2);

    repo.addSong(s3);

    assert(service.getSize() == 3);



	_CrtDumpMemoryLeaks();

	return 0;
}