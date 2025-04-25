#include <bits/stdc++.h>

using namespace std;

int R, C, j_visited[1001][1001], f_visited[1001][1001], jy, jx;
char arr[1001][1001];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
bool possible;

void j_bfs() {

    queue<pair<int, int>> q;
    q.push({jy, jx});
    j_visited[jy][jx] = 1;

    while(!q.empty()) {
        int y, x; tie(y, x) = q.front(); q.pop();

        if(y == 0 || x == 0 || y == R-1 || x == C-1) {
            possible = true;
            cout << j_visited[y][x];
            break;
        }

        for(int i=0; i<4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny<0 || nx<0 || ny>=R || nx>=C) continue;
            if(arr[ny][nx] == '#') continue;
            if(f_visited[ny][nx] != 0 && f_visited[ny][nx] <= j_visited[y][x] + 1) continue; // 이미 불이 있으면
            if(j_visited[ny][nx] > 0) continue;
            j_visited[ny][nx] = j_visited[y][x] + 1;
            q.push({ny, nx});
        }

    }

}

void f_bfs() {

    queue<pair<int, int>> q;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(arr[i][j] == 'F') {
                q.push({i, j});
                f_visited[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        int y, x; tie(y, x) = q.front(); q.pop();

        for(int i=0; i<4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny<0 || nx<0 || ny>=R || nx>=C) continue;
            if(arr[ny][nx] == '#') continue;
            if(f_visited[ny][nx] > 0) continue;
            f_visited[ny][nx] = f_visited[y][x] + 1;
            q.push({ny, nx});
        }

    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> R >> C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'J') {
                jy = i; jx = j;
            }
        }
    }

    f_bfs();
    j_bfs();

    if(!possible) cout << "IMPOSSIBLE";

}
