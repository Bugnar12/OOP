#ifndef T3_BUGNAR12_GUI_QT_H
#define T3_BUGNAR12_GUI_QT_H

#include <QWidget>
#include <QMessageBox>
#include "Services.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GUI_qt; }
QT_END_NAMESPACE

class GUI_qt : public QWidget {
Q_OBJECT

public:
    explicit GUI_qt(Services &s, QWidget *parent = nullptr);

    ~GUI_qt() override;

private:
    Ui::GUI_qt *ui;
    Services &serv;

    void populate_list();
    void connect_signals();
    void search_document();
    void best_match_ui();
};


#endif //T3_BUGNAR12_GUI_QT_H
