#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    string sk = to_string(k);
    
    for(int a=i; a<=j; a++) {
        for(char c : to_string(a)) {
             if(c == sk[0]) answer++;
        }
    }
    
    return answer;
}