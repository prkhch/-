#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;

    for(int i=0; i<T; i++) {
        int N; cin >> N;

        int five = 0;
        for(int i=5; i<=N; i*=5) {
            five += N / i;
        }

        cout << five << "\n";
    }

}
