#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;

    string sn = "";
    for(char c : my_string) {
        if(48 <= c && c <= 57) {
            sn += c;
        } else if(sn != "") {
            answer += stoi(sn);
            sn = "";
        }
    }
    
    if(sn != "") answer += stoi(sn);
    
    return answer;
}