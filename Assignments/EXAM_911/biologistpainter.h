#ifndef E911_BUGNAR12_BIOLOGISTPAINTER_H
#define E911_BUGNAR12_BIOLOGISTPAINTER_H

#include <QWidget>
#include "Service.h"
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class biologistPainter; }
QT_END_NAMESPACE

class biologistPainter : public QWidget {
Q_OBJECT

public:
    explicit biologistPainter(Service& serv, QWidget *parent = nullptr);

    ~biologistPainter() override;

private:
    Ui::biologistPainter *ui;
    ///paint event : it creates rectangles of the
    void paintEvent(QPaintEvent *event) override;

    Service& service;
    public slots:
};


#endif //E911_BUGNAR12_BIOLOGISTPAINTER_H
