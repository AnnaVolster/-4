#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"
#include <fstream>
#include <set>


/*
Иванов 21 4,5 1
Петрова 27 4,0 1
Добренко 28 2,0 0
Галченко 26 4,5 1
Скиба 21 5,0 1
Кутковой 21 3,5 0
Ключко 27 4,5 1
Гром 28 4,0 1
Демченко 21 3,2 0
Евдокимов 21 5,0 1
Крикун 26 4,0 1
Бондаренко 26 3,1 0
Горбенко 21 3,6 0
Сидоров 26 4,0 1
Ильченко 27 4,1 0
*/

using namespace std;

int main()
{
	setlocale(0, "");

	
	FILE* Fin = fopen("vector_in.txt", "r");
	if (Fin == NULL) {
		cout << "файл input.txt не найден";
		return 0;
	}


	vector<Student> student;
	char name1[15];
	string name;
	int grupe;
	double grade;
	bool scholar;
	int scholar2;

	for (int i = 0; i < 12; i++) {
		fscanf(Fin, "%s %d %lf %d", &name1, &grupe, &grade, &scholar2);
		name = name1;
		scholar = scholar2;
		student.push_back({ name, grupe, grade, scholar });
	}


	vector<Student>::iterator result;
	int count = 0;

	set <int> gr = { 21, 27, 26, 28 };
	int group;
	cout << "Введите группу студентов:" << endl;
	cin >> group;
	if (gr.find(group) != gr.end()) {

		int action;
		cout << "По заданной группе вывести:\n 1 - фамилии студентов, средний балл у которых больше задаваемой цифры;\n 2 - фамилии студентов, не имеющих стипендию." << endl;
		cin >> action;

		switch (action) {
		case 1:
			double value;
			cout << "Введите средний балл:" << endl;
			cin >> value;
			cout << endl << "Студенты группы " << group << ", у которых средний балл выше или равен " << value << ":\n";
			result = student.begin();
			while (result != student.end()) {
				result = find_if(result, student.end(), [value, group](const Student& a) { if (a.getGroup() == group) return a.getMidGrade() >= value; else return false; });
				if (result != student.end()) {
					cout << result->getName() << "\n";
					result++;
					count++;
				}
			}
			if (count == 0) { cout << endl << "В списке нет студентов с таким средним баллом" << endl; }
			break;
		case 2:
			cout << endl << "Студенты группы " << group << ", у которых нет стипендии " << ":\n";
			result = student.begin();
			while (result != student.end()) {
				result = find_if(result, student.end(), [group](const Student& a) { if (a.getGroup() == group) return !a.IsScholarship(); else return false; });
				if (result != student.end()) {
					cout << result->getName() << "\n";
					result++;
					count++;
				}
			}
			if (count == 0) { cout << endl << "В списке нет студентов, не имеющих стипендию" << endl; }
			break;
		}
	}
	else  cout << "Такой группы не существует!"; exit(1);

}
