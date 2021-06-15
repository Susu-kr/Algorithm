#include <iostream>
#include <string>

using namespace std;

int main() {
	string data = "abdabeabcabq";
	string b = "bca";
	bool chk = false;
	int t = 0;
	int cnt = 0;
	for (int i = 0; i < data.size(); i++) {
		cout << i;
		t = i;
		for (int j = 0; j < b.size(); j++) {
			cnt++;
			cout << " " << data << "\n  ";
			if (data[t] != b[j]) {
				for (int k = 0; k < data.size(); k++) {
					if (k == t) cout << "|";
					else cout << " ";
				}
				cout << "\n  ";
				for (int k = 0; k < i; k++) cout << " ";
				cout << b << endl;
				chk = false;
				break;
			}
			for (int k = 0; k <= t; k++) {
				if (k == t) cout << "+";
				else cout << " ";
			}
			cout << "\n  ";
			for (int k = 0; k < i; k++) cout << " ";
			cout << b << "\n ";
			chk = true;
			t++;
		}
		if (chk) {
			cout << "\b찾고자 하는 단어는 " << i << " ~ " << i+b.size()-1 << "에 있습니다.\n";
			cout << "비교는 총 " << cnt << "번 했습니다." << endl;
			break;
		}
		cout << endl;
	}
	if(!chk) cout << "찾고자 하는 단어가 존재하지 않습니다.\n";

	return 0;
}