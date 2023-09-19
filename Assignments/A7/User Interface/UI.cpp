#include "UI.h"
#include <iostream>
#include <ctime>
#include <limits>



using namespace std;

///constructor
UI::UI(Services service) : service{service} {}

/*
 * function to input a release year
 * firstly check if the input contains any letters, then if the year is actually valid(>1850, <2023)
 * */
int UI::input_releaseYear() {
    std::string releaseYear_str;
    int releaseYear_int;
    while(true)
    {
        cout << "Please input the release year of the movie";
        getline(cin, releaseYear_str);

        try{
            if(!this->validator.is_number(releaseYear_str))
                throw InputError("Invalid input. The year should be a number");
            else {
                releaseYear_int = stoi(releaseYear_str);
                time_t t = time(nullptr);
                tm *timePtr = localtime(&t);
                if (releaseYear_int < 1850 || releaseYear_int > 1900 + timePtr->tm_year)
                    throw InputError("The time period of the year is not valid!");
                else
                    break;
            }
        } catch(InputError &ie)
        {
            cout << ie.what() << endl;
        }
    }
    return releaseYear_int;
}


/*
 * Function to input the number of likes
 * If the nr. of likes is negative or if it contains letters => throw an error
 * */
int UI::input_nrOfLikes() {
    string nrOfLikes_str;
    int nrOfLikes_int;
    while(true)
    {
        cout << "Please input the number of likes of the movie";
        getline(cin, nrOfLikes_str);
        try{
            if(!this->validator.is_number(nrOfLikes_str))
            {
                throw InputError("The nr. of likes should be a number");
            }
            else {
                nrOfLikes_int = stoi(nrOfLikes_str);
                if (nrOfLikes_int < 0)
                    throw InputError("The nr. of likes should not be negative!");
                else
                    break;
            }
        } catch(InputError &ie)
        {
            cout << ie.what() << endl;
        }
    }
    return nrOfLikes_int;
}


///short function that reads a genre from the user
std::string UI::genre_input() {
    string genre;
    cout << "Please input the desired genre: ";
    getline(cin, genre);

    return genre;
}

///short function that is meant to be used for reading a response from the user ( Yes/No )
///it checks if the response is valid and returns it
std::string UI::response_input() {
    string response;
    std::vector<std::string> resp_vect = {"Yes", "No"};
    while(std::find(resp_vect.begin(), resp_vect.end(), response) == resp_vect.end())
    {
        cout << ">>";
        getline(cin, response);

        try {
            this->validator.input_validator(response, resp_vect);
        }
        catch(InputError &ie) {
            cout << ie.what() << '\n';
        }
    }
    return response;
}

///function that searches in the vector v the movie and returns its position
///returns -1 if the movie is not found or the position
int UI::find(std::vector<Domain> v, Domain movie)
{
    for(int i = 0 ; i < v.size(); i++)
        if(v[i] == movie)
            return i;
    return -1;
}
///some printings for the menu
void UI::printMenu() {
    std::cout << '\n';
    cout << "1.Administrator mode\n";
    cout << "2.User mode\n";
    cout << "3.Exit application \n";
}

///some printings for the admin mode
void UI::printAdminRepo() {
    std::cout << '\n';
    cout << "1.Add a movie to the list \n";
    cout << "2.Remove a movie from the list \n";
    cout << "3.Update a movie from the list \n";
    cout << "4.Display all movies \n";
    cout << "5.Exit application \n";
}

///some printings for the user mode
void UI::printUserRepo() {
    cout << '\n';
    cout << "1.Check out the movies from the database ! \n";
    cout << "2.Delete an already watched movie from the watch list! \n";
    cout << "3.See your current watch list! \n";
    cout << "4.Exit! \n";
}

///function that adds a movie to the admin repository using the UI
///it also checks the validity of an year an of the number of likes(the should be only integer numbers)
///adds a movie to the repo if it is valid, prints an error message if not
void UI::addMovieAdminUI() {
    cout << "Please enter the title :\n";
    std::string title;
    getline(cin, title);

    cout << "Please enter the genre :\n";
    std::string genre;
    getline(cin, genre);

    int yearOfRelease = input_releaseYear();
    int numberOfLikes = input_nrOfLikes();

    cout << "Please enter the trailer : \n";
    string trailer;

    getline(cin, trailer);
    try
    {
        this->service.add_admin_repo(Domain(title, genre, yearOfRelease, numberOfLikes, trailer));
        cout << "Movie added successfully! \n";
    }
    catch (OperationError &ioe)
    {
        cout << ioe.what() << '\n';
    }
}
///function that removes a movie from the admin repository using the UI ; identifier : the trailer
///prints a message of success if the movie was removed, an another message otherwise
void UI::removeMovieAdminUI() {
    cout << "Please enter the url of the trailer you want to remove : \n";
    std::string trailer;
    getline(cin, trailer);

    Domain movie = Domain("p", "p", 0, 0, trailer);

    try{
        this->service.remove_admin_repo(movie);
        cout << "Movie removed successfully! \n";
    }
    catch (OperationError &ioe)
    {
        cout << ioe.what() << '\n';
    }
}


