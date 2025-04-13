#include <bits/stdc++.h>

using namespace std;

int M, N, K, arr[101][101], visited[101][101], ret;
int ly, lx, ry, rx;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int area;

void dfs(int y, int x) {
    visited[y][x] = 1;
    area++;

    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= M || nx >= N || ny < 0 || nx < 0) continue;
        if(visited[ny][nx]) continue;
        if(arr[ny][nx]) continue;
        dfs(ny, nx);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> K;
    for(int i=0; i<K; i++) {
        cin >> lx >> ly >> rx >> ry;

        for(int j=ly; j<ry; j++) {
            for(int k=lx; k<rx; k++) {
                arr[j][k] = 1;
            }
        }
    }

    vector<int> v;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(visited[i][j]) continue;
            if(arr[i][j]) continue;
            area = 0;
            dfs(i, j);
            ret++;
            v.push_back(area);
        }
    }

    sort(v.begin(), v.end());

    cout << ret << "\n";
    for(int i : v) {
        cout << i << " ";
    }

}
