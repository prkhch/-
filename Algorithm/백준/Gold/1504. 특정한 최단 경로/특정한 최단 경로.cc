#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 10000000

vector<pair<int, int>> graph[801];
int n, e;

int dijkstra(int st, int ed) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, st));

	vector<int> dist(n + 1, INF);
	vector<int> visited(n + 1, 0);

	while (!pq.empty()) {
		int nowN = pq.top().second;
		int nowCost = pq.top().first;
		pq.pop();

		if (nowN == ed) {
			return nowCost;
		}

		for (int i = 0; i < graph[nowN].size(); i++) {
			int nextN = graph[nowN][i].second;
			int nextCost = graph[nowN][i].first;

			if (dist[nextN] > nextCost + nowCost) {
				dist[nextN] = nextCost + nowCost;
				pq.push(make_pair(dist[nextN], nextN));
			}
		}
	}

	return INF;

}

int main() {
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
	}

	int v1, v2;
	cin >> v1 >> v2;

	int res1 = 0;
	res1 += dijkstra(1, v1);
	res1 += dijkstra(v1, v2);
	res1 += dijkstra(v2, n);

	int res2 = 0;
	res2 += dijkstra(1, v2);
	res2 += dijkstra(v2, v1);
	res2 += dijkstra(v1, n);

	int res = min(res1, res2);

	if (res >= INF) {
		cout << "-1";
	}
	else {
		cout << res;
	}

}