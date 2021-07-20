#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
8 10 1
1 2 2
1 6 3
2 3 4
2 4 1
3 5 3
4 5 3
4 7 2
5 8 4
6 7 6
7 8 4
*/

// 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
// 노드의 개수는 최대 100,000개라고 가정
int n, m, start;

vector<pair<int, int> > graph[100001]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
int d[100001]; // 최단 거리 테이블 만들기

void Dijkstra(int start, int n)
{
	priority_queue<pair<int, int>> PQ; // 거리, 노드 인덱스
	PQ.push({ 0, start }); // 시작 노드로 가기위한 최단 경로는 0
	d[start] = 0;

	while (!PQ.empty())
	{
		int dist = -PQ.top().first; // 현재 노드까지의 비용
		int now = PQ.top().second; // 현재 노드
		PQ.pop();
		if (d[now] < dist) // 이미 최단경로를 체크한 노드인 경우 패스
			continue;
		for (int i = 0; i < graph[now].size(); i++)
		{
			// 거쳐가는 노드의 비용을 계산 (현재 노드까지의 비용 + 다음노드)
			int cost = dist + graph[now][i].second;
			// 비용이 더 작다면 최단경로 테이블 값을 갱신
			if (cost < d[graph[now][i].first])
			{
				d[graph[now][i].first] = cost;
				PQ.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main() {

	cin >> n >> m >> start;

	// 모든 간선 정보를 입력받기
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		// u ---- w -----> v
		graph[u].push_back({ v, w });
	}

	// 최단 거리 테이블을 모두 무한으로 초기화
	fill(d, d + 100001, INT_MAX);

	// 다익스트라 알고리즘을 수행
	Dijkstra(start, n);

	// 모든 노드로 가기 위한 최단 거리를 출력
	for (int i = 1; i <= n; i++)
	{
		// 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
		if (d[i] == INT_MAX) {
			cout << "INFINITY" << '\n';
		}
		// 도달할 수 있는 경우 거리를 출력
		else {
			cout << 1 << " -> " << i << " : " << d[i] << '\n';
		}
	}
	return 0;
}
