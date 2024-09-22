#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    vector<bool> used(123);
    
    for(char c : my_string) {
        if(used[c] == true) continue;
        answer += c;
        used[c] = true;
    }
    
    return answer;
}

