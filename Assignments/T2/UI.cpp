#include "UI.h"

void UI::printMenu() {
    cout << "0.Exit\n";
    cout << "1.Add a new car\n";
    cout << "2.Display all cars ( console )\n";
    cout << "3.Save the cars to a file with lower price and sorted\n";
}

void UI::run() {
    int option;
    this->generateEntries();

    while(true)
    {
        printMenu();
        cout << "Choose an option (integer) :\n";
        cin >> option;
        switch(option){
            case 0:
                return;
            case 1:
                this->addUi();
                break;
            case 2:
                this->printToConsole();
                break;
            case 3:
                this->saveFileLowerPriceUi();
                break;
            default:
                cout << "Invalid option\n";
        }
    }
}

void UI::printToConsole() {
    for(auto car : this->serv.get_cars())
        cout << car->toString() << "\n";
}

void UI::addUi() {
    cout << "Choose body Style ( Sedan / Convertible ) : \n";
    string bodyStyle;
    cin >> bodyStyle;
    if(bodyStyle != "Sedan" && bodyStyle != "Convertible")
    {
        cout << "Invalid body style\n";
    }
    else {
        cout << "Choose engine type ( Electric / Turbo ) : \n";
        string engineType;
        cin >> engineType;
        if (engineType != "Electric" && engineType != "Turbo") {
            cout << "Invalid engine type\n";
        } else {
            if (engineType == "Electric") {
                cout << "Input the autonomy of the elctric car \n";
                int autonomy;
                cin >> autonomy;
                this->serv.addCar(bodyStyle, engineType, autonomy);
                cout << "The price of the electric car you have added is : ";
                cout << this->serv.compute_price_service(bodyStyle, engineType, autonomy) << '\n';
            } else if (engineType == "Turbo") {
                this->serv.addCar(bodyStyle, engineType, 0);
                cout << "The price of the turbo car you have added is :";
                cout << this->serv.compute_price_service(bodyStyle, engineType, 0) << '\n';
            }
        }
    }

}

void UI::generateEntries() {
    this->serv.addCar("Sedan","Electric", 400);
    this->serv.addCar("Convertible","Electric", 800);
    this->serv.addCar("Sedan","Turbo", 0);
    this->serv.addCar("Convertible","Turbo",0);
    this->serv.addCar("Sedan","Electric", 50);
}

UI::UI(Service serv, string filename) {
    this->serv = serv;
    this->filename = filename;
}

void UI::saveFileLowerPriceUi() {
    cout << "Input the price you want to filter by : \n";
    double max_price;
    cin >> max_price;
    std::vector<Car*> cars_aux;
    cars_aux = this->serv.getCarsWithMaxPrice(max_price);
    this->serv.writeToFile(this->filename, cars_aux);
}
