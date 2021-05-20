#include <iostream>

using namespace std;

int int_cmp(const int *a, const int *b);

int main() {
	int i, nx, ky;
	int *x;
	int *p;
	cout << "bsearch 함수를 사용하여 검색" << endl;
	cout << "요소 개수 : ";
	cin >> nx;
	x = (int *)calloc(nx, sizeof(int));
	cout << "오름차순으로 입력하세요" << endl;
	cout << "x[0] : ";
	cin >> x[0];
	for (i = 1; i < nx; i++) {
		do {
			cout << "x[" << i << "] : ";
			cin >> x[i];
		} while (x[i] < x[i - 1]);
	}
	cout << "검색값 : ";
	cin >> ky;
	int t = nx;
	while (1) {
		p = (int *)bsearch(&ky, x, t--, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
		if (p == NULL) {
			cout << ky << "는 x[" << t << "]에 있습니다." << endl;
			break;
		}
	}
	delete[] x;
	return 0;
}

int int_cmp(const int *a, const int *b) {
	if (*a < *b) return -1;
	else if (*a > *b) return 1;
	else return 0;
}