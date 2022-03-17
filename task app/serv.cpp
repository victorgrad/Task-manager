#include "serv.h"
const vector<Task>& Service::getRepo() const {
	return repo.getRepo();
}
void Service::addt(const string& idi, const string& descriere, string& progs, const string& stare) {
	vector<Task> rep = repo.getRepo();
	int id=val.nrValid(idi);
	if(id<0)
		throw(MyErr{ "Id invalid" });
	for (auto& tsk : repo.getRepo()) {
		if(id==tsk.getId())
			throw(MyErr{ "Id existent" });
	}
	vector<string> prog;
	string del{ "," };
	size_t poz = progs.find(del);
	string progSingle;
	while (poz != string::npos) {
		progSingle = progs.substr(0, poz);
		prog.push_back(progSingle);
		progs.erase(0, poz + del.length());
		poz = progs.find(del);
	}
	val.progsValid(prog);
	val.stareValid(stare);
	if(descriere==string{""})
		throw(MyErr{ "Descriere invalida" });
	Task tsk{ id,descriere,prog,stare };
	repo.addt(tsk);
}
int Validator::nrValid(const string& numar) const {
	int nr;
	nr = atoi(numar.c_str());
	if (nr != 0 || numar == "0") {
		return nr;
	}
	else {
		throw(MyErr{ "Date invalide" });
	}

}
void Validator::stareValid(const string& stare) const {
	if (stare == string{ "open" })
		return;
	if (stare == string{ "inprogress" })
		return;
	if (stare == string{ "closed" })
		return;
	throw MyErr{ "Stare invalida" };
}
void Validator::progsValid(const vector<string>& progs) const {
	if (progs.size() >= 1 && progs.size() <= 4)
		return;
	throw MyErr{ "Nr programatori invalizi" };
}

const vector<Task> Service::srch(const string& str) const {
	vector<Task> tsks = repo.getRepo();
	vector<Task> rez;
	for (auto& tsk : tsks) {
		bool gasit = false;
		for (auto& nume : tsk.getProgramatori()) {
			if (nume == str) {
				gasit = true;
				break;
			}
		}
		if (gasit)
			rez.push_back(tsk);
	}
	return rez;
}
