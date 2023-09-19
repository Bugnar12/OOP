// You may need to build the project (run Qt uic code generator) to get "ui_window1.h" resolved

#include "window1.h"
#include "ui_window1.h"
#include <QMessageBox>


window1::window1(QAbstractItemModel* model, Service& service, string biologistName, QWidget *parent) :
        QWidget(parent), service{ service }, biologistName { biologistName }, ui(new Ui::window1) {
    ui->setupUi(this);

    ui->tableView->setModel(model);
    this->setWindowTitle(QString::fromStdString(biologistName));

    connectSignals();
    populateComboBox();

}

window1::~window1() {
    delete ui;
}

void window1::populateComboBox() {
    ui->comboBox->clear();
    vector<Biologist> allBiologists = this->service.getBiologists();
    for (auto& biologist : allBiologists) {
        if (biologist.getName() == biologistName) {
            vector<string> studiedSpecies = biologist.getBacteriaSpecies();
            for (auto& species : studiedSpecies) {
                ui->comboBox->addItem(QString::fromStdString(species));
            }
        }
    }
}

void window1::addBacteria() {
    string name = ui->lineEdit->text().toStdString();
    string species = ui->lineEdit_2->text().toStdString();
    int size = ui->lineEdit_3->text().toInt();


    vector<string> diseases;
    string diseasesString = ui->lineEdit_4->text().toStdString();
    string delimiter = " ";
    size_t pos = 0;
    string token;
    while ((pos = diseasesString.find(delimiter)) != string::npos) {
        token = diseasesString.substr(0, pos);
        diseases.push_back(token);
        diseasesString.erase(0, pos + delimiter.length());
    }
    diseases.push_back(diseasesString);
    try {
        this->service.addBacteria(name, species, size, diseases);
    }
    catch (std::runtime_error& error) {
        QMessageBox::critical(this, "Error", QString::fromStdString(error.what()));
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();

}

void window1::connectSignals() {
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &window1::addBacteria);
    QObject::connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &window1::bacteriaSelected);

}

void window1::bacteriaSelected() {
    int selectedRow = ui->tableView->selectionModel()->currentIndex().row();
    if (selectedRow < 0 || selectedRow >= this->service.getBacteria().size()) {
        return;
    }
    QModelIndex position = ui->tableView->selectionModel()->selectedIndexes().at(0);
    QModelIndex revisedPosition = ui->tableView->model()->index(position.row(), 1);

    QVariant data = ui->tableView->model()->data(revisedPosition);
    string species = data.toString().toStdString();

    ui->listWidget->clear();
    vector<Bacteria> allBacteria = this->service.getBacteria();
    for (auto& bacteria : allBacteria) {
        if (bacteria.getSpecies() == species) {
            vector<string> diseases = bacteria.getDiseases();
            for (auto& disease : diseases) {
                ui->listWidget->addItem(QString::fromStdString(disease));
            }
        }
    }

}

