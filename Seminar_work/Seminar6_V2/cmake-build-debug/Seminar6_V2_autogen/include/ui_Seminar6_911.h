/********************************************************************************
** Form generated from reading UI file 'Seminar6_911.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEMINAR6_911_H
#define UI_SEMINAR6_911_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Seminar6_911Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Seminar6_911Class)
    {
        if (Seminar6_911Class->objectName().isEmpty())
            Seminar6_911Class->setObjectName("Seminar6_911Class");
        Seminar6_911Class->resize(600, 400);
        menuBar = new QMenuBar(Seminar6_911Class);
        menuBar->setObjectName("menuBar");
        Seminar6_911Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Seminar6_911Class);
        mainToolBar->setObjectName("mainToolBar");
        Seminar6_911Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Seminar6_911Class);
        centralWidget->setObjectName("centralWidget");
        Seminar6_911Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Seminar6_911Class);
        statusBar->setObjectName("statusBar");
        Seminar6_911Class->setStatusBar(statusBar);

        retranslateUi(Seminar6_911Class);

        QMetaObject::connectSlotsByName(Seminar6_911Class);
    } // setupUi

    void retranslateUi(QMainWindow *Seminar6_911Class)
    {
        Seminar6_911Class->setWindowTitle(QCoreApplication::translate("Seminar6_911Class", "Seminar6_911", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Seminar6_911Class: public Ui_Seminar6_911Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEMINAR6_911_H
