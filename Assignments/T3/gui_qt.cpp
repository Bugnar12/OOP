#include "gui_qt.h"
#include "ui_GUI_qt.h"


GUI_qt::GUI_qt(Services &s, QWidget *parent) :
        QWidget(parent), ui(new Ui::GUI_qt), serv{ s } {
    ui->setupUi(this);
    this->populate_list();
    this->connect_signals();
}

void GUI_qt::populate_list() {
    this->ui->documents->clear();
    vector<Document> allDocuments = this->serv.get_all();

    ///lambda sorting
    std::sort(allDocuments.begin(), allDocuments.end(), [](const Document &document1, const Document &document2) {
        return document1.get_name() < document2.get_name();
    });

    for(auto &d : allDocuments)
        this->ui->documents->addItem(QString::fromStdString(d.get_name() + " -> " + d.get_keywords()));
}



GUI_qt::~GUI_qt() {
    delete ui;
}

void GUI_qt::search_document() {
    string searched_text = this->ui->input1->text().toStdString();
    this->ui->documents->clear();
    for(auto &document : this->serv.partial_match_serv(searched_text))
    {
        QListWidgetItem *listItem = new QListWidgetItem(QString::fromStdString(document.get_name() + " -> " + document.get_keywords()));
        this->ui->documents->addItem(listItem);
    }
}

void GUI_qt::connect_signals() {
    connect(this->ui->input1, &QLineEdit::textChanged, this, &GUI_qt::search_document);
    connect(this->ui->buttonMatching, &QPushButton::clicked, this, &GUI_qt::best_match_ui);
}

void GUI_qt::best_match_ui() {
    this->ui->output1->clear();
    string text = this->ui->input1->text().toStdString();
    //this->ui->output1->setText(this->serv.perfect_match_serv(text).get_name().c_str());
    this->ui->output1->setFont(QFont("Times", 12, QFont::Bold));
    this->ui->output1->setText(QString::fromStdString(this->serv.perfect_match_serv(text).get_name()));
}
