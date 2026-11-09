#include "Todolist.h"
#include <iostream>
#include <fstream>
using namespace std;
void Todolist::addtask(const string& a, const string& b) {
	tasks.push_back(make_unique<Task>(a, b, false));
}
void Todolist::remove(int a) {
	tasks.erase(tasks.begin() + a);
}
void Todolist::complete(int a) {
	tasks[a]->changetruefalse();
}
void Todolist::show() const {
	for (int i = 0; i < tasks.size(); i++) {
		tasks[i]->print();
	}
}
void Todolist::save(const string& a) const {
	ofstream file(a);
	if (!file.is_open()) {
		cout << "Error" << endl;
	}
	else {
		for (const auto& task : tasks) {
			file << task->line() << endl;
		}
		file.close();
		cout << "File save!";
	}
}
void Todolist::file(const string& a) {
	ifstream file(a);

	if (!file.is_open()) {
		cout << "Файл не найден. Создан новый список." << endl;
		return;
	}
	string lin;
	while (getline(file, lin)) {
		if (!lin.empty()) {
			Task task = Task::lineIn(lin);
			tasks.push_back(make_unique<Task>(task));
		}
	}
	file.close();
	cout << "Файл загружен!" << endl;
}
int Todolist::size() const {
	return tasks.size();
}
void Todolist::clear() {
	tasks.clear();
}
