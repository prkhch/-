#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 100000000
using namespace std;

int main() {

	int n, m, x; // n명, m개의 도로, x번 마을
	cin >> n >> m >> x;

	vector<pair<int, int>> graph[1001];
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		graph[a].push_back(make_pair(t, b));
	}

	vector<int> result(n+1,0);

	// x번으로 가는 비용
	for (int i = 1; i <= n; i++) {
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> dist(n + 1, INF);
		dist[i] = 0;
		pq.push(make_pair(0, i));

		while (!pq.empty()) {
			int nowTime = pq.top().first;
			int nowX = pq.top().second; pq.pop();

			if (nowX == x) { 
				result[i] = nowTime;
				break; 
			}

			for (int i = 0; i < graph[nowX].size(); i++) {
				int nextX = graph[nowX][i].second;
				int nextTime = graph[nowX][i].first;

				if (dist[nextX] > nowTime + nextTime) {
					dist[nextX] = nowTime + nextTime;
					pq.push(make_pair(dist[nextX], nextX));
				}
			}
		}

	}

	// x번에서 출발하는 비용 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(n + 1, INF);
	dist[x] = 0;
	pq.push(make_pair(0, x));

	while (!pq.empty()) {
		int nowTime = pq.top().first;
		int nowX = pq.top().second; pq.pop();

		for (int i = 0; i < graph[nowX].size(); i++) {
			int nextTime = graph[nowX][i].first;
			int nextX = graph[nowX][i].second;

			if (dist[nextX] > nowTime + nextTime) {
				dist[nextX] = nowTime + nextTime;
				pq.push(make_pair(dist[nextX], nextX));
			}
		}

	}

	// 가는비용 + 오는비용 합치기
	int maxTime = 0;
	for (int i = 1; i <= n; i++) {
		result[i] += dist[i];
		if (maxTime < result[i]) {
			maxTime = result[i];
		}
	}

	cout << maxTime;

}