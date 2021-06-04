#include <iostream>
#include "StopWatch.h"
#include <time.h>

using namespace std;

void RANDOM_ARRAY(int arr[], int n);
void ARRAY_COPY(int arr[], int arr2[], int n);
void SORT1(int arr[], int n); // Bubble
void SORT2(int arr[], int n); // selection
void SORT3(int arr[], int n); // insertion

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
	int* arr3 = new int[N];

	RANDOM_ARRAY(arr, N);
	ARRAY_COPY(arr, arr2, N);
	ARRAY_COPY(arr, arr3, N);

	cout << "SORT1 - Bubble" << endl;
	T.start();
	SORT1(arr, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	cout << "SORT2 - Selection" << endl;
	T.start();
	SORT2(arr2, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	cout << "SORT3 - Insertion" << endl;
	T.start();
	SORT3(arr3, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	return 0;
}
void SORT1(int arr[], int n) {
	int cmp = 0, cnt = 0;
	int i = 0;
	while (i < n - 1) {
		int last = n - 1;
		for (int j = 0; j < n; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;
		for (int j = n - 1; j > i; j--) {
			cmp++;
			if (arr[j] < arr[j - 1]) {
				cnt++;
				swap(arr[j], arr[j - 1]);
				last = j;
			}
		}
		i = last;
	}
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	cout << "비교 : " << cmp << "번, 교환 : " << cnt << "번\n";
}
void SORT2(int arr[], int n) { // 모두 탐색한 후 젤 작은 값을 맨 앞으로 보낸 후 그 다음 위치부터 반복
	int cmp = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = 0; j < n; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;
		for (int j = i + 1; j < n; j++) {
			cmp++;
			if (arr[j] < arr[min]) {
				min = j;
				cnt++;
			}
		}
		swap(arr[i], arr[min]);
	}
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	cout << "비교 : " << cmp << "번, 교환 : " << cnt << "번\n";
}
void SORT3(int arr[], int n) {
	int cmp = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		int tmp = arr[i];
		int j;
		for (j = 0; j < n; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;
		for (j = i; j > 0 && arr[j-1] > tmp; j--) {
			cmp++;
			arr[j] = arr[j - 1];
			cnt++;
		}
		arr[j] = tmp;
	}
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	cout << "비교 : " << cmp << "번, 교환 : " << cnt << "번\n";
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