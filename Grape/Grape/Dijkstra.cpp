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

// ����� ����(N), ������ ����(M), ���� ��� ��ȣ(Start)
// ����� ������ �ִ� 100,000����� ����
int n, m, start;

vector<pair<int, int> > graph[100001]; // �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� �迭
int d[100001]; // �ִ� �Ÿ� ���̺� �����

void Dijkstra(int start, int n)
{
	priority_queue<pair<int, int>> PQ; // �Ÿ�, ��� �ε���
	PQ.push({ 0, start }); // ���� ���� �������� �ִ� ��δ� 0
	d[start] = 0;

	while (!PQ.empty())
	{
		int dist = -PQ.top().first; // ���� �������� ���
		int now = PQ.top().second; // ���� ���
		PQ.pop();
		if (d[now] < dist) // �̹� �ִܰ�θ� üũ�� ����� ��� �н�
			continue;
		for (int i = 0; i < graph[now].size(); i++)
		{
			// ���İ��� ����� ����� ��� (���� �������� ��� + �������)
			int cost = dist + graph[now][i].second;
			// ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����
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

	// ��� ���� ������ �Է¹ޱ�
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		// u ---- w -----> v
		graph[u].push_back({ v, w });
	}

	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	fill(d, d + 100001, INT_MAX);

	// ���ͽ�Ʈ�� �˰����� ����
	Dijkstra(start, n);

	// ��� ���� ���� ���� �ִ� �Ÿ��� ���
	for (int i = 1; i <= n; i++)
	{
		// ������ �� ���� ���, ����(INFINITY)�̶�� ���
		if (d[i] == INT_MAX) {
			cout << "INFINITY" << '\n';
		}
		// ������ �� �ִ� ��� �Ÿ��� ���
		else {
			cout << 1 << " -> " << i << " : " << d[i] << '\n';
		}
	}
	return 0;
}
