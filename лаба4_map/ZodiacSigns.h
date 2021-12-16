#pragma once
#include <string>

/*5.	����� ������ ������� (ZodiacSigns)� � ������:
���,
���� �������,
���� ��������,
����� ��������,
������� �������������� �����.
������� �� ���������� ���� ��������:
-�������,
-���� �������
-��� ��������������.*/


class ZodiacSigns {
private:
	std::string _sign;
	double _birth_date;
	long long int _phone_number;
	std::string _characteristic;

public:
	
	ZodiacSigns(std::string s, double b, long long int n, std::string c) : _sign(s), _birth_date(b), _phone_number(n), _characteristic(c) {}
	ZodiacSigns() {}

	std::string getSign() const { return _sign; }

	double getDateOfBurth() const { return _birth_date; }

	long long int getPhoneNumber() const { return _phone_number; }

	std::string getCharacteristic() const { return _characteristic; }

};