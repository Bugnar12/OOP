#include "Tests/Tests.h"
#include "User Interface/UI.h"

#include <iostream>

using namespace std;

int main()
{
//    Tests tests;
//    tests.run_all_tests();
    std::string answer;
    while(true) {
        cout << "Do you want your data to be stored in an HTML or CSV file ? ";

        getline(cin, answer);
        if (answer != "csv" && answer != "html")
            cout << "Invalid input. Choose csv or html\n";
        else
            break;
    }
        if (answer == "csv")
        {
            ///delete the contents of the exiting code in the watch_list2.csv file
            std::ofstream ofs;
            ofs.open("../files/watch_list2.csv", std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            UserRepo *user_repo = new CSV_Repository("../files/watch_list2.csv");
            Services service1 = Services("../files/Movie_database.txt", user_repo);
            UI ui1 = UI(service1);
            ui1.run();
        }
        else
        {
            ///delete the contents of the exiting code in the watch_list.html file
            std::ofstream ofs;
            ofs.open("../files/watch_list.html", std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            UserRepo *user_repo = new HTML_Repository("../files/watch_list.html");
            Services service2 = Services("../files/Movie_database.txt", user_repo);
            UI ui2 = UI(service2);
            ui2.run();
        }

    return 0;
}