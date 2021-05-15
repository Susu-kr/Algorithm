#include <iostream>

using namespace std;

int mid(int a, int b, int c);

int main() {
	int a, b, c, m;
	cin >> a >> b >> c;
	m = mid(a, b, c);
	cout << "Áß¾Ó°ª : " << m << endl;
	return 0;
}

int mid(int a, int b, int c) {
	int m = 0;
	if (a >= b) {
		if (a > b) {
			if (b >= c) m = b;
			else {
				if (a >= c) m = c;
				else m = a;
			}
		}
		else {
			if (b >= c) m = b;
			else m = a;
		}
	}
	else {
		if (a >= c) m = a;
		else {
			if (b >= c) m = c;
			else m = b;
		}
	}
	return m;
}