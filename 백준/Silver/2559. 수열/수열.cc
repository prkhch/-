#include <bits/stdc++.h>

using namespace std;

int psum[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    
    for(int i=1; i<=N; i++) {
        int tmp;
        cin >> tmp;
        psum[i] = psum[i-1] + tmp;
    }

    int mx = INT_MIN;
    for(int i=0; i<=N-K; i++) {
        mx = max(mx, psum[i+K] - psum[i]);
    }

    cout << mx;

}
