#include <bits/stdc++.h>
using namespace std;

int N, M, H, visited[34][34], a, b;
int ret = 5;

bool check() {

	for (int i = 1; i <= N; i++) {
		int x = i;
		for (int j = 1; j <= H; j++) {
			if (visited[j][x - 1]) {
				x--;
			}
			else if (visited[j][x]) {
				x++;
			}
		}
		if (x != i) return false;
	}
	return true;

}

void dfs(int y, int cnt) {

	if (cnt > 3 || cnt >= ret) {
		return;
	}
	if (check()) {
		ret = min(cnt, ret);
		return;
	}


	for (int i = y; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (visited[i][j]) continue;
			if (visited[i][j - 1]) continue;
			visited[i][j] = 1;
			dfs(i, cnt + 1);
			visited[i][j] = 0;
		}
	}

}

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		visited[a][b] = 1;
	}

	dfs(1, 0);

	cout << ((ret == 5) ? -1 : ret);
}


