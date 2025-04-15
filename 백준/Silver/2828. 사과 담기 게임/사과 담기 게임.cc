#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M, J, arr[21], ret = 0;
    cin >> N >> M >> J;
    for(int i=0; i<J; i++) {
        cin >> arr[i];
    }

    int pos = 1;
    for(int i=0; i<J; i++) {
        if(pos <= arr[i] && arr[i] <= pos+M-1) continue;

        if(arr[i] < pos) {
            ret += pos - arr[i];
            pos = arr[i];
        } else if(pos+M-1 < arr[i]) {
            ret += arr[i] - (pos+M-1);
            pos = arr[i] - M + 1;
        }

    }

    cout << ret;

}
