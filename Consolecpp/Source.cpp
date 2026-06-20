#include "Header.h"
#include <iostream>
using namespace std;
Task::Task() {
	name = "NO name";
	status = false;
}
Task::Task(const std::string& a, const std::string& b, bool c) {
	name = a;
	description = b;
	status = c;
}
Task::Task(const Task& a) {
	name = a.name;
	description = a.description;
	status = a.status;
}
void Task::Name(const string& a) {
	name = a;
}
void Task::Description(const std::string& a) {
	description = a;
}
void Task::changetrue() {
	status = true;
}
void Task::changefalse() {
	status = false;
}
void Task::changetruefalse() {
	status = !status;
}
void Task::print() const {
	if (status == true) {
		cout << "[✓] Name: " << name << " Description: " << description << endl;
	}
	else {
		cout << "[] Name: " << name << " Description: " << description << endl;
	}
}
string Task::line() {
	string Line;
	if(status == true)
		Line = name + "|" + description + "|done";
	else
		Line = name + "|" + description + "|Not done";
	return Line;
}
Task Task::lineIn(const std::string& a) {
	int c= 0;
	string Name;
	string Description;
	string Status;
	for (char g : a) {
		if (g == '|') 
			c++;
		else {
			if (c == 0)
				Name += g;
			if (c == 1)
				Description += g;
			if (c == 2)
				Status += g;
		}
	}
	bool gg = (Status == "done");
	return Task(Name, Description, gg);
}