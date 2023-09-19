#ifndef A45_BUGNAR12_ADMINMODEGUI_H
#define A45_BUGNAR12_ADMINMODEGUI_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include "Service/Services.h"
#include "Validator/Validators.h"

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class adminModeGUI; }
QT_END_NAMESPACE

class adminModeGUI : public QWidget {
Q_OBJECT

public:
    explicit adminModeGUI(Services &serv, QWidget *parent = nullptr);

    ~adminModeGUI() override;

private:
    Ui::adminModeGUI *ui;
    Services &serv;
    Validators validator;

    ///introduce widgets
    QListWidget* moviesWidget;
    QListWidget* playlistWidget;

    QLineEdit* titleEdit;
    QLineEdit* genreEdit;
    QLineEdit* yearOfReleaseEdit;
    QLineEdit* nrOfLikesEdit;
    QLineEdit* trailerEdit;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* filterButton;
    QPushButton* playListButton;
    QPushButton* playButton;
    QPushButton* nextButton;
    QLabel* validationLabel;

    ///introduce methods
    void populate_list();
    void init();
    void handle_add();
    void handle_delete();
    void handle_update();
    void handle_filter();
    void handle_hide();

    bool validate_input(string title, string genre, string yearOfRelease, string nrOfLikes, string trailer);


};


#endif //A45_BUGNAR12_ADMINMODEGUI_H
