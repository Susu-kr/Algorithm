/*
	문제1. 10진수를 입력받고 변환하고자 하는 진수를 입력받은 후,
	해당 진수로 변환하여 출력하는 프로그램을 작성하라. (2 ~ 36진수)
	ex) 10진수 입력 : 59
		출력 진수 : 8
		10진수 59는 8진수 73
*/

#include <iostream>
#include <vector>
using namespace std;

void change(int n, int m);

int main() {
	int N, M;
	while (1) {
		cout << "10진수 입력 : "; cin >> N;
		cout << "출력할 진수 : "; cin >> M;
		if (M > 1 && M < 37) break;
		else cout << "2 ~ 36진수 사이를 입력하세요" << endl;
	}
	change(N, M);
	return 0;
}

void change(int n, int m) {
	int t = n;
	vector<int> k;
	while (t > 0) {
		k.push_back(t % m);
		t /= m;
	}
	cout << "10진수 " << n << "는 " << m << "진수 ";
	for (int i = k.size() - 1; i >= 0; i--) {
		if (k[i] < 10) cout << k[i];
		else putchar(k[i] + 55);
	}
	cout << " 입니다.";
}