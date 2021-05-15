/*
	����2. ���� �������� 10������ �ƴ� ������ ������ �Է¹޾Ƽ� ��ȯ�ϴ� ���α׷�
	ex) �Է����� : 2
		��		: 11
		������� : 10
		2���� 11�� 10���� 3�Դϴ�.
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
		cout << "�Է����� : "; cin >> N;
		cout << "�� �Է�  : "; cin >> K;
		for (int i = 0; i < K.size(); i++) {
			if (K[i] - '0' > 10) {
				if (N <= K[i] - '0' - 7) {
					cout << "�Է������� �´� ���� �Է��ϼ���" << endl;
					chk = false;
					break;
				}
			}
			else {
				if (N <= K[i] - '0') {
					cout << "�Է������� �´� ���� �Է��ϼ���" << endl;
					chk = false;
					break;
				}
			}
		}
		if (chk == false) continue;
		cout << "������� : "; cin >> M;
		if (M > 1 && M < 37 && N > 1 && N < 37) break;
		else cout << "2 ~ 36���� ���̸� �Է��ϼ���" << endl;
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
	cout << n << "���� " << k << "�� " << m << "���� ";
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] < 10) cout << v[i];
		else putchar(v[i] + 55);
	}
	cout << "�Դϴ�.";
}