/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName("ChatWindow");
        ChatWindow->resize(440, 332);
        listWidget = new QListWidget(ChatWindow);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 10, 256, 192));
        lineEdit = new QLineEdit(ChatWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(50, 240, 113, 22));
        lineEdit_2 = new QLineEdit(ChatWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(190, 240, 113, 22));
        label = new QLabel(ChatWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 220, 49, 16));
        label_2 = new QLabel(ChatWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, 220, 49, 16));
        pushButton = new QPushButton(ChatWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 270, 181, 24));

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QWidget *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "ChatWindow", nullptr));
        label->setText(QCoreApplication::translate("ChatWindow", "User:", nullptr));
        label_2->setText(QCoreApplication::translate("ChatWindow", "Text:", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatWindow", "Send message :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
