#include "Planet.h"
#include "Repository.h"
#include <stdio.h>

///Planet : .h(definition + interface) and .c
///Repository :
///Memory leaks : #include <crtdbg.h> in VS; must search for memory leaks

int main()
{
    Planet p = createPlanet("iasndfk", "KADS8KI", 5);
    printf("%s", getName(&p));
    destroyPlanet(&p);

    Repository* repo = createRepository(5);

    testRepository(repo);
}