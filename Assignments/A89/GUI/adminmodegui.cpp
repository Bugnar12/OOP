#include "adminmodegui.h"
#include "ui_adminModeGUI.h"
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>


adminModeGUI::adminModeGUI(Services &s, QWidget *parent) :
        QWidget(parent), ui(new Ui::adminModeGUI), serv { s } {
    ui->setupUi(this);
    this->init();
    this->populate_list();
}

adminModeGUI::~adminModeGUI() {
    delete ui;
}

void adminModeGUI::init() {
    auto* layout = new QHBoxLayout { this };
    this->moviesWidget = new QListWidget{};
    this->moviesWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    auto* allMoviesLabel = new QLabel { "Movie database : "};
    auto* leftSide = new QWidget{};
    auto* leftLayout = new QVBoxLayout{leftSide};

    leftLayout->addWidget(allMoviesLabel);
    leftLayout->addWidget(this->moviesWidget);

    auto* formLayout = new QWidget{};
    auto* movieLayout = new QFormLayout{ formLayout };

    this->titleEdit = new QLineEdit{};
    this->genreEdit = new QLineEdit{};
    this->yearOfReleaseEdit = new QLineEdit{};
    this->nrOfLikesEdit = new QLineEdit{};
    this->trailerEdit = new QLineEdit{};
    QFont font("Times", 10, QFont::Bold);
    auto* titleLabel = new QLabel { "&Title : "};
    titleLabel->setBuddy(this->titleEdit);
    this->titleEdit->setFont(font);

    auto* genreLabel = new QLabel { "&Genre : "};
    genreLabel->setBuddy(this->genreEdit);
    this->genreEdit->setFont(font);

    auto* yearOfReleaseLabel = new QLabel { "&Year of release : "};
    yearOfReleaseLabel->setBuddy(this->yearOfReleaseEdit);
    this->yearOfReleaseEdit->setFont(font);

    auto* nrOfLikesLabel = new QLabel { "&Number of likes : "};
    nrOfLikesLabel->setBuddy(this->nrOfLikesEdit);
    this->nrOfLikesEdit->setFont(font);

    auto* trailerLabel = new QLabel { "&Trailer : "};
    trailerLabel->setBuddy(this->trailerEdit);
    this->trailerEdit->setFont(font);

    movieLayout->addRow(titleLabel, this->titleEdit);
    movieLayout->addRow(genreLabel, this->genreEdit);
    movieLayout->addRow(yearOfReleaseLabel, this->yearOfReleaseEdit);
    movieLayout->addRow(nrOfLikesLabel, this->nrOfLikesEdit);
    movieLayout->addRow(trailerLabel, this->trailerEdit);

    QLineEdit::connect(this->titleEdit, &QLineEdit::textChanged, this, &adminModeGUI::handle_hide);
    QLineEdit::connect(this->genreEdit, &QLineEdit::textChanged, this, &adminModeGUI::handle_hide);
    QLineEdit::connect(this->yearOfReleaseEdit, &QLineEdit::textChanged, this, &adminModeGUI::handle_hide);
    QLineEdit::connect(this->nrOfLikesEdit, &QLineEdit::textChanged, this, &adminModeGUI::handle_hide);
    QLineEdit::connect(this->trailerEdit, &QLineEdit::textChanged, this, &adminModeGUI::handle_hide);

    leftLayout->addWidget(formLayout);

    auto* buttonsWidget = new QWidget{};
    auto* gridLayout = new QGridLayout{ buttonsWidget };

    this->addButton = new QPushButton("Add");
    this->addButton->setFont(font);

    this->deleteButton = new QPushButton("Delete");
    this->deleteButton->setFont(font);

    this->updateButton = new QPushButton("Update");
    this->updateButton->setFont(font);

    this->filterButton = new QPushButton("Filter");
    this->filterButton->setFont(font);

    this->validationLabel = new QLabel{ "Invalid input!" };
    this->validationLabel->setFont(font);
    this->validationLabel->hide();

    gridLayout->addWidget(this->addButton, 0, 0);
    gridLayout->addWidget(this->deleteButton, 0, 1);
    gridLayout->addWidget(this->updateButton, 1, 0);
    gridLayout->addWidget(this->filterButton, 1, 1);
    gridLayout->addWidget(this->validationLabel, 2, 0, 1, 2);

    leftLayout->addWidget(buttonsWidget);

    auto* middleSide = new QWidget{};
    auto* middleLayout = new QVBoxLayout{ middleSide };

    this->playListButton = new QPushButton{ "Playlist : " };
    this->playListButton->setFont(font);

    middleLayout->addWidget(this->playListButton);

    auto* rightSide = new QWidget{};
    auto* rightLayout = new QVBoxLayout{rightSide};

    this->playlistWidget = new QListWidget{};
    this->playlistWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    auto* playListLabel = new QLabel { "Playlist : "};

    rightLayout->addWidget(playListLabel);
    rightLayout->addWidget(this->playlistWidget);

    auto* buttonsPlayList = new QWidget{};
    auto* gridPlaylist = new QGridLayout{ buttonsPlayList };

    this->playButton = new QPushButton{ "Play" };
    this->playButton->setFont(font);
    this->nextButton = new QPushButton{ "Next" };
    this->nextButton->setFont(font);

    gridPlaylist->addWidget(this->playButton, 0, 0);
    gridPlaylist->addWidget(this->nextButton, 0, 1);

    rightLayout->addWidget(buttonsPlayList);

    layout->addWidget(leftSide);
    layout->addWidget(middleSide);
    layout->addWidget(rightSide);


}

void adminModeGUI::handle_add() {

}

void adminModeGUI::populate_list() {
    this->moviesWidget->clear();
    for(auto & movie : this->serv.get_admin_repo().getMovies()) {
        this->moviesWidget->addItem(QString::fromStdString(movie.toStr()));
    }
}

void adminModeGUI::handle_delete() {

}

void adminModeGUI::handle_update() {

}

void adminModeGUI::handle_filter() {

}

void adminModeGUI::handle_hide() {
    this->validationLabel->hide();
}
