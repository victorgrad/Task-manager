#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qtablewidget.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qerrormessage.h>
#include "serv.h"
class Gui : public QWidget {
private:
	Service& serv;
	QTableWidget* tabel;
	QLineEdit* txtid;
	QLineEdit* txtdesc;
	QLineEdit* txtprog;
	QLineEdit* txtstare;
	QLineEdit* txtsrch;
	QPushButton* adauga;
	QErrorMessage* error = new QErrorMessage;

	void afiseaza(const vector<Task>& tsks);

public:
	Gui(Service& serv);
	void Update();
	void addt();
	void srch();
};