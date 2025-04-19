#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    string str;
    while (true) {
        getline(cin, str);
        if(str == ".") break;
        stack<char> stk;
        for(char c : str) {
            if(!stk.empty() && stk.top() == '[' && c == ']') {
                stk.pop();
            } else if(!stk.empty() && stk.top() == '(' && c == ')') {
                stk.pop();
            } else if(c == '[' || c ==']' || c == '(' || c == ')') {
                stk.push(c);
            }
        }

        if(stk.empty()) cout << "yes\n";
        else cout << "no\n"; 

    }


}
