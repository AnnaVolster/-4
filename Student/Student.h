#pragma once

#include <string>

/*1.	����� �������� (Student)� � ������:
��� ��������,
����� ������,
������� ����,
������� ���������.
������� �������� �� ���������� ������:
-������� ���������, ������� ���� � ������� ������ ���������� �����;
-������� ���������, �� ������� ���������.
*/


class Student {
private:
	std::string Surname;
	int _group;
	double _midGrade;
	bool _scholarship;

public:
	Student(std::string n, int g, double m, bool s) : Surname(n), _group(g), _midGrade(m), _scholarship(s) {}
	Student() {}

	//bool operator()(const Student& a) { return (a.getMidGrade() >= 3.5); }

	std::string getName() const { return Surname; }

	int getGroup() const { return _group; }

	double getMidGrade() const { return _midGrade; }

	bool IsScholarship() const { return _scholarship; }

};

int value;
bool b;
double p;

//�������������� �������� ��� find_if 

struct foGroup {
	bool operator()(Student a) { return (a.getGroup() == value); }
};

struct foScholarship {
	bool operator()(Student a) { return (a.IsScholarship()); }
};


struct foMidGrade {
	bool operator()(const Student& a) { return (a.getMidGrade() >= p); }
};


