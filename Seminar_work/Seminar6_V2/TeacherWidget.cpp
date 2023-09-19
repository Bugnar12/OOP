#include "TeacherWidget.h"

TeacherWidget::TeacherWidget(QAbstractItemModel* s, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.studentsTabelView->setModel(s);
}

TeacherWidget::~TeacherWidget()
{}

void TeacherWidget::addStudent() {
    string name;
    int group;
    double grade_seminar;
    double grade_lab;

    name = ui.lineEdit->text().toStdString();
    group = ui.lineEdit_2->text().toInt();
    grade_seminar = ui.lineEdit_3->text().toDouble();
    grade_lab = ui.lineEdit_4->text().toDouble();

    this->ui.studentsTabelView->model().
}

void TeacherWidget::connect_signals() {
    connect(ui.pushButton, &QPushButton::clicked, this, &TeacherWidget::addStudent);
}
