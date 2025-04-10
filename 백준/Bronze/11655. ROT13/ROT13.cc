#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    getline(cin, str);

    for(char c : str) {
        if(islower(c)) {
            if(c + 13 > 122) c = c + 13 - 26; // 97 + 25
            else c = c + 13;
        } else if(isupper(c)) {
            if(c + 13 > 90) c = c + 13 - 26; // 65 + 25
            else c = c + 13;
        }

        cout << c;
    }

}
