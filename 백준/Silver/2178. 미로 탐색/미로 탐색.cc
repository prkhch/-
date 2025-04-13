#include <bits/stdc++.h>

using namespace std;

int N, M, arr[101][101], visited[101][101];
int my[] = {-1, 1, 0, 0};
int mx[] = {0, 0, -1, 1};

void bfs() {
    queue<pair<int, int>> q;
    q.push(pair(0, 0));
    visited[0][0] = 1;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];
            if(ny >= N || nx >= M || ny < 0 || nx < 0) continue;
            if(visited[ny][nx] > 0) continue;
            if(arr[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push(pair(ny, nx));
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string row;
        cin >> row;
        for(int j=0; j<M; j++) {
            arr[i][j] = row[j]-'0';
        }
    }

    bfs();

    cout << visited[N-1][M-1];

}
