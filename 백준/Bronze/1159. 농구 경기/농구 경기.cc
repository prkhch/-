#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    int name[26];
    memset(name, 0, sizeof(name));
    cin >> N;
    for(int i=0; i<N; i++) {
        string str;
        cin >> str;
        name[str[0]-'a']++;
    }

    bool tf = false;
    for(int i=0; i<26; i++) {
        if(name[i] >= 5) {
            cout << (char)(i+'a');
            tf = true;
        }
    }

    if(tf==false) cout << "PREDAJA";

}



