#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
class Task {
private:
	std::string name;
	std::string description;
	bool status;
public:
	Task();
	Task(const std::string& a, const std::string& b, bool c);
	Task(const Task& a);
	void Name(const std::string& a);
	void Description(const std::string& a);
	void changetrue();
	void changefalse();
	void changetruefalse();
	void print() const;
	std::string line();
	static Task lineIn(const std::string& a);

};
#endif
