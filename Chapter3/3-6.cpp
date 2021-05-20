#include <iostream>

using namespace std;

int int_cmpr(const int *a, const int *b);

int main() {
	int i, nx, ky;
	int *x;
	int *p;
	cout << "bsearch 함수를 사용하여 검색" << endl;
	cout << "요소 개수 : ";
	cin >> nx;
	x = (int *)calloc(nx, sizeof(int));

	cout << "내림차순으로 입력하세요" << endl;
	cout << "x[0] : ";
	cin >> x[0];
	for (i = 1; i < nx; i++) {
		do {
			cout << "x[" << i << "] : ";
			cin >> x[i];
		} while (x[i] > x[i - 1]);
	}

	cout << "검색값 : ";
	cin >> ky;

	p = (int *)bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmpr);
	if (p == NULL) cout << "검색에 실패했습니다." << endl;
	else cout << ky << "는 x[" << (int)(p - x) << "]에 있습니다." << endl;
	delete[] x;
	return 0;
}

int int_cmpr(const int *a, const int *b) {
	if (*a < *b) return 1;
	else if (*a > *b) return -1;
	else return 0;
}