#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, inDegree[32001];
vector<int> edge[32001];
vector<int> result;

void topologySort() {
	queue<int> q;

	// 초기 세팅
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) { // 진입차수가 0인 값 큐에 넣기
			q.push(i);
		}
	}

	while (q.size()) {
		int now = q.front();
		result.push_back(now);
		q.pop();

		for (int i = 0; i < edge[now].size(); i++) {
			int idjNode = edge[now][i];
			inDegree[idjNode] --;
			if (inDegree[idjNode] == 0) {
				q.push(idjNode);
			}
		}

	}

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		inDegree[b] ++; // 진입차수
	}

	topologySort();

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}

}