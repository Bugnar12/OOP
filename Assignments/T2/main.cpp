#include <iostream>
#include "UI.h"

int main()
{
    Service serv;
    UI ui = UI(serv, "output.txt");
    ui.run();
}