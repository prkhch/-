#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    string copyStr;
    cin >> str;

    copyStr = str;
    reverse(str.begin(), str.end());

    if(copyStr == str) {
        cout << 1;
    } else {
        cout << 0;
    }
}
