// You may need to build the project (run Qt uic code generator) to get "ui_ChatWindow.h" resolved

#include "chatwindow.h"
#include "ui_ChatWindow.h"


ChatWindow::ChatWindow(ChatSession& cs1, QWidget *parent) :
        QWidget(parent), ui(new Ui::ChatWindow), chatSession(cs1) {
    ui->setupUi(this);
    this->populate_list();
    this->connect_signals_and_slots();
}

ChatWindow::~ChatWindow() {
    delete ui;
}

void ChatWindow::update() {
    this->ui->listWidget->clear();
    for (auto &message : this->chatSession.getMessages()) {
        this->ui->listWidget->addItem(QString::fromStdString(message.toString()));
    }
}

void ChatWindow::sendMessage() {
    string user = this->ui->lineEdit->text().toStdString();
    string text = this->ui->lineEdit_2->text().toStdString();
    this->chatSession.addMessage(user, text);
    this->populate_list();
}

void ChatWindow::populate_list() {
    this->ui->listWidget->clear();
    for (auto &message : this->chatSession.getMessages()) {
        this->ui->listWidget->addItem(QString::fromStdString(message.toString()));
    }
}

void ChatWindow::connect_signals_and_slots() {
    QObject::connect(this->ui->pushButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
}