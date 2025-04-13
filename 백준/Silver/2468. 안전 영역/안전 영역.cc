#include <bits/stdc++.h>

using namespace std;

int N, arr[101][101], visited[101][101], height;
int my[] = {-1, 1, 0, 0};
int mx[] = {0, 0, -1, 1};
void dfs(int y, int x) {
    visited[y][x] = 1;

    for(int i=0; i<4; i++) {
        int ny = y + my[i];
        int nx = x + mx[i];

        if(ny >= N || nx >= N || ny < 0 || nx < 0) continue;
        if(visited[ny][nx]) continue;
        if(arr[ny][nx] <= height) continue; // 잠긴
        dfs(ny, nx);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    int mx_area = 0;
    for(int i=0; i<=100; i++) {
        height = i;
        int area = 0;
        memset(visited, 0, sizeof(visited));

        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                if(visited[j][k]) continue;
                if(arr[j][k] <= height) continue; // 잠긴
                dfs(j, k);
                area++;
            }
        }
        mx_area = max(area, mx_area);
    }

    cout << mx_area;

}
