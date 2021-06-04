#include <iostream>
#include <vector>

using namespace std;

void solution(int N);


int Relation[101][101];
int TotalFriend[101][101];

int main() {
	int N;
	cout << "��ü ��� �� : ";
	cin >> N;
	while (N > 100 || N < 2) {
		cout << "��ü ����� 2�� �̻� 100�� ���� �Դϴ�." << endl;
		cout << "��ü ��� �� : ";
		cin >> N;
	}
	solution(N);
	return 0;
}

void solution(int N) {
	vector <vector<int>> v(N+1, vector<int>(1, 0));
	int has_f, f;
	for (int i = 1; i <= N; i++) {
		int min = 0, max = N-1; // �ּ� ģ�� ��, �ִ� ģ�� ��
		for (int j = 1; j <= N; j++) {
			if (Relation[j][i] == 1) min++; // �ڽ��� ģ���� �ϴ� ����� �����ϸ� �ּ� ģ�� �� ����
			else if (Relation[j][i] == -1) max--; // �ڽ��� ģ���� ���� ���� ����� �����ϸ� �ִ� ģ�� �� ����
		}
		if (i == 1) min++;
		cout << i << "�� ������� ģ�� �� (" << min << " ~ " << max << ") : ";
		cin >> has_f;
		if (has_f < min || has_f > max) {
			i--;
			cout << "ģ�� ���� �ùٸ��� �ʽ��ϴ�." << endl;
			continue;
		}
		int cnt = 1; // ���� ģ���� ��� ���
		for (int k = 1; k <= N; k++) {
			if (Relation[k][i] == 1) {
				Relation[i][k] = TotalFriend[i][k] = 1;
				cout << cnt << "��° ģ�� : " << k << endl;
				cnt++;
			}
		}
		if (cnt <= has_f) { // �Է��� ģ�� ���� ������� ���� ģ�� �� ���� ���� ���
			for (int j = cnt; j <= has_f; j++) {
				cout << j << "��° ģ�� : ";
				cin >> f;
				if (f == i || f > N || Relation[f][i] == -1) { // �Է��� ģ���� �ڱ� �ڽ� or �������� �ʴ� ģ�� or ģ����� ���� ���� ����� ���
					j--;
					cout << "ģ�����谡 Ʋ�Ƚ��ϴ�. �ٽ� �Է��ϼ���." << endl;
					continue;
				}

				if (Relation[i][f] == 0) Relation[i][f] = TotalFriend[i][f] = 1;
				else { // 
					cout << "�̹� ģ������ �Դϴ�. �ٸ� ����ڸ� �Է��ϼ���." << endl;
					j--;
				}
			}
		}
		cout << endl;
		for (int j = 1; j <= N; j++) { // �� ����� ģ�� ���谡 ������ ģ���� �ƴ϶�� �ߴ� ������� -1�� ����
			if (Relation[i][j] == 0) Relation[i][j] = TotalFriend[i][j] = -1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Relation[i][j] == 1) {
				for (int k = 1; k <= N; k++) {
					if (Relation[j][k] == 1 && i != k)
						TotalFriend[i][k] = 1;
				}
			}
		}
	}
	cout << "ģ��-ģ��" << endl;
	for (int i = 1; i <= N; i++) {
		cout << i << "�� ������� ģ�� : ";
		for (int j = 1; j <= N; j++) {
			if (Relation[i][j] == 1) cout << j << " ";
		}
		cout << endl;
	}
	cout << "========================================" << endl;
	cout << "ģ��-ģ��-ģ��" << endl;
	for (int i = 1; i <= N; i++) {
		cout << i << "�� ������� ģ�� : ";
		for (int j = 1; j <= N; j++) {
			if (TotalFriend[i][j] == 1) cout << j << " ";
		}
		cout << endl;
	}
}