#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    for(int i=0; i<tc; i++) {
        int n;
        cin >> n;

        map<string, int> _map;
        for(int j=0; j<n; j++) {
            string a, b;
            cin >> a >> b;
            _map[b]++;
        }

        long long answer = 1;
        for(auto it : _map) {
            answer *= (it.second + 1);
        }

        cout << answer-1 << "\n";
    }
    
}
