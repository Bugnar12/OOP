#include <QWidget>
#include <QApplication>
#include <QSortFilterProxyModel>

#include "Service.h"
#include "window1.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BacteriumRepo bacteriaRepo { "bacterias.txt" };
    BiologistsRepo biologistsRepo { "biologists.txt" };
    Service service{ bacteriaRepo, biologistsRepo };

    QSortFilterProxyModel* model = new QSortFilterProxyModel{};

    model->setSourceModel(&service);

    vector<window1*> windows;

    for (auto& biologist : biologistsRepo.getBiologists())
    {
        windows.push_back(new window1{ model, service, biologist.getName() });
    }

    for (auto& window : windows)
        window->show();

    return a.exec();

    return 0;
}