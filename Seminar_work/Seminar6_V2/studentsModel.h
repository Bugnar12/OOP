#pragma once
#include "Repository.h"
#include <QAbstractTableModel>

using namespace std;

class studentsModel :
    public QAbstractTableModel
{
private:
    Repository& repo;

public:
    studentsModel(Repository& r) : repo{ r } {};
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    void addStudent(string name, string group, double seminarGrade, double labGrade);
};

