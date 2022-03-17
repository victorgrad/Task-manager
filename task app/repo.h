#pragma once
#include "dom.h"
class Repository {
public:
	Repository(const string& filename) : filename{ filename } {
		loadFromFile();
		sortt();
	}
	~Repository() = default;
	void addt(const Task& task);
	void sortt();
	const vector<Task>& getRepo() const;

private:
	vector<Task> tasks;
	void loadFromFile();
	void storeToFile();
	string filename;
};