#pragma once

#include <QWidget>
#include <QAbstractItemModel>
#include "studentsModel.h"
#include "ui_TeacherWidget.h"

class TeacherWidget : public QWidget
{
	Q_OBJECT

public:
	TeacherWidget(QAbstractItemModel* s, QWidget *parent = nullptr);
	~TeacherWidget();

private:
	Ui::TeacherWidgetClass ui;

    void addStudent();
    void connect_signals();
};
