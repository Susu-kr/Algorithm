#include <iostream>

using namespace std;

int sum_total(int n);

int main() {
	int n;
	cin >> n;
	cout << sum_total(n);
	return 0;
}

int sum_total(int n) {
	return (int)((1 + n) * ((float)n / 2));
}