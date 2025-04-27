#include <bits/stdc++.h>

using namespace std;

int N, arr[3], visited[64][64][64];
int mn = 1e9;

int dmg[6][3] = {
    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1},
    {9, 1, 3},
    {9, 3, 1}
};

struct Info {
    int a;
    int b;
    int c;
    int cnt;
};

void bfs() {

    queue<Info> q;
    q.push({arr[0], arr[1], arr[2], 0});
    visited[arr[0]][arr[1]][arr[2]] = 1;

    while(!q.empty()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        int cnt = q.front().cnt;
        q.pop();

        if(a <= 0 && b <= 0 && c <= 0) {
            mn = min(cnt, mn);
        }

        for(int i=0; i<6; i++) {
            int na = max(0, a - dmg[i][0]);
            int nb = max(0, b - dmg[i][1]);
            int nc = max(0, c - dmg[i][2]);
            if(visited[na][nb][nc] == 1) continue;
            visited[na][nb][nc] = 1;
            q.push({na, nb, nc, cnt+1});
        }
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    bfs();

    cout << mn;

}
