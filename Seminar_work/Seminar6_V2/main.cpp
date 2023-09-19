#include <QtWidgets/QApplication>
#include "Repository.h"
#include "TeacherWidget.h"
#include "studentsModel.h"
#include <QSortFilterProxyModel>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Repository repo{"Students.txt"};

	studentsModel* s = new studentsModel(repo);

	TeacherWidget w{ s };
	w.setWindowTitle("Main teacher");
	w.show();

    QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel{};
    proxyModel->setSourceModel(s); ///the model that we want to sort/filter ; the model where we started from
    proxyModel->setFilterRegularExpression(QRegularExpression("911", QRegularExpression::CaseInsensitiveOption));
    proxyModel->setFilterKeyColumn(1);

	TeacherWidget teacherFor911{ proxyModel };
	teacherFor911.setWindowTitle("Teacher for 911" );
	teacherFor911.show();

	return a.exec();
}
