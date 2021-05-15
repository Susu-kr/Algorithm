/*
	����1. 10������ �Է¹ް� ��ȯ�ϰ��� �ϴ� ������ �Է¹��� ��,
	�ش� ������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��϶�. (2 ~ 36����)
	ex) 10���� �Է� : 59
		��� ���� : 8
		10���� 59�� 8���� 73
*/

#include <iostream>
#include <vector>
using namespace std;

void change(int n, int m);

int main() {
	int N, M;
	while (1) {
		cout << "10���� �Է� : "; cin >> N;
		cout << "����� ���� : "; cin >> M;
		if (M > 1 && M < 37) break;
		else cout << "2 ~ 36���� ���̸� �Է��ϼ���" << endl;
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
	cout << "10���� " << n << "�� " << m << "���� ";
	for (int i = k.size() - 1; i >= 0; i--) {
		if (k[i] < 10) cout << k[i];
		else putchar(k[i] + 55);
	}
	cout << " �Դϴ�.";
}