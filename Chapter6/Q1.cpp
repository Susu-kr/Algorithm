#include <iostream>
#include <vector>

using namespace std;

void solution(int N);


int Relation[101][101];
int TotalFriend[101][101];

int main() {
	int N;
	cout << "전체 사람 수 : ";
	cin >> N;
	while (N > 100 || N < 2) {
		cout << "전체 사람은 2명 이상 100명 이하 입니다." << endl;
		cout << "전체 사람 수 : ";
		cin >> N;
	}
	solution(N);
	return 0;
}

void solution(int N) {
	vector <vector<int>> v(N+1, vector<int>(1, 0));
	int has_f, f;
	for (int i = 1; i <= N; i++) {
		int min = 0, max = N-1; // 최소 친구 수, 최대 친구 수
		for (int j = 1; j <= N; j++) {
			if (Relation[j][i] == 1) min++; // 자신을 친구로 하는 사람이 존재하면 최소 친구 수 증가
			else if (Relation[j][i] == -1) max--; // 자신을 친구로 하지 않은 사람이 존재하면 최대 친구 수 감소
		}
		if (i == 1) min++;
		cout << i << "번 사용자의 친구 수 (" << min << " ~ " << max << ") : ";
		cin >> has_f;
		if (has_f < min || has_f > max) {
			i--;
			cout << "친구 수가 올바르지 않습니다." << endl;
			continue;
		}
		int cnt = 1; // 서로 친구인 사람 출력
		for (int k = 1; k <= N; k++) {
			if (Relation[k][i] == 1) {
				Relation[i][k] = TotalFriend[i][k] = 1;
				cout << cnt << "번째 친구 : " << k << endl;
				cnt++;
			}
		}
		if (cnt <= has_f) { // 입력한 친구 수가 현재까지 나온 친구 수 보다 작은 경우
			for (int j = cnt; j <= has_f; j++) {
				cout << j << "번째 친구 : ";
				cin >> f;
				if (f == i || f > N || Relation[f][i] == -1) { // 입력한 친구가 자기 자신 or 존재하지 않는 친구 or 친구라고 하지 않은 사람일 경우
					j--;
					cout << "친구관계가 틀렸습니다. 다시 입력하세요." << endl;
					continue;
				}

				if (Relation[i][f] == 0) Relation[i][f] = TotalFriend[i][f] = 1;
				else { // 
					cout << "이미 친구관계 입니다. 다른 사용자를 입력하세요." << endl;
					j--;
				}
			}
		}
		cout << endl;
		for (int j = 1; j <= N; j++) { // 한 사람의 친구 관계가 끝나면 친구가 아니라고 했던 사람들을 -1로 변경
			if (Relation[i][j] == 0) Relation[i][j] = TotalFriend[i][j] = -1;
		}
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
	cout << "친구-친구" << endl;
	for (int i = 1; i <= N; i++) {
		cout << i << "번 사용자의 친구 : ";
		for (int j = 1; j <= N; j++) {
			if (Relation[i][j] == 1) cout << j << " ";
		}
		cout << endl;
	}
	cout << "========================================" << endl;
	cout << "친구-친구-친구" << endl;
	for (int i = 1; i <= N; i++) {
		cout << i << "번 사용자의 친구 : ";
		for (int j = 1; j <= N; j++) {
			if (TotalFriend[i][j] == 1) cout << j << " ";
		}
		cout << endl;
	}
}