#include <iostream>
#include "StopWatch.h"
#include <vector>
#include <time.h>

using namespace std;

void SORT1(int arr[], int n);
void SORT2(int arr[], int n);
void SORT3(int arr[], int n);

void Swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
using namespace std;

void solution(int N);

int Relation[101][101];
int TotalFriend[101][101];
StopWatch T;

int main() {
	T.start();
	srand(unsigned int(time(NULL)));
	solution(100);
	T.stop();
	cout << "Friend" << endl;
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	const int N = 10000;
	int* arr = new int[N];
	int* arr2 = new int[N];
	int* arr3 = new int[N];
	for (int i = 0; i < N; i++)
	{
		int t = rand() % N;
		arr[i] = t;
		arr2[i] = t;
		arr3[i] = t;
	}
	cout << "SORT1" << endl;
	T.start();
	SORT1(arr, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	cout << "SORT2" << endl;
	T.start();
	SORT2(arr2, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	cout << "SORT3" << endl;
	T.start();
	SORT3(arr3, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	return 0;
}

void solution(int N) {
	int cnt = 1;
	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			cout << i << "번 사용자의 친구 수 : 1\n";
			cout << 1 << "번째 친구 : " << cnt + 1 << endl;
			Relation[i][cnt + 1] = TotalFriend[i][cnt+1] = 1;
		}
		else if (i == N) {
			cout << i << "번 사용자의 친구 수 : 1\n";
			cout << 1 << "번째 친구 : " << cnt - 1 << endl;
			Relation[i][cnt - 1] = TotalFriend[i][cnt - 1] = 1;
		}
		else {
			cout << i << "번 사용자의 친구 수 : 2\n";
			cout << 1 << "번째 친구 : " << cnt-1 << endl;
			Relation[i][cnt - 1] = TotalFriend[i][cnt - 1] = 1;
			cout << 2 << "번째 친구 : " << cnt+1 << endl;
			Relation[i][cnt+1] = TotalFriend[i][cnt+1] = 1;
		}
		cnt++;
		cout << endl;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Relation[i][j] == 1) {
				for (int k = 1; k <= N; k++) {
					if (Relation[j][k] == 1 && i != k)
						TotalFriend[i][k] = 1;
				}
			}
		}
	}

}

void SORT1(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j-1], arr[j]);
			}
		}
	}
}

void SORT2(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int t_c = 0;
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				t_c++;
				swap(arr[j-1], arr[j]);
			}
		}
		if (t_c == 0) break;
	}
}

void SORT3(int arr[], int n) {
	int i = 0;
	while (i < n - 1) {
		int last = n - 1;
		for (int j = n-1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				last = j;
			}
		}
		i = last;
	}
}