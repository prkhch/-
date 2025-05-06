#include <bits/stdc++.h>

using namespace std;

int N, M, jy, jx, by, bx, visited[304][304], cnt;
char arr[304][304];
int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };


void bfs() {

    queue<pair<int, int>> q;
    visited[jy - 1][jx - 1] = 1;
    q.push({ jy - 1, jx - 1 });

    while (true) {
        if (visited[by - 1][bx - 1] != 0) break;
        cnt++;
        queue<pair<int, int>> tmp;
        while (q.size()) {
            int y, x;
            tie(y, x) = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if (arr[ny][nx] == '1') {
                    arr[ny][nx] = 0;
                    tmp.push({ ny, nx });
                }
                else {
                    q.push({ ny, nx });
                }
            }
        }
        q = tmp;

    }
  

}

int main() {

    cin >> N >> M >> jy >> jx >> by >> bx;
    for (int i = 0; i < N; i++) {
        string row; cin >> row;
        for (int j = 0; j < M; j++) {
            arr[i][j] = row[j];
        }
    }

    bfs();

    cout << visited[by - 1][bx - 1];
}


