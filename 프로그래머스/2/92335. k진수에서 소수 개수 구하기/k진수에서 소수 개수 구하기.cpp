#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool sosu(string str) {
    long long num = stoll(str);
    if(num == 1) {
        return false;
    }

    for(int i=2; i<=sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }
    
    return true;
}

int solution(int n, int k) {
    int answer;
    
    vector<int> v; 

    while(n) {
        v.push_back(n%k);
        n /= k;
    }
    
    int v_size = v.size();
    int cnt = 0;
    string str = "";
    
    for(int i=v_size-1; i>=0; i--) {

        if(v[i] != 0 ) {
            str += to_string(v[i]);
        }
        
        if(v[i] == 0 || i==0) {
            if(str != "") {         
                if(sosu(str)) {
                    cnt ++;
                };
            }
            // cout << i << ":" << str << "\n";
            str = "";
        }
        
    }
    
    answer = cnt;
    return answer;
}