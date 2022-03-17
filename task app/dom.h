#pragma once
#include <string>]
#include <vector>
using namespace std;

class Task {
public:
	Task() = default;
	Task(const int& id, const string& descriere, const vector<string>& prog, const string& stare) :id{ id }, descriere{ descriere }, programatori{ prog }, stare{ stare }{}
	Task(const Task& ot) {
		id = ot.id;
		descriere = ot.descriere;
		programatori = ot.programatori;
		stare = ot.stare;
	}

	Task& operator=(const Task& ot) {
		if (this == &ot)
			return *this;
		id = ot.id;
		descriere = ot.descriere;
		programatori = ot.programatori;
		stare = ot.stare;
	}

	const int getId() const;
	const string getDescriere() const;
	const vector<string>& getProgramatori() const;
	const string getStare() const;

private:
	int id;
	string descriere;
	vector<string> programatori;
	string stare;
};

class MyErr {
public:
	MyErr(const string& str):msg{str}{}
	string getMsg() const;
private:
	string msg;
};