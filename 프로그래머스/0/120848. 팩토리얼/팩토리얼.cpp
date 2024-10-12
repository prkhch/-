#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int now = 1;
    int i = 1;
    
    while(now < n) {
        now*=i;
        i++;
        if(now == n) {
            i-=1;
        }
        if(now > n) {
            i-=2;
        }
    }

    return i;
}