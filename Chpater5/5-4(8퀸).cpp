#include <iostream>

using namespace std;

void print();
void set(int i);

const int SIZE = 8;
bool flag[SIZE];
bool flag1[SIZE * 2 - 1];
bool flag2[SIZE * 2 - 1];
int pos[SIZE];
int cnt = 0;

int main() {
	set(0);
	return 0;
}

void print() {
	cnt++;
	cout << cnt << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (j == pos[i]) cout << "бс";
			else cout << "бр";
		}
		cout << endl;
	}
	cout << endl;
}
void set(int i) {
	int j;
	for (j = 0; j < SIZE; j++) {
		if (!flag[j] && !flag1[i + j] && !flag2[i - j + SIZE-1]) {
			pos[i] = j;
			if (i == SIZE-1)print();
			else {
				flag[j] = flag1[i + j] = flag2[i - j + SIZE-1] = true;
				set(i + 1);
				flag[j] = flag1[i + j] = flag2[i - j + SIZE-1] = false;
			}
		}
	}
}