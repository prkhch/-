#include <bits/stdc++.h>

using namespace std;

int N, M, arr[101][101], visited[101][101], pre, t;
int my[] = {-1, 1, 0, 0};
int mx[] = {0, 0, -1, 1};
vector<pair<int, int>> v;

void dfs(int y, int x) {

    for(int i=0; i<4; i++) {
        int ny = my[i] + y;
        int nx = mx[i] + x;
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(visited[ny][nx] == 1) continue;
        if(arr[ny][nx] == 1) {
            v.push_back({ny, nx});
            visited[ny][nx] = 1;
            continue;
        }
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }

}

int check() {
    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(arr[i][j] == 1) {
                cnt++;
            }
        }
    }
    if(cnt > 0) {
        pre = cnt;
    }
    return cnt;
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

    while(check() > 0) {
        v.clear();
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);

        dfs(0 ,0);
        
        for(auto i : v) {
            arr[i.first][i.second] = 0;
        }
        
        t++;
        
    }

    cout << t << "\n" << pre;

}
