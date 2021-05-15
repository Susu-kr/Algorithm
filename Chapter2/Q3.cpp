/*
	문제.
	윤년 : 4로 나누어 떨어지는 해, 100의 배수는 아니어야 하고, 그 중에서 400의 배수는 포함 시켜야한다.
	윤년은 366일이다.
	bool isLeapYear(int 연도)
	int isLeapYear(int 연도)
*/

#include <iostream>

using namespace std;

bool isLeapYear(int year);

int main() {
	int year;
	cin >> year;
	for (int i = 1; i <= year; i++) {
		if (isLeapYear(i) == true) {
			cout << i << "는 윤년이다." << endl;
		}
		else cout << i << "는 평년이다." << endl;
	}
	return 0;
}

bool isLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	return false;
}