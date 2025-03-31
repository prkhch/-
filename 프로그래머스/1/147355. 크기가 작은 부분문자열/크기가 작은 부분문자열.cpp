#include <bits/stdc++.h>

using namespace std;

int solution(string t, string p) {
    int answer = 0; 
    int st = 0;
    string tmp = "";
    
    while(true) {
        
        for(int i=st; i<st+p.size(); i++) {
            tmp += t[i];
        }
        
        if(stoll(p) >= stoll(tmp)) answer++;
        
        tmp = "";
        
        st++;
        
        if(st == t.size() - p.size() + 1) {
            break;
        }
    }
    
    return answer;
}