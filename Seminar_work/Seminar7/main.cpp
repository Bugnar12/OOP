#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <string>
#include "ChatWindow.h"
#include "Subject.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ChatSession cs;
    cs.generate_entries();
    ChatWindow w1(cs);
    ChatWindow w2(cs);
    ChatWindow w3(cs);
    ChatWindow w4(cs);
    cs.registerObserver(&w1);
    cs.registerObserver(&w2);
    cs.registerObserver(&w3);
    cs.registerObserver(&w4);
    w1.show();
    w2.show();
    w3.show();
    w4.show();
    return QApplication::exec();
}
