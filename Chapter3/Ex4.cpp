#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void Binary_Search(vector<int> v, int t);

int main() {
	int N;
	cout << "������ �Է��ϼ��� : ";
	cin >> N;
	vector<int> v;
	cout << "������������ ���ڸ� �Է��ϼ��� : ";
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	int target;
	cout << "ã���� �ϴ� ���ڸ� �Է��ϼ��� : ";
	cin >> target;	
	Binary_Search(v, target);
	return 0;
}
void Binary_Search(vector<int> v, int t) {
	int left = 0, right = v.size() - 1, mid;
	if ((right + left) % 2 == 0) mid = (right + left) / 2;
	else mid = (right + left - 1) / 2;
	cout << "  |";
	for (int i = 0; i < v.size(); i++) {
		cout << " " << i;
	}
	cout << "\n--+";
	for (int i = 0; i < v.size(); i++) {
		cout << "--";
	}
	for (int i = 0; i < (int)sqrt(v.size())+1; i++) {
		cout << "\n  |";
		for (int j = 0; j < v.size(); j++) {
			if (j == mid) cout << " + ";
			else if (j == left) cout << " <-";
			else if (j == right) cout << " ->";
			else cout << "   ";
		}
		cout << "\n " << mid << "| ";
		for (int j = 0; j < v.size(); j++) {
			cout << v[j] << "  ";
		}
		if(v[mid] > t) right = mid - 1;
		else if (v[mid] < t) left = mid + 1;
		else {
			cout << "\n" << t << "�� v[" << mid << "]�� �����մϴ�." << endl;
			break;
		}
		if ((right + left) % 2 == 0) mid = (right + left) / 2;
		else mid = (right + left - 1) / 2;
	}
	cout << "\n" << t << "�� �������� �ʽ��ϴ�." << endl;
}