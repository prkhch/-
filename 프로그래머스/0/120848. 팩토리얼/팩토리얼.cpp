#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int now = 1;
    int i = 1;
    
    while(now * i <= n) {
        now*=i;
        i++;
    }

    return i-1;
}