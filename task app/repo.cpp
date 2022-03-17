#include "repo.h"
#include <algorithm>
#include <fstream>

void Repository::addt(const Task& task) {
	tasks.push_back(task);
	sortt();
	storeToFile();
}
void Repository::loadFromFile() {
	ifstream in(filename);
	if(!in.is_open())
		throw(MyErr{ "Eroare deschidere fisier" });
	while (!in.eof()) {
		int id;
		string stare,progs;
		char descrierestr[100];
		vector<string> prog;
		in >> id;
		in.get();
		in.getline(descrierestr,100);
		if (in.eof()) break;
		string descriere{ descrierestr };
		in >> stare;
		if (in.eof()) break;
		in >> progs;
		if (in.eof()) break;
		string del{ "," };
		size_t poz = progs.find(del);
		string progSingle;
		while (poz != string::npos) {
			progSingle = progs.substr(0, poz);
			prog.push_back(progSingle);
			progs.erase(0, poz + del.length());
			poz = progs.find(del);
		}
		Task tsk{ id,descriere,prog,stare };
		tasks.push_back(tsk);
	}
}
void Repository::storeToFile() {
	ofstream out(filename, ofstream::trunc);
	if (!out.is_open())
		throw(MyErr{ "Eroare deschidere fisier" });
	for (auto& tsk : tasks) {
		out << tsk.getId() << "\n" << tsk.getDescriere() << "\n" << tsk.getStare() << "\n";
		for (auto& prog : tsk.getProgramatori()) {
			out << prog << ",";
		}
		out << "\n";
	}
	out.close();
}
void Repository::sortt() {
	sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2) {
		return t1.getStare() < t2.getStare();
		});
}
const vector<Task>& Repository::getRepo() const {
	return tasks;
}