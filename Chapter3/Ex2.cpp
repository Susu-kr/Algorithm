#include <iostream>
#include <vector>
using namespace std;
void Linear_Search(int n);

int main() {
	int N;
	cin >> N;
	Linear_Search(N);
	return 0;
}

void Linear_Search( int n) {
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	int target;
	cout << "찾고자 하는 숫자를 입력하세요 : "; cin >> target;
	cout << "  | ";
	for (int i = 0; i < n; i++) {
		cout << i << " ";
	}
	cout << "\n--+";
	for (int i = 0; i < n; i++) {
		cout << "--";
	}
	for (int i = 0; i < n; i++) {
		cout << "\n  |";
		for (int j = 0; j < i; j++) {
			cout << "  ";
		}
		cout << " *\n " << i << "| ";
		for (int j = 0; j < n; j++) {
			cout << v[j] << " ";
		}
		if (v[i] == target) {
			cout << "\n" << target << "은 v[" << i << "]에 존재합니다." << endl;
			break;
		}
	}
}