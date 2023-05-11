#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v[1001];
int inDegree[1001], result[1001];
queue<int> q;

void topologySort() {
	
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			result[next] = result[now] + 1;
			inDegree[next] --;
			if (inDegree[next] == 0) {
				q.push(next);
			}
		}
	}


}

int main() {
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		inDegree[b] ++;
	}

	for (int i = 1; i <= n; i++) {
		result[i] = 1; // 기본값 1
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	topologySort();

	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}
}