#include "designer_gui.h"
#include "ui_designer_gui.h"
#include <QMessageBox>
#include <QFormLayout>
#include <QComboBox>
#include <QDialogButtonBox>

designer_gui::designer_gui(Services &s, QWidget *parent) :
        QWidget(parent), ui(new Ui::designer_gui), serv(s) {
    ui->setupUi(this);
    this->ui->watchListWidget->clear();
    this->populate_list();
    this->connect_signals_and_slots();
}

designer_gui::~designer_gui() {
    delete ui;
}

void designer_gui::populate_list() {
    this->ui->movieListWidget->clear();
    for (auto &movie : this->serv.get_admin_repo().getMovies()) {
        this->ui->movieListWidget->addItem(QString::fromStdString(movie.toStr()));
    }
}

void designer_gui::connect_signals_and_slots() {
    QObject::connect(this->ui->addButton, &QPushButton::clicked, this, &designer_gui::handle_add);
    QObject::connect(this->ui->deleteButton, &QPushButton::clicked, this, &designer_gui::handle_remove);
    QObject::connect(this->ui->updateButton, &QPushButton::clicked, this, &designer_gui::handle_update);
    QObject::connect(this->ui->playButton, &QPushButton::clicked, this, &designer_gui::handle_genre_filter_cascade);
    QObject::connect(this->ui->removePlaylist, &QPushButton::clicked, this, &designer_gui::remove_movie_from_watchlist);
}

