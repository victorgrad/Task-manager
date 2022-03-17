#pragma once
#include "repo.h"
#include <cstdlib>

class Validator {
public:
	int nrValid(const string& str) const;
	void stareValid(const string& stare) const;
	void progsValid(const vector<string>& progs) const;
};

class Service {
public:
	Service(const Validator& val, Repository& repo) :repo{ repo }, val{ val }{}
	void addt(const string& id, const string& descriere,string& progs, const string& stare);
	const vector<Task>& getRepo() const;
	const vector<Task> srch(const string& str) const;
private:
	Repository& repo;
	Validator val;
};