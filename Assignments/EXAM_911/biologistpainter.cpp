// You may need to build the project (run Qt uic code generator) to get "ui_biologistPainter.h" resolved

#include "biologistpainter.h"
#include "ui_biologistPainter.h"


biologistPainter::biologistPainter(Service& serv, QWidget *parent) :
        service {serv},QWidget(parent), ui(new Ui::biologistPainter) {
    ui->setupUi(this);
}

biologistPainter::~biologistPainter() {
    delete ui;
}

void biologistPainter::paintEvent(QPaintEvent *event) {
    ///it will create rectangles for each bacterium of a specific species
    QPainter painter(this);
    int x = 10;
    int y = 10;
    for(auto& bacterium : this->service.getBacteria()) {{
            painter.setPen(Qt::black);
            painter.drawRect(x, y, 100, 100);
            painter.drawText(x + 10, y + 20, QString::fromStdString(bacterium.getName()));

            x = x + 70;
            y = y + 70;

        }

    }

}
