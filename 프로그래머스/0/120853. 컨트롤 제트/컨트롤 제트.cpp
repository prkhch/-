#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    stringstream ss(s);
    
    string words;
    int tmp = 0;
    while(getline(ss, words, ' ')) {
        if(words != "Z") {
            tmp = stoi(words);
            answer += tmp;
        }
        else answer -= tmp;
    }
    
    return answer;
}