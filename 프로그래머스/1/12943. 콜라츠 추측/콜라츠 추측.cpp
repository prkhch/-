#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = num;
    int answer = 0;
    
    for(int i=0; i<500; i++) {
        if(n == 1) return answer;
        n = n%2 == 0 ?  n/2 : n*3+1;
        answer++;
    }
    return -1;
}