#include "Service.h"

Service::Service(BacteriumRepo &bacteriaRepo, BiologistsRepo &biologistsRepo) : bacteriaRepo{ bacteriaRepo }, biologistsRepo{ biologistsRepo }
{
}

int Service::rowCount(const QModelIndex &parent) const {
    ///bacterias
    return bacteriaRepo.getBacteria().size();
}

int Service::columnCount(const QModelIndex &parent) const {
    return 4; ///the last column is a vector
}


QVariant Service::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();

    Bacteria& requiredBacteria = this->bacteriaRepo.getBacteria()[row];


    if (role == Qt::EditRole || role == Qt::DisplayRole)
    {
        switch (column)
        {
            case 0:
                return QString::fromStdString(requiredBacteria.getName());

            case 1:
                return QString::fromStdString(requiredBacteria.getSpecies());

            case 2:
                ///get size is an int
                return QString::number(requiredBacteria.getSize());

            ///case 3 -> vector
            case 3:
                {
                    string result = "";
                    for (auto& bacterias : requiredBacteria.getDiseases())
                        result += bacterias + " ";
                    return QString::fromStdString(result);
                }

        }
    }
    return QVariant();
}

QVariant Service::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch (section)
        {
            case 0:
                return "Name";

            case 1:
                return "Species";

            case 2:
                return "Size";

            case 3:
                return "Diseases";
        }
    }
    return QVariant();
}

vector<Bacteria> Service::getBacteriaByBiologistSpecies(string biologistName) {
    vector<Bacteria> result;
    vector<Bacteria> bacterias = this->bacteriaRepo.getBacteria();
    for(auto& bacteria : bacterias)
    {
        string check = bacteria.getSpecies();
        Biologist b1 = this->biologistsRepo.getBiologistByName(biologistName);
        vector<string> species = b1.getBacteriaSpecies();
        for(auto& specie : species)
            if(specie == check)
                result.push_back(bacteria);
    }
    return result;
}

void Service::addBacteria(string name, string species, int size, vector<string> diseases) {
    this->beginInsertRows(QModelIndex(), this->rowCount(), this->rowCount());

    ///check if the name and the species is unique
    vector<Bacteria> bacterias = this->bacteriaRepo.getBacteria();
    for(auto& bacteria : bacterias)
        if(bacteria.getName() == name || bacteria.getSpecies() == species)
            throw std::exception();

    Bacteria bacteria_to_add { name, species, size, diseases };
    this->bacteriaRepo.addBacteria(bacteria_to_add);

    this->endInsertRows();
}

bool Service::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::EditRole)
    {
        Bacteria& bacteria = this->bacteriaRepo.getBacteria()[index.row()];
        int column = index.column();

        switch (column)
        {
            case 0:
                bacteria.setName(value.toString().toStdString());
                break;

            case 1:
                bacteria.setSpecies(value.toString().toStdString());
                break;

            case 2:
                bacteria.setSize(value.toInt());
                break;

            case 3:
                {
                    string result = value.toString().toStdString();
                    vector<string> diseases;
                    string current = "";
                    for (auto& character : result)
                    {
                        if (character == ' ')
                        {
                            diseases.push_back(current);
                            current = "";
                        }
                        else
                            current += character;
                    }
                    diseases.push_back(current);
                    bacteria.setDiseases(diseases);
                    break;
                }
        }
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags Service::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}




