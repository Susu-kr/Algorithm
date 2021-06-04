#include <iostream>
#include "StopWatch.h"
#include <time.h>

using namespace std;

void RANDOM_ARRAY(int arr[], int n);
void ARRAY_COPY(int arr[], int arr2[], int n);
void SORT1(int arr[], int n);
void SORT2(int arr[], int n);

void Swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
using namespace std;

StopWatch T;

int main() {
	srand(unsigned int(time(NULL)));
	int N;
	cin >> N;
	int* arr = new int[N];
	int* arr2 = new int[N];
	RANDOM_ARRAY(arr, N);
	ARRAY_COPY(arr, arr2, N);

	cout << "SORT1" << endl;
	T.start();
	SORT1(arr, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , �ɸ� �ð� : " << T.getElapsedTime() << "ms" << endl;

	cout << "SORT2" << endl;
	T.start();
	SORT2(arr2, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , �ɸ� �ð� : " << T.getElapsedTime() << "ms" << endl;

	delete[] arr;
	delete[] arr2;
	return 0;
}

void SORT1(int arr[], int n) { // ��� Ž���� �� �� ���� ���� �� ������ ���� �� �� ���� ��ġ���� �ݺ�
	int cmp = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i+1; j < n; j++) {
			cmp++;
			if (arr[j] < arr[min]) {
				min = j;
				cnt++;
			}
		}
		swap(arr[i], arr[min]);
	}
	cout << "�� : " << cmp << "��, ��ȯ : " << cnt << "��\n";
}
void SORT2(int arr[], int n) { // ó������ ������ ���ϸ鼭 ���� ���������� ����
	int cmp = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cmp++;
			if (arr[j] < arr[i]) {
				cnt++;
				swap(arr[i], arr[j]);
			}
		}
	}
	cout << "�� : " << cmp << "��, ��ȯ : " << cnt << "��\n";
}

void RANDOM_ARRAY(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		int t = rand() % n;
		bool chk = false;
		for (int j = 0; j < i; j++) {
			if (arr[j] == t) {
				i--;
				chk = true;
				break;
			}
		}
		if (!chk) {
			arr[i] = t;
		}
	}
}
void ARRAY_COPY(int arr[], int arr2[], int n) {
	for (int i = 0; i < n; i++) {
		arr2[i] = arr[i];
	}
}