///updates a movie from the admin_repo
///also does the validation that is performed at add too
///prints a nice message in case of success, a dissapointing one otherwise
void UI::updateMovieAdminUI() {
    cout << "Please enter the title you want to update: \n";
    std::string title;
    getline(cin, title);

    cout << "Please enter the genre you want to update: \n";
    std::string genre;
    getline(cin, genre);

    int yearOfRelease;
    int numberOfLikes;

    try{
        yearOfRelease = input_releaseYear();
        numberOfLikes = input_nrOfLikes();
    } catch (InputError &ie) {
        cout << ie.what() << '\n';
    }

    cout << "Please enter the trailer you want to update: \n";
    std::string trailer;
    getline(cin, trailer);

    Domain movie = Domain(title, genre, yearOfRelease, numberOfLikes, trailer);
    Domain movie1 = Domain("", "", 0, 0, trailer);

    try{
        this->service.update_admin_repo(movie1, movie);
        cout << "Movie updated successfully! \n";
    }
    catch (OperationError &ioe)
    {
        cout << ioe.what() << '\n';
    }
}

///function that displays all the movies from the admin repository
void UI::displayMoviesAdmin()
{
    for(int i = 0; i < this->service.get_admin_repo().get_size_of_repo(); i++)
        cout << i + 1 << "." << this->service.get_admin_repo().getMovies()[i].toStr() << endl ;
}

///UI part for the user choosing a specific genre
void UI::get_user_genre() {
    string genre = genre_input();

    int index = 0;
    int viewer_count = 0;

    while (index < this->service.get_admin_repo().get_size_of_repo())
    {
        int pos = find(this->service.get_user_repo()->get_watch_list(), this->service.get_admin_repo().getMovies()[index]);
            if(pos == -1 && this->service.get_admin_repo().getMovies()[index].getGenre() == genre || genre.empty())
            {
                viewer_count = viewer_count + 1;

                cout << this->service.get_admin_repo().getMovies()[index].toStr();
                cout << endl;

                this->service.get_admin_repo().getMovies()[index].play();

                cout << "Did you enjoy the trailer ? (Yes/No) :\n";
                string user_response1 = response_input();
                if (user_response1 == "Yes") {
                    this->service.add_user(this->service.get_admin_repo().getMovies()[index]);
                    cout << "The movie was added to the playlist\n";
                }
                cout << "Do you wish to continue ? (Yes/No) : \n";
                string user_response2 = response_input();
                if (user_response2 == "No")
                    break;
        }
        index++;
        if(index == this->service.get_admin_repo().get_size_of_repo())
        {
            index = 0;
            if(viewer_count == 0)
            {
                cout << "No movies in the genre selected !\n";
                break;
            }
            viewer_count = 0;
        }
    }
}

//display the watch list of the user
void UI::displayWatchList() {
    ///check if the watch list is not empty firstly
    if(this->service.get_user_repo()->get_watch_list().size() == 0) {
        cout << "No movies in your watch list ! \n";
    }

    for(int index = 0; index < this->service.get_user_repo()->get_watch_list().size(); index++)
        cout << index + 1 << "." << this->service.get_user_repo()->get_watch_list()[index].toStr() << '\n';

    this->service.get_user_repo()->print_file();
}

///function for removing a movie from the user repository
void UI::remove_movie_user() {
    string trailer;
    cout << "Please enter the link of the trailer you want to remove: ";
    getline(cin, trailer);

    try {
        this->service.delete_user(Domain("", "", 0, 0, trailer));
        cout << "The desired movie was deleted!\n";
        cout << "Did you enjoy the removed movie ? (Yes/No) :\n";
        string reply = response_input();
        if (reply == "Yes") {
            int pos = find(this->service.get_admin_repo().getMovies(), Domain("a", "a", 0, 0, trailer));
            string title = this->service.get_admin_repo().getMovies()[pos].getTitle();
            string genre = this->service.get_admin_repo().getMovies()[pos].getGenre();
            int yearOfRelease = this->service.get_admin_repo().getMovies()[pos].getReleaseYear();
            int nrOfLikes = this->service.get_admin_repo().getMovies()[pos].getNrOfLikes() + 1;

            this->service.update_admin_repo(Domain("a", "a", 0, 0, trailer),
                                            Domain(title, genre, yearOfRelease, nrOfLikes, trailer));

            cout << "You just gave a like to the movie !\n";
        }
    }
    catch (OperationError &ioe) {
        cout << ioe.what() << '\n';
    }
}

///function that runs the entire application, contains some infinite whiles
void UI::run() {
    while (true)
    {
        UI::printMenu();
        int command{0};
        cout << "Choose one of the following options (1, 2, 3) :\n";
        cin >> command;

        if(cin.fail()){ ///checks if the input is not an integer
            cin.clear(); ///cleans the error flag on cin ( so that future operations work accordingly )
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); ///it basically skips to the new line ( again in order to avoid problems in the buffer )
            cout << "Invalid input";
            continue;
        }

        if (command == 0)
            break;

        if (command == 1) ///admin mode has been chosen
        {
            cout << "Welcome to the admin mode! Choose one of the following options : \n";
            UI::printAdminRepo();
            int optionAdmin{0};
            cin >> optionAdmin;
            cin.ignore();
            if(optionAdmin == 0)
                break;
            switch (optionAdmin)
            {
                case 1:
                    this->addMovieAdminUI();
                    break;
                case 2:
                    this->removeMovieAdminUI();
                    break;
                case 3:
                    this->updateMovieAdminUI();
                    break;
                case 4:
                    this->displayMoviesAdmin();
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid option! \n";
                    break;
            }
        }

        if(command == 2)
        {
            cout << "Welcome to the user mode! Choose one of the following options : \n";
            UI::printUserRepo();
            int optionUser{0};
            cin >> optionUser;
            cin.ignore();
            if(optionUser == 0)
                break;
            switch(optionUser)
            {
                case 1:
                    this->get_user_genre();
                    break;
                case 2:
                    this->remove_movie_user();
                    break;
                case 3:
                    this->displayWatchList();
                    break;
                case 4:
                    return;
            }
        }
        if(command == 3)
        {
            return;
        }

    }
}
