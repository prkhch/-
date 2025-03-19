#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
    
    int n, answer = 0;
    string str;
    
    cin >> n;
    for(int i=0; i<n; i++) {    

        cin >> str;
        stack<char> stk;
        for(int j=0; j<str.size(); j++) {
            if(stk.size() && stk.top() == str[j]) {
                stk.pop();
            } else {
                stk.push(str[j]);
            }
        }
        
        if(stk.empty()) {
            answer++;
        }
    }
    
    cout << answer;
    return 0;
}