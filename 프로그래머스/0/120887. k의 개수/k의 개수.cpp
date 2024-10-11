#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    string s;
    string sk = to_string(k);
    
    for(int a=i; a<=j; a++) {
        s = to_string(a);
        
        for(char c : s) {
             if(c == sk[0]) answer++;
        }
       
    }
    
    return answer;
}