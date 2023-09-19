#ifndef A45_BUGNAR12_DESIGNER_GUI_H
#define A45_BUGNAR12_DESIGNER_GUI_H

#include <QWidget>
#include "Service/Services.h"
#include "Validator/Validators.h"

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class designer_gui; }
QT_END_NAMESPACE

class designer_gui : public QWidget {
Q_OBJECT

public:
    explicit designer_gui(Services &serv, QWidget *parent = nullptr);

    ~designer_gui() override;

private:
    Ui::designer_gui *ui;
    Services &serv;
    Validators validator;

    void populate_list();
    void connect_signals_and_slots();
    void handle_add();
    void handle_remove();
    void handle_update();

    void handle_genre_filter_cascade();
    void remove_movie_from_watchlist();
    int find_gui(vector<Domain> movies, Domain movie);

    bool input_validator(string title, string genre, string yearOfRelease, string nrOfLikes, string trailer);
};


#endif //A45_BUGNAR12_DESIGNER_GUI_H
