#include "Tests/Tests.h"
#include "User Interface/UI.h"
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QtWidgets/QHBoxLayout>
#include <iostream>
#include <QFormLayout>
#include "GUI/adminmodegui.h"
#include "GUI_2/designer_gui.h"

using namespace std;



int main(int argc, char *argv[])
{

//    QApplication a{argc, argv};
//    a.setQuitOnLastWindowClosed(false);
//    UserRepo *user_repo = new CSV_Repository("../files/watch_list2.csv");
//    Services service = Services("../files/Movie_database.txt", user_repo);
//
//    adminModeGUI adminGUI(service);
//    adminGUI.show();
//
//    return a.exec();


    QApplication a{argc, argv};
    a.setQuitOnLastWindowClosed(false);

    ///clear the contents of the watch_list2.csv file
    std::ofstream ofs;
    ofs.open("../files/watch_list2.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    UserRepo *user_repo = new CSV_Repository("../files/watch_list2.csv");
    Services service2 = Services("../files/Movie_database.txt", user_repo);

    designer_gui gui2(service2);
    gui2.show();

    return a.exec();

//    std::string answer;
//    while(true) {
//        cout << "Do you want your data to be stored in an HTML or CSV file ? ";
//
//        getline(cin, answer);
//        if (answer != "csv" && answer != "html")
//            cout << "Invalid input. Choose csv or html\n";
//        else
//            break;
//    }
//        if (answer == "csv")
//        {
//            ///delete the contents of the exiting code in the watch_list2.csv file
//            std::ofstream ofs;
//            ofs.open("../files/watch_list2.csv", std::ofstream::out | std::ofstream::trunc);
//            ofs.close();
//            UserRepo *user_repo = new CSV_Repository("../files/watch_list2.csv");
//            Services service1 = Services("../files/Movie_database.txt", user_repo);
//            UI ui1 = UI(service1);
//            ui1.run();
//        }
//        else
//        {
//            ///delete the contents of the exiting code in the watch_list.html file
//            std::ofstream ofs;
//            ofs.open("../files/watch_list.html", std::ofstream::out | std::ofstream::trunc);
//            ofs.close();
//            UserRepo *user_repo = new HTML_Repository("../files/watch_list.html");
//            Services service2 = Services("../files/Movie_database.txt", user_repo);
//            UI ui2 = UI(service2);
//            ui2.run();
//        }
//
//    return 0;
}