#include <bits/stdc++.h>

using namespace std;

int N, K, arr[200004], visited[200004];
int mn = 987654321;
int cnt;

void bfs() {

    queue<int> q;
    q.push(N);
    visited[N] = 0;

    while(q.size()) {
        int x = q.front(); q.pop();
        if(x == K) { // K 도달
            if(mn > visited[x]) {
                mn = visited[x];
                cnt = 1;
            } else if(mn == visited[x]) {
                cnt += 1;
            }
        }
        
        for(int i : {x+1, x-1, x*2}) {
            if(i<0 || i>200000) continue;
            if(visited[i] < visited[x] + 1) continue; // 더 느린 방문
            visited[i] = visited[x] + 1;
            q.push(i);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    fill(&visited[0], &visited[0] + 200004, 987654321);
    bfs();

    cout << mn << "\n" << cnt;
}
