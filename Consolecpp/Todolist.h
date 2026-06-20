#ifndef TODOLIST_H
#define TODOLIST_H
#include <vector>
#include <memory>
#include "Header.h"
class Todolist {
private:
	std::vector<std::unique_ptr<Task>> tasks;
public:
	void addtask(const std::string& a, const std::string& b);
	void remove(int a);
	void complete(int a);
	void show() const;
	void save(const std::string& a) const;
	void file(const std::string& a);
	int size() const;
	void clear();
};
#endif