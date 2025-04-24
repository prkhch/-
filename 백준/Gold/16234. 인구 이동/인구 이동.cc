#include <bits/stdc++.h>

using namespace std;

int N, L, R;
int arr[51][51], visited[51][51];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int cnt, pop, day;
bool flag;

void dfs(int y, int x, vector<pair<int, int>>& un) {

    for(int i=0; i<4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if(visited[ny][nx] == 1) continue;
        if(L <= abs(arr[y][x] - arr[ny][nx]) && abs(arr[y][x] - arr[ny][nx]) <= R) {
            visited[ny][nx] = 1;
            un.push_back({ny, nx});
            pop += arr[ny][nx]; // 총 연합인구수
            dfs(ny, nx, un);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N >> L >> R;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, int>> un;
    while(true) {
        flag = false; // 연합X
        memset(visited, 0, sizeof(visited)); // 방문 초기화
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(visited[i][j] == 1) continue;
                un.clear();
                visited[i][j] = 1;
                pop = arr[i][j];
                un.push_back({i, j});
                dfs(i, j, un);
                if(un.size() > 1) {
                    flag = true;
                    for(pair<int, int> i : un) {
                        arr[i.first][i.second] = pop/un.size();
                    }
                }
            }
        }

        if(flag) day+=1;
        else break;

    }

    cout << day;

}
