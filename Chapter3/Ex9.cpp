#include <iostream>

using namespace std;

int int_cmp(const int *a, const int *b);
void *bsearchx(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));

int main() {
	int i, nx, ky;
	int *x;
	int *p;
	cout << "bsearch �Լ��� ����Ͽ� �˻�" << endl;
	cout << "��� ���� : ";
	cin >> nx;
	x = (int *)calloc(nx, sizeof(int));
	cout << "������������ �Է��ϼ���" << endl;
	cout << "x[0] : ";
	cin >> x[0];
	for (i = 1; i < nx; i++) {
		do {
			cout << "x[" << i << "] : ";
			cin >> x[i];
		} while (x[i] < x[i - 1]);
	}
	cout << "�˻��� : ";
	cin >> ky;
	p = (int *)bsearchx(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
	if(p == NULL) cout << "�˻��� �����߽��ϴ�." << endl;
	else cout << ky << "�� x[" << (int) (p - x) << "]�� �ֽ��ϴ�." << endl;
	delete[] x;
	return 0;
}

int int_cmp(const int *a, const int *b) {
	if (*a < *b) return -1;
	else if (*a > *b) return 1;
	else return 0;
}
void *bsearchx(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void*, const void*)) {
	int t = nmemb;
	int* p;
	while (1) {
		p = (int *)bsearch(key, base, t, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
		if (p == NULL) {
			if (t + 1 <= nmemb) {
				p = (int *)bsearch(key, base, ++t, sizeof(int), (int(*)(const void*, const void*)) int_cmp);
			}
			return p;
		}
		t--;
	}
}