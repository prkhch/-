#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int answer = 0;
    for(int i=0; i<N; i++) {
        stack<char> stk;
        string str;
        cin >> str;

        for(char c : str) {
            if(!stk.empty() && stk.top() == c) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }

        if(stk.empty()) {
            answer++;
        }
    }
    
    cout << answer;   

}
