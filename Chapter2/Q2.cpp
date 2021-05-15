/*
	문제2. 위의 문제에서 10진수가 아닌 임의의 진수를 입력받아서 변환하는 프로그램
	ex) 입력진수 : 2
		값		: 11
		출력진수 : 10
		2진수 11은 10진수 3입니다.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void change(int n, int m, string k);

int main() {
	int N, M;
	string K;
	bool chk;
	while (1) {
		chk = true;
		cout << "입력진수 : "; cin >> N;
		cout << "값 입력  : "; cin >> K;
		for (int i = 0; i < K.size(); i++) {
			if (K[i] - '0' > 10) {
				if (N <= K[i] - '0' - 7) {
					cout << "입력진수에 맞는 값을 입력하세요" << endl;
					chk = false;
					break;
				}
			}
			else {
				if (N <= K[i] - '0') {
					cout << "입력진수에 맞는 값을 입력하세요" << endl;
					chk = false;
					break;
				}
			}
		}
		if (chk == false) continue;
		cout << "출력진수 : "; cin >> M;
		if (M > 1 && M < 37 && N > 1 && N < 37) break;
		else cout << "2 ~ 36진수 사이를 입력하세요" << endl;
	}
	change(N, M, K);
	return 0;
}

void change(int n, int m, string k) {
	vector<int> v;
	int num = 0;
	for (int i = 0; i < k.size(); i++) {
		num *= n;
		if (k[i] - '0' > 10) num += k[i] - '0' - 7;
		else num += k[i] - '0';
	}
	cout << num << endl;
	while (num > 0) {
		v.push_back(num % m);
		num /= m;
	}
	cout << n << "진수 " << k << "는 " << m << "진수 ";
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] < 10) cout << v[i];
		else putchar(v[i] + 55);
	}
	cout << "입니다.";
}