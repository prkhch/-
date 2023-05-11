#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(!('0' <= s[0] && s[0] <= '9')) {
        answer += toupper(s[0]); // 문자면 대문자로
    } else {
        answer += s[0]; // 숫자면 그냥 저장
    }
    
    for(int i=1; i<s.length(); i++) {
        if(s[i-1]==' ') { // 이전이 공백이다.
            answer += toupper(s[i]);
        }
        else {
            answer += tolower(s[i]);
        }
    }
    
    return answer;
}