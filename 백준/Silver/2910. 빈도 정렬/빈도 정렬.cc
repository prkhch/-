#include <bits/stdc++.h>

using namespace std;

int N, C, tmp;
map<int,int> mp_freq;
map<int,int> mp_order;
vector<pair<int,int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) { // 빈도수가 같으면
        return mp_order[a.first] < mp_order[b.first]; // 숫자의 순서가 빠른순
    }
    return a.second > b.second; // 빈도수가 큰
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> C;

    for(int i=0; i<N; i++) {
        cin >> tmp;
        mp_freq[tmp]++;
        if(mp_order[tmp] == 0) mp_order[tmp] = i+1;
    }

    for(auto it : mp_freq) {
        v.push_back({it.first, it.second}); // 숫자, 빈도수
    }
    
    sort(v.begin(), v.end(), cmp);

    for(auto i : v) {
        for(int j=0; j<i.second; j++) {
            cout << i.first << " ";
        }
    }

}
