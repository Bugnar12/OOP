#ifndef E911_BUGNAR12_WINDOW1_H
#define E911_BUGNAR12_WINDOW1_H

#include <QWidget>

#include "Service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class window1; }
QT_END_NAMESPACE

class window1 : public QWidget {
Q_OBJECT

public:
    window1(QAbstractItemModel* model, Service& service, string biologistName, QWidget *parent = nullptr);

    ~window1() override;

    void connectSignals();

private:
    Ui::window1 *ui;

    string biologistName;
    Service& service;
public slots:
    void populateComboBox(); ///it will populate the Combo Box with the bacterial species that the biologist has studied
    void addBacteria();
    void bacteriaSelected();

};


#endif //E911_BUGNAR12_WINDOW1_H
