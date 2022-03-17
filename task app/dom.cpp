#include "dom.h"

const int Task::getId() const {
	return id;
}
const string Task::getDescriere() const {
	return descriere;
}
const vector<string>& Task::getProgramatori() const {
	return programatori;
}
const string Task::getStare() const {
	return stare;
}
string MyErr::getMsg() const {
	return msg;
}