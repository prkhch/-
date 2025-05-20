#include <bits/stdc++.h>
using namespace std;

string tmp;
int R, C, K, visited[9][9], result;
char arr[9][9];
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };

void dfs(int y, int x, int cnt) {

	if (y == 0 && x == C - 1 && cnt == K) {
		result++;
		return;
	}
	if (cnt > K) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] || arr[ny][nx] == 'T') continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, cnt + 1);
		visited[ny][nx] = 0;
	}

}

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			arr[i][j] = tmp[j];
		}
	}

	visited[R - 1][0] = 1;
	dfs(R-1, 0, 1);

	cout << result;
}


