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


	RANDOM_ARRAY(arr, N);
	ARRAY_COPY(arr, arr2, N);
	ARRAY_COPY(arr, arr3, N);
	ARRAY_COPY(arr, arr4, N);
	ARRAY_COPY(arr, arr5, N);


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

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;


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
					if (t == j || t == j-1)
						cout << "* ";
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
				if (t == i || t == min)
					cout << "* ";
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
					if (t == j || t == j - 1)
						cout << "* ";
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
	for (int i = n/2; i > 0; i /= 2) {
		for (int j = i; j < n; j++) {
			for (int k = j - i; k >= 0; k -= i) {
				cmp++;
				if (arr[k] > arr[k+i]) {
					for (int t = 0; t < n; t++) {
						if (t == k || t == k + i)
							cout << "* ";
						else cout << "  ";
					}
					cout << endl;
					for (int t = 0; t < n; t++) {
						cout << arr[t] << " ";
					}
					cout << endl;
					cnt++;
					swap(arr[k], arr[k+i]);
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
						if (t == k || t == k + i)
							cout << "* ";
						else cout << "  ";
					}
					cout << endl;
					for (int t = 0; t < n; t++) {
						cout << arr[t] << " ";
					}
					cout << endl;
					cnt++;
					swap(arr[k], arr[k+i]);
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

/*
10
SORT1 - Bubble
				* *
3 2 1 0 5 7 9 8 6 4
			  * *
3 2 1 0 5 7 9 8 4 6
			* *
3 2 1 0 5 7 9 4 8 6
		  * *
3 2 1 0 5 7 4 9 8 6
		* *
3 2 1 0 5 4 7 9 8 6
	* *
3 2 1 0 4 5 7 9 8 6
  * *
3 2 0 1 4 5 7 9 8 6
* *
3 0 2 1 4 5 7 9 8 6
				* *
0 3 2 1 4 5 7 9 8 6
			  * *
0 3 2 1 4 5 7 9 6 8
			* *
0 3 2 1 4 5 7 6 9 8
	* *
0 3 2 1 4 5 6 7 9 8
  * *
0 3 1 2 4 5 6 7 9 8
				* *
0 1 3 2 4 5 6 7 9 8
	* *
0 1 3 2 4 5 6 7 8 9
---------------------------------
0 1 2 3 4 5 6 7 8 9
비교 : 30번, 교환 : 15번
start : 3239ms , end : 3266ms , 걸린 시간 : 27ms
SORT2 - Selection
*     *
3 2 1 0 5 7 9 8 6 4
  * *
0 2 1 3 5 7 9 8 6 4
		*         *
0 1 2 3 5 7 9 8 6 4
		  *       *
0 1 2 3 4 7 9 8 6 5
			*   *
0 1 2 3 4 5 9 8 6 7
			  *   *
0 1 2 3 4 5 6 8 9 7
				* *
0 1 2 3 4 5 6 7 9 8
---------------------------------
0 1 2 3 4 5 6 7 8 9
비교 : 45번, 교환 : 7번
start : 3267ms , end : 3290ms , 걸린 시간 : 23ms
SORT3 - Insertion
* *
3 2 1 0 5 7 9 8 6 4
  * *
2 3 1 0 5 7 9 8 6 4
* *
2 1 3 0 5 7 9 8 6 4
	* *
1 2 3 0 5 7 9 8 6 4
  * *
1 2 0 3 5 7 9 8 6 4
* *
1 0 2 3 5 7 9 8 6 4
			* *
0 1 2 3 5 7 9 8 6 4
			  * *
0 1 2 3 5 7 8 9 6 4
			* *
0 1 2 3 5 7 8 6 9 4
		  * *
0 1 2 3 5 7 6 8 9 4
				* *
0 1 2 3 5 6 7 8 9 4
			  * *
0 1 2 3 5 6 7 8 4 9
			* *
0 1 2 3 5 6 7 4 8 9
		  * *
0 1 2 3 5 6 4 7 8 9
		* *
0 1 2 3 5 4 6 7 8 9
---------------------------------
0 1 2 3 4 5 6 7 8 9
비교 : 45번, 교환 : 15번
start : 3292ms , end : 3352ms , 걸린 시간 : 60ms
SORT4 - Shell
		*         *
3 2 1 0 5 7 9 8 6 4
*   *
3 2 1 0 4 7 9 8 6 5
  *   *
1 2 3 0 4 7 9 8 6 5
			*   *
1 0 3 2 4 7 9 8 6 5
			  *   *
1 0 3 2 4 7 6 8 9 5
		  *   *
1 0 3 2 4 7 6 5 9 8
* *
1 0 3 2 4 5 6 7 9 8
	* *
0 1 3 2 4 5 6 7 9 8
				* *
0 1 2 3 4 5 6 7 9 8
---------------------------------
0 1 2 3 4 5 6 7 8 9
비교 : 70번, 교환 : 9번
start : 3354ms , end : 3392ms , 걸린 시간 : 38ms
SORT5 - Shell
		  *       *
3 2 1 0 5 7 9 8 6 4
* *
3 2 1 0 5 4 9 8 6 7
  * *
2 3 1 0 5 4 9 8 6 7
* *
2 1 3 0 5 4 9 8 6 7
	* *
1 2 3 0 5 4 9 8 6 7
  * *
1 2 0 3 5 4 9 8 6 7
* *
1 0 2 3 5 4 9 8 6 7
		* *
0 1 2 3 5 4 9 8 6 7
			* *
0 1 2 3 4 5 9 8 6 7
			  * *
0 1 2 3 4 5 8 9 6 7
			* *
0 1 2 3 4 5 8 6 9 7
				* *
0 1 2 3 4 5 6 8 9 7
			  * *
0 1 2 3 4 5 6 8 7 9
---------------------------------
0 1 2 3 4 5 6 7 8 9
비교 : 53번, 교환 : 13번
start : 3394ms , end : 3446ms , 걸린 시간 : 52ms

C:\Users\qjack\source\Algorithm\Chapter6\Debug\Chapter6.exe(21420 프로세스)이(가) 0 코드로 인해 종료되었습니다.
이 창을 닫으려면 아무 키나 누르세요.
*/