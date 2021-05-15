#include <iostream>

using namespace std;

void spira(int n);
void nrpira(int n);

int main() {
	int n;
	cin >> n;
	cout << "피라미드" << endl;
	spira(n);
	cout << endl;
	cout << "역 피라미드" << endl;
	nrpira(n);

	return 0;
}
void spira(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= (i - 1) * 2 + 1; j++) {
			cout << i % 10;
		}
		cout << endl;
	}
}
void nrpira(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i-1; j++) {
			cout << " ";
		}
		for (int j = 1; j <= (n-i)*2 + 1; j++) {
			cout << i % 10;
		}
		cout << endl;
	}
}