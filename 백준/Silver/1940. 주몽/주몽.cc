#include <bits/stdc++.h>

using namespace std;

int N, M, arr[15001], result;

void combi(int start, vector<int> &v) {

    if(v.size() == 2) {
        if(v[0] + v[1] == M) {
            result++;
        }
        return;
    }

    for(int i=start+1; i<N; i++) {
        v.push_back(arr[i]);
        combi(i, v);
        v.pop_back();
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    vector<int> v;
    combi(-1, v);

    cout << result;
}
