#include <bits/stdc++.h>
using namespace std;

int N, K;
int visited[200004], pre[200004];

void bfs() {

    queue<int> q;
    q.push(N);
    // visited[N] = 1;

    while(q.size()) {
        int x = q.front(); q.pop();

        if(x == K) {
            cout << visited[x] << "\n";
            break;
        }

        for(int nx : {x+1, x-1, x*2}) {
            if(nx > 100001 || nx < 0) continue;
            if(visited[nx]) continue;
            visited[nx] = visited[x] + 1;
            pre[nx] = x;
            q.push(nx);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    bfs();
    
    vector<int> path;
    path.push_back(K);
    for(int i=K; i!=N; i=pre[i]) {
        path.push_back(pre[i]);
    }

    for(int i=path.size()-1; i>=0; i--) {
        cout << path[i] << " ";
    }

}
