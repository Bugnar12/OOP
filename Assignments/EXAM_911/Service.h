#ifndef E911_BUGNAR12_SERVICE_H
#define E911_BUGNAR12_SERVICE_H

#include "BacteriumRepo.h"
#include "BiologistsRepo.h"

#include <QAbstractTableModel>

class Service : public QAbstractTableModel{
private:
    BacteriumRepo& bacteriaRepo;
    BiologistsRepo& biologistsRepo;
public:
    Service(BacteriumRepo& bacteriaRepo, BiologistsRepo& biologistsRepo);

    vector<Bacteria>& getBacteria() { return bacteriaRepo.getBacteria();}

    vector<Biologist>& getBiologists() { return biologistsRepo.getBiologists();}

    //vector<Bacteria> getBacteriaByBiologist(string biologistName);

    vector<Bacteria> getBacteriaByBiologistSpecies(string biologistName);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    void addBacteria(string name, string species, int size, vector<string> diseases);

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

};


#endif //E911_BUGNAR12_SERVICE_H
