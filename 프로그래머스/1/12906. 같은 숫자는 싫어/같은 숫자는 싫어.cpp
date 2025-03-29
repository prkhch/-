#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> stk;
    vector<int> answer;

    for(int i=0; i<arr.size(); i++) {
        if(!stk.empty() && stk.top() == arr[i]) {
            continue;
        } else {
            answer.push_back(arr[i]);
            stk.push(arr[i]);
        }
    }

    return answer;
}