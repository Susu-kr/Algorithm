/*
	����.
	���� : 4�� ������ �������� ��, 100�� ����� �ƴϾ�� �ϰ�, �� �߿��� 400�� ����� ���� ���Ѿ��Ѵ�.
	������ 366���̴�.
	bool isLeapYear(int ����)
	int isLeapYear(int ����)
*/

#include <iostream>

using namespace std;

bool isLeapYear(int year);

int main() {
	int year;
	cin >> year;
	for (int i = 1; i <= year; i++) {
		if (isLeapYear(i) == true) {
			cout << i << "�� �����̴�." << endl;
		}
		else cout << i << "�� ����̴�." << endl;
	}
	return 0;
}

bool isLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	return false;
}