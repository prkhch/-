#include <bits/stdc++.h>
using namespace std;

int N, visited[14][14], arr[14][14];
int dy[] = { -1, 0, 1, 0, 0 }, dx[] = { 0, -1, 0, 1, 0 };
int mn = 200 * 5 * 3;

bool check(int y, int x) {

	for (int i = 0; i < 5; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) return false;
	}
	

	return true;

}

//int sm() {
//	int sm = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (visited[i][j] == 1)
//				sm += arr[i][j];
//		}
//	}
//
//	return sm;
//}

void dfs(int cnt, int cost) {

	if (cnt > 2) {
		mn = min(cost, mn);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check(i, j)) continue;
			for (int k = 0; k < 5; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				visited[ny][nx] = 1;
				cost += arr[ny][nx];
			}
			dfs(cnt + 1, cost);
			for (int k = 0; k < 5; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				visited[ny][nx] = 0;
				cost -= arr[ny][nx];
			}
		}
	}

}

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0);
	
	cout << mn;

}


