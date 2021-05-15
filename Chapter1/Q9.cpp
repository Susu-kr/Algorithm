#include <iostream>

using namespace std;

int sum_total(int n, int m);

int main() {
	int n, m;
	while (1) {
		cout << "범위를 입력하세요(n ~ m)" << endl;
		cin >> n >> m;
		if (n > 0 && m > 0) break;
		cout << "양수만 입력하세요" << endl;
	}
	cout << sum_total(n, m);
	return 0;
}

int sum_total(int n, int m) {
	if (n < m){
		int total = (int)((1 + m) * (float)(m / 2));
		int temp = (int)((1 + n - 1) * (float)((n - 1) / 2));
		return total - temp;
	}
	else {
		int total = (int)((1 + n) * (float)(n / 2));
		int temp = (int)((1 + m - 1) * (float)((m - 1) / 2));
		return total - temp;
	}
}