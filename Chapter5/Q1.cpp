#include <iostream>
#include <string>

using namespace std;

void reverseDisplay(int value);
void reverseDisplay(const string & s);


int main() {
	int N;
	string s;
	cout << "���� 2-1 : ���� ������ ����ϱ�" << endl;
	cin >> N;
	reverseDisplay(N);
	cout << endl;
	cout << "���� 2-2 : ���ڿ� ������ ����ϱ�" << endl;
	cin >> s;
	reverseDisplay(s);

	return 0;
}

void reverseDisplay(int value) {
	int t = value % 10;
	cout << t;
	value /= 10;
	if(value > 0) reverseDisplay(value);
}
void reverseDisplay(const string & s) {
	int cnt = s.size()-1;
	string tmp;
	for (int i = 0; i < s.size(); i++) {
		if (i == cnt) cout << s[i];
		else if(cnt > i) tmp += s[i];
	}
	if (cnt != 0) reverseDisplay(tmp);
}
