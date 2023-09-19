#include "studentsModel.h"

int studentsModel::rowCount(const QModelIndex& parent) const
{
	return repo.getSize();
}

int studentsModel::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant studentsModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	Student s = repo.getStudents()[row];
	if(role == Qt::DisplayRole)
		switch (column)
		{
		case 0:
			return QString::fromStdString(s.getName());
		case 1:
			return QString::fromStdString(s.getGroup());
		case 2:
			return QString::number(s.getSeminarGrade());
		case 3:
			return QString::number(s.getLabGrade());
		}
	return QVariant();
}
QVariant studentsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		switch (section)
		{
		case 0:
			return "Name";
		case 1:
			return "Group";
		case 2:
			return "Seminar Grade";
		case 3:
			return "Lab Grade";
		}
	}
	return QVariant();
}

Qt::ItemFlags studentsModel::flags(const QModelIndex& index) const
{
    if(index.column() == 1 ||index.column() == 2 || index.column() == 3)
	    return Qt::ItemIsEditable | QAbstractTableModel::flags(index); /// we can edit the specific field
    return QAbstractTableModel::flags(index);
}

bool studentsModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    Student& s = repo.getStudents()[index.row()];
    int column = index.column();
    if(role == Qt::EditRole) {
        switch (column) {
            case 1:
                s.setGroup(value.toString().toStdString());
                break;
            case 2:
                s.setSeminarGrade(value.toInt());
                break;
            case 3:
                s.setLabGrade(value.toInt());
                break;
        }
        emit dataChanged(index, index); ///signal for setting the updated grade in the table instantly
        return true;
    }

    return false;

}

void studentsModel::addStudent(string name, string group, double seminarGrade, double labGrade) {
    ///function that adds a new student to the table
    beginInsertRows(QModelIndex(), repo.getSize(), repo.getSize());
    Student s{name, group, seminarGrade, labGrade};
    this->repo.addStudent(s);
    endInsertRows();
}

