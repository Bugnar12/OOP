
#include "UI.h"
#include <limits>

void UI::printings() {
    cout << "Menu : \n";
    cout << "0.Exit\n";
    cout << "1.Remove a protein\n";
    cout << "2.Display proteins\n";
    cout << "3.Input a name to show you a protein\n";
}

void UI::run() {
    this->service.generate_entries();
    while(true)
    {
        UI::printings();
        int command{0};
        cin >> command;
        if(cin.fail()){ ///checks if the input is not an integer
            cin.clear(); ///cleans the error flag on cin ( so that future operations work accordingly )
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); ///it basically skips to the new line ( again in order to avoid problems in the buffer )
            cout << "Invalid input";
            continue;
        }
        cin.ignore();
        if(command == 0)
            break;
        switch(command)
        {
            case 1:
                this->remove_ui();
                break;
            case 2:
                this->display_ui();
                break;
            case 3:
                this->sequence_find_ui();
                break;
            default:
                cout << "Invalid command!\n";
                break;
        }
    }
}


void UI::remove_ui() {
    ///function in UI to remove by organism and by name
    string organism;
    string name;
    cout << "Organism: ";
    getline(cin, organism);
    cout << "Name: ";
    getline(cin, name);
    Protein protein{organism, name, ""};
    if(this->service.remove_service(protein))
        cout << "Protein removed with success!\n";
    else
        cout << "Protein not removed!\n";
}

void UI::display_ui() {
    for(int i = 0; i < this->service.get_repo().get_data().size(); i++)
        cout << i + 1 << "." << this->service.get_repo().get_data()[i].toStr() << endl;
}

void UI::sequence_find_ui() {
    string sequence;
    cout << "Sequence: ";
    getline(cin, sequence);
    std::vector<Protein> proteins = this->service.proteins_with_sequence_input(sequence);
    for(auto protein : proteins)
        cout << protein.toStr() << endl;
}
