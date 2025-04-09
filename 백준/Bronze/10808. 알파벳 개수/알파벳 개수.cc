#include <bits/stdc++.h>

using namespace std;

int a[26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    for(auto c : str) {
        a[c-'a']++;
    }

    for(auto i : a) {
        cout << i << " ";
    }
}
