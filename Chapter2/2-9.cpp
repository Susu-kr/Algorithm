#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void prime_num(int n);

int main() {
	int num;
	cout << "정수를 입력하세요 : "; cin >> num;
	prime_num(num);
	return 0;
}
void prime_num(int n) {
	vector<int> V;
	for (int i = 0; i <= n; i++) {
		V.push_back(i);
	}
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (V[i] == 0) continue;
		for (int j = i + i; j <= n; j += i) {
			V[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (V[i] != 0) cout << V[i] << "소수이다." << endl;
	}
	V.clear();
}