#include <QApplication>
#include <QPushButton>
#include "gui_qt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo;
    Services serv(repo);
    GUI_qt gui1{serv};
    gui1.show();
    return a.exec();
}