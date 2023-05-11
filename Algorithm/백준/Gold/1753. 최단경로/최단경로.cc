#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 100000000
using namespace std;

int main() {
	
	int v, e, k;
	cin >> v >> e;
	cin >> k;

	vector<pair<int,int>> graph[20001];
	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back(make_pair(w, b));
	}

	vector<int> dist(v + 1, INF);
	int visited[20001];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0,k));
	dist[k] = 0;

	while (!pq.empty()) {
		int nowW = pq.top().first; // 현재 가중치 weight
		int	nowN = pq.top().second; pq.pop(); // 현재 노드

	/*	if (visited[nowN] == 1) continue;
		visited[nowN] = 1;*/

		for (int i = 0; i < graph[nowN].size(); i++) {
			int nextW = graph[nowN][i].first;
			int nextN = graph[nowN][i].second;

			if (dist[nextN] > nowW + nextW) {
				dist[nextN] = nowW + nextW;
				pq.push(make_pair(dist[nextN], nextN));
			}
		}

	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}

	}

}