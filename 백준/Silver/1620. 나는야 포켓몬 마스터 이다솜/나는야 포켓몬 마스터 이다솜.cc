#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, string> mp;
    for(int i=0; i<N; i++) {
        string str;
        cin >> str;
        mp[str] = to_string(i+1);
        mp[to_string(i+1)] = str;
    }

    for(int i=0; i<M; i++) {
        string a;
        cin >> a;
        cout << mp[a] << "\n";
    }

}
