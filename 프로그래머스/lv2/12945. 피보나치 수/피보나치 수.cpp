#include <string>
#include <vector>

using namespace std;

int fibonachi(int n) {
   
}


int solution(int n) {
    int answer = 0;
    
    int fibo[100001] = {0, };
    
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<=n; i++) {
        fibo[i] = (fibo[i-1]%1234567) + (fibo[i-2]%1234567) ;
    }
    
    answer = fibo[n]%1234567;
    
    return answer;
}