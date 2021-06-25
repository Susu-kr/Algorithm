#include <iostream>
#include <string>
#include "StopWatch.h"

using namespace std;
void B_F(string data, string ); // Bruth-Force
void KMP(string data, string ); // KMP
void B_M(string data, string ); // Boyer-Moore

int main() {
	
	string data;
	cout << "String : ";
	cin >> data;
	string F;
	cout << "Find word : ";
	cin >> F;

	StopWatch T;

	cout << "-----------------------------------------------\n";
	T.start();
	B_F(data, F);
	T.stop();
	cout << "Start : " << T.getStartTime() << "ms\tEnd : " << T.getEndTime() << "ms\tResult : " << T.getElapsedTime() << "ms\n"; T.start();
	cout << "-----------------------------------------------\n";
	T.start();
	KMP(data, F);
	T.stop();
	cout << "Start : " << T.getStartTime() << "ms\tEnd : " << T.getEndTime() << "ms\tResult : " << T.getElapsedTime() << "ms\n";
	cout << "-----------------------------------------------\n";
	T.start();
	B_M(data, F);
	T.stop();
	cout << "Start : " << T.getStartTime() << "ms\tEnd : " << T.getEndTime() << "ms\tResult : " << T.getElapsedTime() << "ms\n";
	cout << "-----------------------------------------------\n";
	return 0;
}

void B_F(string data, string b) {
	cout << "Bruth-Force\n";
	bool chk = false;
	int cnt = 0;
	for (int i = 0; i <= data.length() - b.length(); i++) {
		cout << i << endl;
		for (int j = 0; j < b.length(); j++) {
			cnt++;
			cout << data << "\n";
			for (int k = 0; k < i + j; k++) 
				cout << " ";
			data[i+j] == b[j] ? cout << "+\n" : cout << "|\n";
			for (int k = 0; k < i; k++)
				cout << " ";
			cout << b << "\n";
			if (data[i+j] != b[j]) {
				chk = false;
				break;
			}
			chk = true;
		}
		if (chk) {
			cout << "\b찾고자 하는 단어는 " << i << " ~ " << i + b.size() - 1 << "에 있습니다.\n";
			cout << "비교는 총 " << cnt << "번 했습니다." << endl;
			break;
		}
		cout << endl;
	}
	if (!chk) cout << "찾고자 하는 단어가 존재하지 않습니다.\n";
}

void KMP(string data, string k) {
	cout << "KMP\n";
	bool chk = false;
	int cnt = 0;
	for (int i = 0; i <= data.length() - k.length(); i++) {
		cout << i << endl;
		for (int j = 0; j < k.length(); j++) {
			cnt++;
			cout << data << "\n";
			for (int l = 0; l < i+j; l++)
				cout << " ";
			data[i + j] == k[j] ? cout << "+\n" : cout << "|\n";
			for (int l = 0; l < i; l++)
				cout << " ";
			cout << k << endl;
			if (data[i+j] != k[j]) {
				chk = false;
				i += j == 0 ? 0 : j - 1;
				break;
			}
			chk = true;
		}
		if (chk) {
			cout << "\b찾고자 하는 단어는 " << i << " ~ " << i + k.size() - 1 << "에 있습니다.\n";
			cout << "비교는 총 " << cnt << "번 했습니다." << endl;
			break;
		}
		cout << endl;
	}
	if (!chk) cout << "찾고자 하는 단어가 존재하지 않습니다.\n";
}
// ABCXDEZCABACABAC
// asdjhaskjdhaskjhdjkashdkjahsdkjhqweuyt
void B_M(string data, string m) {
	cout << "Boyer-Moore\n";
	bool chk = false;
	int cnt = 0;
	for (int i = 0; i <= data.length() - m.length(); i++) {
		cout << i << endl;
		for (int j = m.length() - 1; j >= 0; j--) {
			cnt++;
			cout << data << "\n";
			for (int l = 0; l < i + j; l++)
				cout << " ";
			data[i + j] == m[j] ? cout << "+\n" : cout << "|\n";
			for (int l = 0; l < i; l++)
				cout << " ";
			cout << m << endl;
			if (data[i + j] != m[j]) {
				chk = false;
				int pass = j+1;
				int temp = 0;
				int count = 0;
				for (int k = j-1; k >= 0; k--) {
					count++;
					cout << data << "\n";
					for (int l = 0; l < i + j; l++)
						cout << " ";
					data[i + j] == m[k] ? cout << "+\n" : cout << "|\n";
					for (int l = 0; l < i + count; l++)
						cout << " ";
					cout << m << endl;
					if (data[i + j] == m[k]) temp++;
				}
				if (temp == 0) i += pass - 1;
				else if(temp == 1)i += count - 1;
				else i += pass - temp;
				break;
			}
			chk = true;
		}
		if (chk) {
			cout << "\b찾고자 하는 단어는 " << i << " ~ " << i + m.size() - 1 << "에 있습니다.\n";
			cout << "비교는 총 " << cnt << "번 했습니다." << endl;
			break;
		}
		cout << endl;
	}
	if (!chk) cout << "찾고자 하는 단어가 존재하지 않습니다.\n";
}