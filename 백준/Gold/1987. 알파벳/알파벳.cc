#include <bits/stdc++.h>

using namespace std;

int R, C, alphabet[26], visited[21][21], mx;
char arr[21][21];
int dy[] = {-1, 0, 1 ,0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, int lv) {

	mx = max(lv, mx);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if (visited[ny][nx]) continue;
		if (alphabet[arr[ny][nx] - 'A']) continue;
		visited[ny][nx] = 1;
		alphabet[arr[ny][nx] - 'A'] = 1;
		dfs(ny, nx, lv + 1);
		visited[ny][nx] = 0;
		alphabet[arr[ny][nx] - 'A'] = 0;
	}

}

int main() {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < C; j++) {
			arr[i][j] = tmp[j];
		}
	}

	visited[0][0] = 1;
	alphabet[arr[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	cout << mx;

}


