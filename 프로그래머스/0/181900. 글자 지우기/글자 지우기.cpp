#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    
    bool used[101] = {false};
    
    for(int i=0; i<indices.size(); i++) {
        used[indices[i]] = true;
    }
    
    for(int i=0; i<my_string.length(); i++) {
        if(used[i]) continue;
        answer += my_string[i];
    }
    
    return answer;
}