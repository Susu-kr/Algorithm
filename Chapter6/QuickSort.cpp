#include <iostream>
#include "StopWatch.h"
#include <time.h>

using namespace std;

void RANDOM_ARRAY(int arr[], int n);
void ARRAY_COPY(int arr[], int arr2[], int n);
void SORT1(int arr[], int n); // Bubble
void SORT2(int arr[], int n); // selection
void SORT3(int arr[], int n); // insertion
void SORT4(int arr[], int n); // Shell
void SORT5(int arr[], int n); // Shell
void SORT6(int arr[], int n); // Quick
void quick(int arr[], int l, int r, int &cmp, int & cnt, int n);

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
	int* arr4 = new int[N];
	int* arr5 = new int[N];
	int* arr6 = new int[N];


	RANDOM_ARRAY(arr, N);
	ARRAY_COPY(arr, arr2, N);
	ARRAY_COPY(arr, arr3, N);
	ARRAY_COPY(arr, arr4, N);
	ARRAY_COPY(arr, arr5, N);
	ARRAY_COPY(arr, arr6, N);

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

	cout << "SORT4 - Shell" << endl;
	T.start();
	SORT4(arr4, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	cout << "SORT5 - Shell" << endl;
	T.start();
	SORT5(arr5, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	cout << "SORT6 - Quick" << endl;
	T.start();
	SORT6(arr6, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;

	return 0;
}
void SORT1(int arr[], int n) {
	int cmp = 0, cnt = 0;
	int i = 0;
	while (i < n - 1) {
		int last = n - 1;
		for (int j = n - 1; j > i; j--) {
			cmp++;
			if (arr[j] < arr[j - 1]) {
				for (int t = 0; t < n; t++) {
					if (t == j) cout << "> ";
					else if(t == j - 1) cout << "< ";
					else cout << "  ";
				}
				cout << endl;
				for (int j = 0; j < n; j++) {
					cout << arr[j] << " ";
				}
				cout << endl;
				cnt++;
				swap(arr[j], arr[j - 1]);
				last = j;
			}
		}
		i = last;
	}
	cout << "---------------------------------" << endl;
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
		for (int j = i + 1; j < n; j++) {
			cmp++;
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			cnt++;
			for (int t = 0; t < n; t++) {
				if (t == i) cout << "< ";
				else if(t == min) cout << "> ";
				else cout << "  ";
			}
			cout << endl;
			for (int j = 0; j < n; j++) {
				cout << arr[j] << " ";
			}
			cout << endl;
		}
		swap(arr[i], arr[min]);
	}
	cout << "---------------------------------" << endl;
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	cout << "비교 : " << cmp << "번, 교환 : " << cnt << "번\n";
}
void SORT3(int arr[], int n) {
	int cmp = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0; j--) {
			cmp++;
			if (arr[j - 1] > arr[j]) {
				for (int t = 0; t < n; t++) {
					if (t == j) cout << "> ";
					else if (t == j - 1) cout << "< ";
					else cout << "  ";
				}
				cout << endl;
				for (int t = 0; t < n; t++) {
					cout << arr[t] << " ";
				}
				cnt++;
				swap(arr[j - 1], arr[j]);
				cout << endl;
			}
		}
	}
	cout << "---------------------------------" << endl;
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	cout << "비교 : " << cmp << "번, 교환 : " << cnt << "번\n";
}

void SORT4(int arr[], int n) {
	int cmp = 0, cnt = 0;
	for (int i = n / 2; i > 0; i /= 2) {
		for (int j = i; j < n; j++) {
			for (int k = j - i; k >= 0; k -= i) {
				cmp++;
				if (arr[k] > arr[k + i]) {
					for (int t = 0; t < n; t++) {
						if (t == k) cout << "< ";
						else if (t == k + i) cout << "> ";
						else cout << "  ";
					}
					cout << endl;
					for (int t = 0; t < n; t++) {
						cout << arr[t] << " ";
					}
					cout << endl;
					cnt++;
					swap(arr[k], arr[k + i]);
				}
			}
		}
	}
	cout << "---------------------------------" << endl;
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	cout << "비교 : " << cmp << "번, 교환 : " << cnt << "번\n";
}

void SORT5(int arr[], int n) {
	int cmp = 0, cnt = 0;
	int i = 1;
	while (i * 9 < n) {
		i = i * 3 + 1;
	}
	for (; i > 0; i /= 3) {
		for (int j = i; j < n; j++) {
			for (int k = j - i; k >= 0; k -= i) {
				cmp++;
				if (arr[k] > arr[k + i]) {
					for (int t = 0; t < n; t++) {
						if (t == k) cout << "< ";
						else if (t == k + i) cout << "> ";
						else cout << "  ";
					}
					cout << endl;
					for (int t = 0; t < n; t++) {
						cout << arr[t] << " ";
					}
					cout << endl;
					cnt++;
					swap(arr[k], arr[k + i]);
				}
			}
		}
	}
	cout << "---------------------------------" << endl;
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	cout << "비교 : " << cmp << "번, 교환 : " << cnt << "번\n";
}

void SORT6(int arr[], int n) {
	int cmp = 0, cnt = 0;
	quick(arr, 0, n - 1, cmp, cnt, n);
	cout << "---------------------------------" << endl;
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	cout << "비교 : " << cmp << "번, 교환 : " << cnt << "번\n";
}
void quick(int arr[], int l, int r, int & cmp, int & cnt, int n) {
	int left = l;
	int right = r;
	int mid;
	if((left + right) % 2 == 0) mid = arr[(left + right) / 2];
	else mid = arr[((left + right) / 2) + 1];
	do{
		while (arr[left] < mid) left++;
		while (arr[right] > mid) right--;
		cmp++;
		for (int t = 0; t < n; t++) {
			if (t == left) cout << "< ";
			else if (t == right) cout << "> ";
			else cout << "  ";
		}
		cout << endl;
		for (int t = 0; t < n; t++) {
			cout << arr[t] << " ";
		}
		cout << endl;
		if (left <= right) {
			cnt++;
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	} while (left <= right);

	if (l < right) {
		quick(arr, l, right, cmp, cnt, n);
	}
	if (left < r) {
		quick(arr, left, r, cmp, cnt, n);
	}
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
