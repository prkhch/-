#include <bits/stdc++.h>

using namespace std;

int N, M, visited[51][51];
char arr[51][51];
int my[] = {-1, 1, 0, 0};
int mx[] = {0, 0, -1, 1};

int bfs(int y, int x) {

    queue<pair<int,int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    int ret = 0;

    while(!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = yy + my[i];
            int nx = xx + mx[i];

            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(arr[ny][nx] == 'W') continue;
            if(visited[ny][nx] > 0) continue; 
            visited[ny][nx] = visited[yy][xx] + 1;
            ret = max(visited[ny][nx], ret);
            q.push({ny, nx});
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;

    string line;
    for(int i=0; i<N; i++) {
        cin >> line;
        for(int j=0; j<M; j++) {
            arr[i][j] = line[j];
        }
    }

    int mx = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(arr[i][j] == 'L') {
                fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
                mx = max(mx, bfs(i, j));
            }
        }
    }

    cout << mx-1;
}
