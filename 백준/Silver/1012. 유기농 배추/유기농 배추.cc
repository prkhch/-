#include <bits/stdc++.h>

using namespace std;

int T, M, N, K, y, x;
int arr[51][51], visited[51][51];
int my[] = {-1, 1, 0, 0};
int mx[] = {0, 0, -1, 1};

void dfs(int y, int x) {
    visited[y][x] = 1;

    for(int i=0; i<4; i++) {
        int ny = my[i] + y;
        int nx = mx[i] + x;
        if(ny >= N || nx >= M || ny < 0 || nx < 0) continue;
        if(visited[ny][nx] == 1) continue;
        if(arr[ny][nx] == 0) continue;
        dfs(ny, nx);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int i=0; i<T; i++) {

        cin >> M >> N >> K;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        for(int j=0; j<K; j++) {
            cin >> x >> y;
            arr[y][x] = 1;
        }

        int answer = 0;
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                if(visited[j][k] == 1) continue;
                if(arr[j][k] == 0) continue;
                dfs(j, k);
                answer++;
            }
        }

        cout << answer << "\n";
        
    }

}
