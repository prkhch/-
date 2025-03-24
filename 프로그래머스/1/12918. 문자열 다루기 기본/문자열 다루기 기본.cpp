#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool solution(string s) {
    
    for(int i=0; i<s.size(); i++) {
        if(0 < s[i]-'0' && s[i]-'0' > 9) {
            return false;
        }
    }
    
    if(s.size() != 4 && s.size() != 6) return false;
    
    return true;
}