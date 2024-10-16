#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code) {
    string answer = "";
    
    for(int i=r%q; i<code.length(); i+=q) {
        answer += code[i];
    }
    
    return answer;
}