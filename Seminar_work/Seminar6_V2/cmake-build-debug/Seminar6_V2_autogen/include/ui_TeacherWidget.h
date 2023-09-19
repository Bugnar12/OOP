/********************************************************************************
** Form generated from reading UI file 'TeacherWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERWIDGET_H
#define UI_TEACHERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherWidgetClass
{
public:
    QTableView *studentsTabelView;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;

    void setupUi(QWidget *TeacherWidgetClass)
    {
        if (TeacherWidgetClass->objectName().isEmpty())
            TeacherWidgetClass->setObjectName("TeacherWidgetClass");
        TeacherWidgetClass->resize(812, 578);
        studentsTabelView = new QTableView(TeacherWidgetClass);
        studentsTabelView->setObjectName("studentsTabelView");
        studentsTabelView->setGeometry(QRect(140, 80, 256, 192));
        pushButton = new QPushButton(TeacherWidgetClass);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 40, 75, 24));
        lineEdit = new QLineEdit(TeacherWidgetClass);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 90, 113, 22));
        lineEdit_2 = new QLineEdit(TeacherWidgetClass);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(10, 130, 113, 22));
        lineEdit_3 = new QLineEdit(TeacherWidgetClass);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(10, 170, 113, 22));
        lineEdit_4 = new QLineEdit(TeacherWidgetClass);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(10, 210, 113, 22));

        retranslateUi(TeacherWidgetClass);

        QMetaObject::connectSlotsByName(TeacherWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *TeacherWidgetClass)
    {
        TeacherWidgetClass->setWindowTitle(QCoreApplication::translate("TeacherWidgetClass", "TeacherWidget", nullptr));
        pushButton->setText(QCoreApplication::translate("TeacherWidgetClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherWidgetClass: public Ui_TeacherWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWIDGET_H
