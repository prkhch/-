#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 100000000
using namespace std;

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	vector<pair<int,int>> graph[1001];
	vector<int> dist(n + 1, INF);
	int visited[1001] = { 0, };
	

	int st, ed, cost;
	for (int i = 0; i < m; i++) {
		cin >> st >> ed >> cost;
		graph[st].push_back(make_pair(cost, ed));
	}

	cin >> st >> ed;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, st));
	
	while (!pq.empty()) {
		int nowCost = pq.top().first; 
		int nowNode = pq.top().second;
		pq.pop();

		if (visited[nowNode] == 1) continue; 
		visited[nowNode] = 1;

		for (int i = 0; i < graph[nowNode].size(); i++) {
			int nextCost = graph[nowNode][i].first;
			int nextNode = graph[nowNode][i].second;

			if (dist[nextNode] > nowCost + nextCost) {
				dist[nextNode] = nowCost + nextCost;
				pq.push(make_pair(dist[nextNode], nextNode));
			}
		}

	}

	cout << dist[ed];

}