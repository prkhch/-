#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int T; cin >> T;

    
    for(int i=0; i<T; i++) {
        string str; cin >> str;
        stack<char> stk;

        for(char c : str) {
            if(!stk.empty() && stk.top() == '(' && c == ')') {
                stk.pop();
            } else {
                stk.push(c);
            }
        }

        if(stk.empty()) cout << "YES\n";
        else cout << "NO\n";

    }

}
