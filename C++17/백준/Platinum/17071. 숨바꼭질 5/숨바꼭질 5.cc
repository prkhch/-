#include <bits/stdc++.h>
using namespace std;

int N, K, visited[2][500004], t;
bool possible;

void bfs() {

	queue<int> q;
	q.push(N);
	visited[0][N] = 1;

	if (N == K) {
		cout << 0;
		return;
	}

	while (q.size()) {
		t++;
		K += t;
		if (K > 500000) break;
		if (visited[t % 2][K]) {
			possible = true; break;
		}

		int NowQueueSize = q.size();
		for (int i = 0; i < NowQueueSize; i++) {
			int x = q.front(); q.pop();

			for (int nx : {x + 1, x - 1, x * 2}) {
				if (nx < 0 || nx > 500000) continue;
				if (visited[t % 2][nx] == 1) continue;
				visited[t % 2][nx] = 1;
				if (nx == K) {
					possible = true;  break;
				}
				q.push(nx);
			}

		}
		if (possible) break;

	}

	if (possible) cout << t;
	else cout << -1;

}

int main() {
	
	cin >> N >> K;
	bfs();

}