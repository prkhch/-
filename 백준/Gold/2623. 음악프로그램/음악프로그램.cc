#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v[1001];
vector<int> result;
int inDegree[1001];
queue<int> q;

void topologySort() {

	while (q.size()) {
		int now = q.front(); q.pop();
		result.push_back(now);

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
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

		int line, a, b;
		cin >> line;
		cin >> a;
		for (int j = 0; j < line - 1; j++) {
			cin >> b;
			v[a].push_back(b);
			inDegree[b] ++;
			a = b;
		}

	}

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	topologySort();

	if (result.size() == n) {
		for (int i = 0; i < n; i++) {
			cout << result[i] << "\n";
		}
	}
	else {
		cout << '0';
	}
}