void designer_gui::handle_add() {
    string title = this->ui->titleLineEdit->text().toStdString();
    string genre = this->ui->genreLineEdit->text().toStdString();
    string year = this->ui->releaseYearLineEdit->text().toStdString();
    string likes = this->ui->nrOfLikesLineEdit->text().toStdString();
    string trailer = this->ui->trailerLineEdit->text().toStdString();

    if(this->input_validator(title, genre, year, likes, trailer))
    {
        Domain movie1 = Domain(title, genre, stoi(year), stoi(likes), trailer);

        try{
            this->serv.add_admin_repo(movie1);
            this->populate_list();
        }catch(OperationError &oe)
        {
            QMessageBox::critical(this, "Movie already exists", QString::fromStdString(oe.what()));
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
    }

}

void designer_gui::handle_remove() {
    string trailer = this->ui->trailerLineEdit->text().toStdString();
    if(!(trailer == ""))
    {
        Domain movie1 = Domain("", "", 2023, 0, trailer);
        try {
            this->serv.remove_admin_repo(movie1);
            this->populate_list();
        }catch(OperationError &oe)
        {
            QMessageBox::critical(this, "Movie does not exist", QString::fromStdString(oe.what()));
        }
    }
    else {
        QMessageBox::critical(this, "Error", "Invalid input!");
    }
}

void designer_gui::handle_update() {
    string title = this->ui->titleLineEdit->text().toStdString();
    string genre = this->ui->genreLineEdit->text().toStdString();
    string year = this->ui->releaseYearLineEdit->text().toStdString();
    string likes = this->ui->nrOfLikesLineEdit->text().toStdString();
    string trailer = this->ui->trailerLineEdit->text().toStdString();

    if(this->input_validator(title, genre, year, likes, trailer))
    {
        Domain movie1 = Domain("", "", 2023, 0, trailer);
        Domain movie2 = Domain(title, genre, stoi(year), stoi(likes), trailer);

        try{
            this->serv.update_admin_repo(movie1, movie2);
            this->populate_list();
        }catch(OperationError &oe)
        {
            QMessageBox::critical(this, "Movie could not be updated!", QString::fromStdString(oe.what()));
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
    }
}

bool designer_gui::input_validator(string title, string genre, string yearOfRelease, string nrOfLikes, string trailer) {
    return (title != "") && (genre != "") && (this->validator.is_number(yearOfRelease)) &&
            (stoi(yearOfRelease) >= 1850) && (stoi(yearOfRelease) <= 2023) && (this->validator.is_number(nrOfLikes));
}

int designer_gui::find_gui(vector<Domain> movies, Domain movie) {
    for(int i = 0; i < movies.size(); i++)
    {
        if(movies[i] == movie)
        {
            return i;
        }
    }
    return -1;
}


void designer_gui::handle_genre_filter_cascade() {
    ///the user will input a genre(can be also "") and when the button "Play movie" is pressed, the movie according to the genre will be played
    string genre = this->ui->genrePlayListButton->text().toStdString();
    int viewer_count = 0;
    int index = 0;

    while (index < this->serv.get_admin_repo().get_size_of_repo()) {
        int position = find_gui(this->serv.get_user_repo()->get_watch_list(), this->serv.get_admin_repo().getMovies()[index]);

        if ((position == -1 || (this->serv.get_user_repo()->get_watch_list().size() > 0)) && this->serv.get_admin_repo().getMovies()[index].getGenre() == genre || genre.empty()) {
            ///this->serv.get_admin_repo().getMovies()[index].play();

            QDialog *dialog = new QDialog(this);
            dialog->setWindowTitle(QString::fromStdString(this->serv.get_admin_repo().getMovies()[index].getTitle()));
            QFormLayout form(dialog);
            QComboBox *comboBox = new QComboBox(dialog);
            comboBox->addItem("Yes");
            comboBox->addItem("No");
            form.addRow(new QLabel("Do you want to add this movie to the playlist?"));
            form.addRow(comboBox);
            QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
            form.addRow(&buttonBox);
            QObject::connect(&buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
            QObject::connect(&buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));


            if (dialog->exec() == QDialog::Accepted) {
                if (comboBox->currentText() == "Yes") {
                    this->ui->watchListWidget->addItem(QString::fromStdString(this->serv.get_admin_repo().getMovies()[index].toStr()));
                    viewer_count++;
                    if(this->serv.get_user_repo()->get_watch_list().size() < this->serv.nr_movies_with_a_genre(genre))
                        this->serv.add_user(this->serv.get_admin_repo().getMovies()[index]);
                } else if(comboBox->currentText() == "No") {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        index++;
        if(index == this->serv.get_admin_repo().get_size_of_repo())
        {
            index = 0;
            if(viewer_count == 0) {
                QMessageBox::critical(this, "Error", "No movies with this genre!");
                break;
            }
            viewer_count = 0;
        }
    }

}

void designer_gui::remove_movie_from_watchlist() {

    ///in the line edit I have only the trailer of the movie
    string trailer = this->ui->trailerRemove2->text().toStdString();
    try {
        Domain movie1 = Domain("", "", 2023, 0, trailer);
        ///get the index of the movie selected to be deleted
        int position = find_gui(this->serv.get_user_repo()->get_watch_list(), movie1);
        QListWidgetItem *itemToRemove = this->ui->watchListWidget->takeItem(position);
        delete itemToRemove;

        this->serv.delete_user(movie1);
        ///remove an element from the watch list

        QDialog *dialog = new QDialog(this);
        QFormLayout form(dialog);
        QComboBox *comboBox = new QComboBox(dialog);
        comboBox->addItem("Yes");
        comboBox->addItem("No");
        form.addRow(new QLabel("Did you like the movie watched"));
        form.addRow(comboBox);
        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
        form.addRow(&buttonBox);
        QObject::connect(&buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
        QObject::connect(&buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

        if (dialog->exec() == QDialog::Accepted) {
            if (comboBox->currentText() == "Yes") {
                int position = find_gui(this->serv.get_admin_repo().getMovies(), movie1);
                string title = this->serv.get_admin_repo().getMovies()[position].getTitle();
                string genre = this->serv.get_admin_repo().getMovies()[position].getGenre();
                int year = this->serv.get_admin_repo().getMovies()[position].getReleaseYear();
                int likes = this->serv.get_admin_repo().getMovies()[position].getNrOfLikes() + 1;
                this->serv.update_admin_repo(Domain("a", "a", 2023, 0, trailer),
                                             Domain(title, genre, year, likes, trailer));
                this->ui->movieListWidget->clear();
                for (auto movie: this->serv.get_admin_repo().getMovies()) {
                    this->ui->movieListWidget->addItem(QString::fromStdString(movie.toStr()));
                }
            }
        }
    }catch(OperationError &ioe)
    {
        QMessageBox::critical(this, "Error", QString::fromStdString(ioe.what()));
    }
}
