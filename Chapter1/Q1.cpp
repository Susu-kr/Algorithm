#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

using namespace std;

int max4(int a, int b, int c, int d);
int min3(int a, int b, int c);
int min4(int a, int b, int c, int d);

int main() {
	int a, b, c, d;

	cout << "a : ";	cin >> a;
	cout << "b : ";	cin >> b;
	cout << "c : ";	cin >> c;
	cout << "d : ";	cin >> d;

	cout << "max4(a,b,c,d) = " << max4(a, b, c, d) << endl;
	cout << "min3(a,b,c) = " << min3(a, b, c) << endl;
	cout << "min4(a,b,c,d) = " << min4(a, b, c, d) << endl;

	//printf("a : "); scanf("%d", &a);
	//printf("b : "); scanf("%d", &b);
	//printf("c : "); scanf("%d", &c);
	//printf("d : "); scanf("%d", &d);

	//printf("max4(%d,%d,%d,%d) = %d\n", a, b, c, d, max4(a, b, c, d));
	//printf("min3(%d,%d,%d) = %d\n", a, b, c, min3(a, b, c));
	//printf("min4(%d,%d,%d,%d) = %d\n", a, b, c, d, min4(a, b, c, d));

	return 0;
}

int max4(int a, int b, int c, int d) {
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	return max;
}

int min3(int a, int b, int c) {
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return min;
}

int min4(int a, int b, int c, int d) {
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	if (d < min) min = d;
	return min;
}