#include <bits/stdc++.h>

using namespace std;

int N, M, A, B;
vector<vector<int>> v(10001);
int arr[10001], visited[10001];

int dfs(int st) {

    if(visited[st] == 1) return 0;
    visited[st] = 1;
    int ret = 1;

    for(int i=0; i<v[st].size(); i++) {
        ret += dfs(v[st][i]);
    }

    return ret;

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;

    for(int i=0; i<M; i++) {
        cin >> A >> B;
        v[B].push_back(A);
    }

    int mx = 0;
    for(int i=1; i<=N; i++) {
        fill(&visited[0], &visited[0] + 10001, 0);
        arr[i] = dfs(i);
        mx = max(arr[i], mx);
    }

    for(int i=1; i<=N; i++) {
        if(mx==arr[i]) cout << i << " ";
    }
    

}
