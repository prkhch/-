#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    int prev = 0;
    int i = 0;
    while(i < dartResult.length()) {
        int now = 0;
        if('0' <= dartResult[i] && dartResult[i] <= '9') { // 숫자
            if(i+1 < dartResult.length() && dartResult[i] == '1' && dartResult[i+1] == '0') {
                now = 10;
                i++; 
            }
            
            if(i+1 < dartResult.length() && dartResult[i+1] == 'S') { // 보너스
                if(now!=10) {
                    now = dartResult[i] - '0';
                }
                if(i+2 < dartResult.length() && dartResult[i+2] == '*') { // 옵션
                    answer += prev;
                    now *= 2;
                }
                else if(i+2 < dartResult.length() && dartResult[i+2] == '#') {
                    now *= -1;
                }
            }
            else if(i+1 < dartResult.length() && dartResult[i+1] == 'D') {
                if(now!=10) {
                    now = pow(dartResult[i] - '0', 2);
                } else {
                    now = pow(10,2);
                }
                if(i+2 < dartResult.length() && dartResult[i+2] == '*') {
                    answer += prev;
                    now *= 2;
                }
                else if(i+2 < dartResult.length() && dartResult[i+2] == '#') {
                    now *= -1;
                }
            }
            else if(i+1 < dartResult.length() && dartResult[i+1] == 'T') {
                if(now!=10) {
                    now = pow(dartResult[i] - '0', 3);
                } else {
                    now = pow(10,3);
                }
                if(i+2 < dartResult.length() && dartResult[i+2] == '*') {
                    answer += prev;
                    now *= 2;
                }
                else if(i+2 < dartResult.length() && dartResult[i+2] == '#') {
                    now *= -1;
                } 
            }
            
            prev = now;
            answer += now;
        }     
        i++;
    } // while
    
    
    return answer;
}