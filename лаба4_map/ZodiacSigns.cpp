﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include "ZodiacSigns.h"
#include <fstream>


/*
18.02 Водолей 18.02 89284587196 Творческий
20.02 Рыбы 20.02 88526987452 Мечтатель
24.03 Овен 24.03 89530707011 Импульсивный
08.04 Телец 08.04 89745689123 Практичный
12.05 Близнецы 12.05 892841258796 Яркий
22.06 Рак 22.06 89185698471 Чувствительный
26.07 Лев 26.07 89612587496 Харизматичный
22.08 Дева 22.08 89621235689 Справедливый
24.10 Весы 24.10 8938659152 Актер
12.11 Скорпион 12.11 89284523678 Независимый
22.12 Стрелец 22.12 89284568961 Активный
16.01 Козерог 16.01 89284568974 Стойкий
*/

using namespace std;

int main()
{
	setlocale(0, "");

	map<double, ZodiacSigns> Zodiac;

	string path = "map_in.txt";
	std::ifstream infile(path);

	if (!infile.is_open()) {
		cout << "файл input.txt не найден" << endl;
		return 0;
	}

	string sign;
	double birth_date;
	long long int number;
	string cha;

	double key;
	ZodiacSigns value;
	while (infile >> key >> sign >> birth_date >> number >> cha) {
		value = { sign, birth_date , number, cha };
		Zodiac[key] = value;
	}


	for (auto it = Zodiac.begin(); it != Zodiac.end(); ++it)
	{
		cout << it->first << " : " << it->second.getSign() << endl;
	}

	double date;
	cout << "Введите дату рождения:" << endl;
	cin >> date;
	auto res = Zodiac.find(date);
	if (res != Zodiac.end()) {

		cout << "Номер телефона: ";
		cout << res->second.getPhoneNumber();
		cout << endl << "Знак зодиака: ";
		cout << res->second.getSign();
		cout << endl << "Характеристика знака: ";
		cout << res->second.getCharacteristic();
	}
	else  cout << "Нет пользователя с такой датой рождения!"; exit(1);

	system("Pause");
}

