#include <bits/stdc++.h>

using namespace std;

int N, rm;
vector<vector<int>> v(51);

int dfs(int st) {

    int ret = 0;
    int child = 0;

    for(int i=0; i<v[st].size(); i++) {
        if(v[st][i] == rm) continue;
        child++;
        ret += dfs(v[st][i]);
    }

    if(child==0) return 1;
    return ret;

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N;
    int root = -1;
    int tmp;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        if(tmp == -1) root = i;
        else v[tmp].push_back(i);
    }
    cin >> rm;

    if(rm == root) cout << 0;
    else cout << dfs(root);

}
