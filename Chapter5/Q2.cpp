#include <iostream>
#include <string>

using namespace std;
void displayPermutation(const string & s1, const string & s2);

int main() {
	string s;
	cout << "문자열의 모든 순열을 출력하는 재귀 함수를 작성" << endl;
	cin >> s;
	displayPermutation(s, "");
	return 0;
}

void displayPermutation(const string & s1, const string & s2) {
	if (s1.size() > 2) {
		for (int i = 0; i < s1.size(); i++) {
			string t, tmp;
			tmp += s2 + s1[i];
			for (int j = 0; j < s1.size(); j++) {
				if (j != i) t += s1[j];
			}
			displayPermutation(t, tmp);
		}
	}
	else {
		cout << s1[0] << s1[1] << s2 << endl;
		cout << s1[1] << s1[0] << s2 << endl;
	}
}