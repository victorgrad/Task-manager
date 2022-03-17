#include "gui.h"

Gui::Gui(Service& serv) :serv{ serv } {
	QHBoxLayout* mainLay = new QHBoxLayout;
	this->setLayout(mainLay);

	//stanga
	QVBoxLayout* stangal = new QVBoxLayout;
	tabel = new QTableWidget;
	stangal->addWidget(tabel);
	tabel->setColumnCount(4);
	tabel->setHorizontalHeaderLabels({ "Id","Descriere","Programatori","Stare" });
	QFormLayout* formularst = new QFormLayout;
	QLabel* src = new QLabel{ "Cauta Programatori:" };
	txtsrch = new QLineEdit;
	formularst->addRow(src, txtsrch);
	stangal->addLayout(formularst);
	connect(txtsrch, &QLineEdit::textChanged,this,&Gui::srch);

	//dreapta
	QVBoxLayout* dreaptal = new QVBoxLayout;

	QFormLayout* formular = new QFormLayout;
	QLabel* id = new QLabel{ "ID:" };
	QLabel* desc = new QLabel{ "Descriere:" };
	QLabel* prog = new QLabel{ "Programatori:" };
	QLabel* stare = new QLabel{ "Stare:" };
	txtid = new QLineEdit;
	txtdesc = new QLineEdit;
	txtprog = new QLineEdit;
	txtstare = new QLineEdit;
	formular->addRow(id, txtid);
	formular->addRow(desc, txtdesc);
	formular->addRow(prog, txtprog);
	formular->addRow(stare, txtstare);

	dreaptal->addLayout(formular);
	
	adauga = new QPushButton{"Adauga"};
	dreaptal->addWidget(adauga);
	connect(adauga, &QPushButton::released, this, &Gui::addt);


	mainLay->addLayout(stangal);
	mainLay->addLayout(dreaptal);
}

void Gui::afiseaza(const vector<Task>& tsks) {
	tabel->setRowCount(0);
	for (const auto& tsk : tsks) {
		tabel->insertRow(tabel->rowCount());
		QTableWidgetItem* id = new QTableWidgetItem{ QString::number(tsk.getId()) };
		QTableWidgetItem* desc = new QTableWidgetItem{ QString::fromStdString(tsk.getDescriere()) };
		QString progs;
		for (const auto& prog : tsk.getProgramatori()) {
			progs += QString::fromStdString(prog);
			progs += ", ";
		}
		QTableWidgetItem* prog = new QTableWidgetItem{ progs };
		QTableWidgetItem*  stare = new QTableWidgetItem{ QString::fromStdString(tsk.getStare()) };
		tabel->setItem(tabel->rowCount() - 1, 0, id);
		tabel->setItem(tabel->rowCount() - 1, 1, desc);
		tabel->setItem(tabel->rowCount() - 1, 2, prog);
		tabel->setItem(tabel->rowCount() - 1, 3, stare);
	}
}

void Gui::Update() {
	afiseaza(serv.getRepo());
}

void Gui::addt() {
	string id = txtid->text().toStdString();
	string desc = txtdesc->text().toStdString();
	string prog = txtprog->text().toStdString();
	string stare = txtstare->text().toStdString();
	try {
		serv.addt(id, desc, prog, stare);
	}
	catch (const MyErr& err) {
		error->showMessage(err.getMsg().c_str());
	}
	Update();
}

void Gui::srch() {
	string txt{ txtsrch->text().toStdString() };
	if (txt == "") {
		Update();
	}
	else {
		vector<Task> rez = serv.srch(txt);
		afiseaza(rez);
	}
}