#include <bits/stdc++.h>

using namespace std;

int arr[1000001], ret[1000001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int N; cin >> N;

    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    stack<int> stk;

    for(int i=N-1; i>=0; i--) {
        if(stk.empty()) {
            ret[i] = -1;
        }
        else if(!stk.empty() && stk.top() > arr[i]) {
            ret[i] = stk.top();
        } 
        else if(!stk.empty() && stk.top() <= arr[i]) {
            while(!stk.empty() && stk.top() <= arr[i]) stk.pop();
                if(!stk.empty()) {
                    ret[i] = stk.top();
                } else if(stk.empty()) {
                    ret[i] = -1;
                }
        }
        stk.push(arr[i]);
    }

    for(int i=0; i<N; i++) {
        cout << ret[i] << " ";
    }

}
