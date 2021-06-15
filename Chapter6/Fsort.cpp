#include <iostream>
#include "StopWatch.h"
#include <time.h>

using namespace std;

void RANDOM_ARRAY(int arr[], int n);
void ARRAY_COPY(int *arr, int* arr2, int n);
void SORT1(int arr[], int n); // Bubble
void SORT2(int arr[], int n); // selection
void SORT3(int arr[], int n); // insertion
void SORT4(int arr[], int n); // Shell
void SORT5(int arr[], int n); // Shell
void SORT6(int arr[], int n); // Quick
void quick(int arr[], int l, int r, int &cmp, int & cnt, int n);
void SORT7(int arr[], int l, int r, int n); // Merge
void merge(int arr[], int l, int m, int r, int n);
void SORT8(int arr[], int n); // Heap
void Build_Heap(int arr[], int n);
void Heapify(int arr[], int current, int n, int size);
void SORT9(int arr[], int n, int max); // Fsort (도수정렬)


void Swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
using namespace std;

StopWatch T;

int* sorted;

class ARR {
private:
	int *arr;
	int size;
public:
	ARR(int s) {
		arr = new int[s];
		size = s;
		Randomize();
	}
	~ARR() { if (arr != NULL) delete[] arr; }
	int GetSize() const { return size; }
	int* GetArr() const { return arr; }
	void Randomize() {
		for (int i = 0; i < size; i++)
		{
			int t = rand() % size;
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
	void print() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	srand(unsigned int(time(NULL)));
	int N;
	cin >> N;
	ARR arr(N);
	int* tmp = new int[N];
	sorted = new int[N];

	ARRAY_COPY(tmp, arr.GetArr(), arr.GetSize());
	cout << "SORT1 - Bubble" << endl;
	T.start();
	SORT1(tmp, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	ARRAY_COPY(tmp, arr.GetArr(), arr.GetSize());
	cout << "SORT2 - Selection" << endl;
	T.start();
	SORT2(tmp, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	ARRAY_COPY(tmp, arr.GetArr(), arr.GetSize());
	cout << "SORT3 - Insertion" << endl;
	T.start();
	SORT3(tmp, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	ARRAY_COPY(tmp, arr.GetArr(), arr.GetSize());
	cout << "SORT4 - Shell" << endl;
	T.start();
	SORT4(tmp, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	ARRAY_COPY(tmp, arr.GetArr(), arr.GetSize());
	cout << "SORT5 - Shell" << endl;
	T.start();
	SORT5(tmp, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	ARRAY_COPY(tmp, arr.GetArr(), arr.GetSize());
	cout << "SORT6 - Quick" << endl;
	T.start();
	SORT6(tmp, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	ARRAY_COPY(tmp, arr.GetArr(), arr.GetSize());
	cout << "SORT7 - Merge" << endl;
	T.start();
	SORT7(tmp, 0, N - 1, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	ARRAY_COPY(tmp, arr.GetArr(), arr.GetSize());
	cout << "SORT8 - Heap" << endl;
	T.start();
	SORT8(tmp, N);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	int * F = new int[N];
	cout << "SORT9 - Fsort" << endl;
	int max = 0;

	for (int i = 0; i < N; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}
		int num = rand() % 100;
		F[i] = num;
		cout << F[i] << " ";
		if (max < F[i]) max = F[i];
	}
	cout << endl;
	T.start();
	SORT9(F, N, max);
	T.stop();
	cout << "start : " << T.getStartTime() << "ms , end : " << T.getEndTime() << "ms , 걸린 시간 : " << T.getElapsedTime() << "ms" << endl;

	delete[] tmp;
	delete[] F;
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
					else if (t == j - 1) cout << "< ";
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
				else if (t == min) cout << "> ";
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
	if ((left + right) % 2 == 0) mid = arr[(left + right) / 2];
	else mid = arr[((left + right) / 2) + 1];
	do {
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

int t_cmp = 0;
void SORT7(int arr[], int l, int r, int n) {
	int mid = 0;
	if (l < r) {
		mid = (l + r) / 2;
		for (int t = 0; t <= n; t++) {
			if (t >= l && t <= r) cout << arr[t] << " ";
			else cout << "  ";
		}
		cout << endl;
		SORT7(arr, l, mid, n);
		SORT7(arr, mid + 1, r, n);
		merge(arr, l, mid, r, n);
		for (int t = 0; t <= n; t++) {
			if (t >= l && t <= r) cout << arr[t] << " ";
			else cout << "  ";
		}
		cout << endl;
	}
	if (l + r == n - 1) {
		cout << "---------------------------------" << endl;
		for (int j = 0; j < n; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;
		cout << "비교 : " << t_cmp << "번\n";
	}
}
void merge(int arr[], int l, int m, int r, int n) {
	int left = l;
	int right = m + 1;
	int i = left;
	while (left <= m && right <= r) {
		t_cmp++;
		if (arr[left] <= arr[right]) sorted[i++] = arr[left++];
		else sorted[i++] = arr[right++];
	}
	if (left > m) {
		for (int k = right; k <= r; k++) {
			sorted[i++] = arr[k];
		}
	}
	else {
		for (int k = left; k <= r; k++) {
			sorted[i++] = arr[k];
		}
	}
	for (int k = l; k <= r; k++) {
		arr[k] = sorted[k];
	}
}

void SORT8(int arr[], int n) {
	Build_Heap(arr, n);
	for (int i = n - 1; i >= 1; i--) {
		// Max_Heap 상태
		for (int j = 0; j < n; j++) {
			if (j == 0) cout << "R ";
			else if (j == i) cout << "* ";
			else cout << "  ";
		}
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;
		// 오름차순 정렬
		swap(arr[i], arr[0]);
		Heapify(arr, 0, i, n);
		// 배열, Root, 정렬안된 마지막 자식, 전체 크기
	}
	cout << "---------------------------------" << endl;
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
}

void Build_Heap(int arr[], int n) { // 최대힙
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	cout << "---------------------------------" << endl;
	cout << "Build_Max_Heap" << endl;
	for (int cur = 1; cur < n; cur++) { // 0 : root, 1 ~ : child
		while (cur > 0) { // Root가 아닐때까지
			int parent = (cur - 1) / 2; // 부모 인덱스 설정
			if (arr[cur] > arr[parent]) { // 자식 > 부모
				for (int j = 0; j < n; j++) {
					if (j == parent) cout << "P ";
					else if (j == cur) cout << "C ";
					else cout << "  ";
				}
				cout << endl;
				for (int j = 0; j < n; j++) {
					cout << arr[j] << " ";
				}
				cout << endl;
				swap(arr[cur], arr[parent]); // swap
				cur = parent; // 인덱스 변경
			}
			else break;
		}
	}
	cout << "---------------------------------" << endl;

}
void Heapify(int arr[], int current, int n, int size) {
	int cur = current;
	int left_child = (current * 2) + 1;
	int right_child = (current * 2) + 2;
	if ((left_child < n) && (arr[left_child] > arr[cur]))
		cur = left_child;
	if ((right_child < n) && (arr[right_child] > arr[cur]))
		cur = right_child;
	for (int j = 0; j < size; j++) {
		if (j == current) cout << "P ";
		else if (j == cur) cout << "C ";
		else cout << "  ";
	}
	cout << endl;
	for (int j = 0; j < size; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	if (cur != current) { // 부모가 자식보다 작은경우
		swap(arr[cur], arr[current]);
		Heapify(arr, cur, n, size);
	}
}

void SORT9(int arr[], int n, int max) {
	int * temp = new int[max + 1];
	memset(temp, 0, sizeof(int) * (max+1));
	for (int i = 0; i < n; i++) {
		temp[arr[i]]++;
	}
	int cnt = 0;
	for (int i = 0; i < max + 1; i++) {
		if (temp[i] != 0) {
			while (temp[i] != 0) {
				arr[cnt] = i;
				temp[i]--;
				cout << "arr[" << cnt << "] : " << arr[cnt] << ", temp[" << i << "] : " << temp[i] << endl;
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] temp;
}

void ARRAY_COPY(int * arr, int* arr2, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = arr2[i];
	}
}
