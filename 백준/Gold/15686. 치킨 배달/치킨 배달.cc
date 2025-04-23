#include <bits/stdc++.h>

using namespace std;

int N, M, arr[51][51];

vector<pair<int, int>> cks;
vector<pair<int, int>> hss;
vector<pair<int, int>> combiList;

int mn = 1e9;

void combi(int st) {

    if(combiList.size() == M) {
        int _dist_sum = 0;
        for(int i=0; i<hss.size(); i++) {
            int _dist = 1e9;
            for(int j=0; j<combiList.size(); j++) {
                _dist = min(abs(hss[i].first - combiList[j].first) + abs(hss[i].second - combiList[j].second), _dist);
            }
            _dist_sum += _dist;
        }
        mn = min(mn, _dist_sum);
    }
    
    for(int i=st+1; i<cks.size(); i++) {
        combiList.push_back({cks[i].first, cks[i].second});
        combi(i);
        combiList.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) hss.push_back({i, j});
            if(arr[i][j] == 2) cks.push_back({i, j});
        }
    }

    vector<pair<int, int>> v;
    combi(-1);
    cout << mn;

}
