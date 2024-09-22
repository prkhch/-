#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    string str = to_string(age);
    
    for(char c : str) {
        answer += c+97-48;
    }
    
    return answer;
}