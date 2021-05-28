#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main() {
	string s;
	cout << "수식을 입력하세요 : ";
	cin >> s;
	stack<char> op_c;
	stack<double> op_d;
	queue<char> q;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			q.push(s[i]);
		}
		else {
			op_c.push(s[i]);
		}
		cout << "\t\t stack : ";
		for (int j = 0; j < op_c.size(); j++) {
			cout << op_c.top() << " ";
		}
		cout << "\t\t queue : ";
		for (int j = 0; j < q.size(); j++) {
			cout << q.back() << " ";
		}
		cout << endl;
	}

	return 0;
}