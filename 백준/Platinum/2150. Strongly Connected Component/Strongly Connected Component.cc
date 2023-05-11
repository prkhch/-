#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int v, e;
vector<vector<int>> adjList, SCCs;
int visitOrder[10001];
int id;
int isScc[10001];
int sccSize;
stack<int> s;

int dfs(int now) {
	visitOrder[now] = ++id;
	s.push(now);

	// 부모 찾기
	int parent = visitOrder[now]; // 자기 자신을 부모

	for (int i = 0; i < adjList[now].size(); i++) {
		int next = adjList[now][i];

		if (visitOrder[next] == 0) parent = min(parent, dfs(next)); // 방문하지 않았다면
		else if (isScc[next] == 0) parent = min(parent, visitOrder[next]); // sccID를 할당받지 않았다면
	}

	if (visitOrder[now] == parent) { // 자신 == 부모 노드
		vector<int> scc;
		while (1) {
			int topNode = s.top(); s.pop(); // 꺼내기
			scc.push_back(topNode); // scc에 저장
			isScc[topNode] = 1; // 이 노드는 scc다.
			if (topNode == now) break; // 꺼낸 노드가 부모노드라면 break
		}
		sccSize++;
		SCCs.push_back(scc);
	}
	return parent;
}

int main() {
	cin >> v >> e;
	adjList.resize(v + 1);

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
	}

	for (int i = 1; i <= v; i++)
		if (visitOrder[i] == 0)
			dfs(i);

	for (int i = 0; i < SCCs.size(); i++) {
		sort(SCCs[i].begin(), SCCs[i].end());
	}
	sort(SCCs.begin(), SCCs.end());

	cout << sccSize << "\n";
	for (int i = 0; i < SCCs.size(); i++) {
		for (int j = 0; j < SCCs[i].size(); j++) {
			cout << SCCs[i][j] << " ";
		}
		cout << "-1\n";
	}

}