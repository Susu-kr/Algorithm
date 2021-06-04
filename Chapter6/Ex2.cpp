#include <iostream>
#include <vector>
#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)
using namespace std;

void SORT1 (vector<int> v);
void SORT2 (vector<int> v);
void SORT3 (vector<int> v);


int main() {
	
	vector<int> v;
	int N;
	cout << "��� ���� �Է� : ";
	cin >> N;
	cout << "V : ";
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}
	vector<int> v2 = v;
	vector<int> v3 = v;

	SORT1(v);
	SORT2(v2);
	SORT3(v3);
	return 0;
}

void SORT1 (vector<int> v) {
	cout << "SORT1" << endl;
	int cmp_cnt = 0, change_cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		cout << "�н�" << i + 1 << endl;
		for (int j = v.size() - 1; j > i; j--) {
			bool chk = false;
			cmp_cnt++;
			if (v[j] < v[j - 1]) {
				change_cnt++;
				chk = true;
			}
			for (int k = 0; k < v.size(); k++) {
				if (chk == true && k == j) cout << "+ " << v[k] << " ";
				else if (chk == false && k == j) cout << "- " << v[k] << " ";
				else cout << v[k] << " ";
			}
			if(chk) swap(int, v[j], v[j - 1]);
			cout << endl;
		}
	}
	cout << "�񱳸� " << cmp_cnt << "ȸ �߽��ϴ�." << endl;
	cout << "��ȯ�� " << change_cnt << "ȸ �߽��ϴ�." << endl;
}

void SORT2(vector<int> v) {
	cout << "SORT2" << endl;
	int cmp_cnt = 0, change_cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		cout << "�н�" << i + 1 << endl;
		int t_c = change_cnt;
		for (int j = v.size() - 1; j > i; j--) {
			bool chk = false;
			cmp_cnt++;
			if (v[j] < v[j - 1]) {
				change_cnt++;
				chk = true;
			}
			for (int k = 0; k < v.size(); k++) {
				if (chk == true && k == j) cout << "+ " << v[k] << " ";
				else if (chk == false && k == j) cout << "- " << v[k] << " ";
				else cout << v[k] << " ";
			}
			if (chk) swap(int, v[j], v[j - 1]);
			cout << endl;
		}
		if (t_c == change_cnt) break;
	}
	cout << "�񱳸� " << cmp_cnt << "ȸ �߽��ϴ�." << endl;
	cout << "��ȯ�� " << change_cnt << "ȸ �߽��ϴ�." << endl;
}

void SORT3(vector<int> v) {
	cout << "SORT3" << endl;
	int cmp_cnt = 0, change_cnt = 0;
	int i = 0, t = 1;
	while(i < v.size() - 1) {
		cout << "�н�" << t << endl;
		int last = v.size() - 1;
		for (int j = v.size() - 1; j > i; j--) {
			bool chk = false;
			cmp_cnt++;
			if (v[j] < v[j - 1]) {
				change_cnt++;
				chk = true;
				last = j;
			}
			for (int k = 0; k < v.size(); k++) {
				if (chk == true && k == j) cout << "+ " << v[k] << " ";
				else if (chk == false && k == j) cout << "- " << v[k] << " ";
				else cout << v[k] << " ";
			}
			if (chk) swap(int, v[j], v[j - 1]);
			cout << endl;
		}
		i = last;
		t++;
	}
	cout << "�񱳸� " << cmp_cnt << "ȸ �߽��ϴ�." << endl;
	cout << "��ȯ�� " << change_cnt << "ȸ �߽��ϴ�." << endl;
}