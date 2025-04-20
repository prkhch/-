#include <bits/stdc++.h>

using namespace std;

int N, M, arr[9][9], tmp[9][9];
int my[] = {-1, 1, 0, 0};
int mx[] = {0, 0, -1, 1};
int mx_cnt = 0;

void check() {
    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(tmp[i][j] == 0) {
                cnt++;
            }
        }
    }

    mx_cnt = max(cnt, mx_cnt);
}

void dfs(int y, int x) {
    for(int i=0; i<4; i++) {
        int ny = my[i] + y;
        int nx = mx[i] + x;
        if(ny >= N || nx >= M || ny < 0 || nx < 0) continue;
        if(tmp[ny][nx] == 1 || tmp[ny][nx] == 2) continue;
        tmp[ny][nx] = 2;
        dfs(ny, nx);
    }

}

void wall(int cnt) {
    if(cnt == 3) {
        memcpy(tmp, arr, sizeof(tmp));
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(tmp[i][j] == 2) {
                    dfs(i, j);
                }
            }
        }
        check();
        return;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(arr[i][j] != 0) continue;
            arr[i][j] = 1;
            wall(cnt+1);
            arr[i][j] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }

    wall(0);

    cout << mx_cnt;
}
