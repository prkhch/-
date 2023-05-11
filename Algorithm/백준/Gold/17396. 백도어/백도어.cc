#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define INF 10000000000000 // 최댓값 INF 정의
#define ll unsigned long long // ll 타입 ll 정의
int n, m, ward[100001]; // 정점, 간선의 수

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	// 시야 세팅
	for (int i = 0; i < n; i++) {
		cin >> ward[i];
	}
	ward[n - 1] = 0; // 마지막 분기점은 시야 보임

	// 간선 세팅
	int a, b, t;
	vector<vector<pair<ll, int>>> edges;
	edges.resize(100001); // 크기 설정 안하니 오류..
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> t;
		if (ward[a] == 1 || ward[b] == 1) { continue; } // 시야 걸림
		edges[a].push_back({t,b});
		edges[b].push_back({t,a});
	}

	// 비용 세팅
	vector <ll> dist;
	dist.resize(100001, INF);

	// 우선순위 큐
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	// ll:시간, int : 노드

	pq.push(make_pair(0, 0)); // (시간 :0, 노드 :0)

	while (pq.size()) {
		pair<ll, int> now = pq.top(); // now.fisrt = 시간, now.second = 노드
		pq.pop();

		if (now.first > dist[now.second]) { // 이미 최단 시간에 갈 수 있으면
			continue; // 볼 필요 없음
		}
		for (int i = 0; i < edges[now.second].size(); i++) {
			ll nxt_dist = now.first + edges[now.second][i].first; // now까지 시간 + 연결된노드[i].시간
			int nxt_node = edges[now.second][i].second; // 연결된노드[i].노드
			
			if (nxt_dist < dist[nxt_node]) { // 더 빨리 갈 수 있으면
				dist[nxt_node] = nxt_dist;
				pq.push({ nxt_dist, nxt_node });
			}
		}
	}

	if (dist[n - 1] == INF) {
		cout << -1 << "\n";
	}
	else {
		cout << dist[n - 1] << "\n";
	}
}