#include <string>
#include <vector>

using namespace std;

string search(int n) {
    if(n == 1) return "w";
    if(n == -1) return "s";
    if(n == 10) return "d";
    if(n == -10) return "a";    
}

string solution(vector<int> numLog) {
    int size = numLog.size();
    string answer = "";
    answer.reserve(size-1);
    
    int gap;
    for(int i=1; i<numLog.size(); i++) {
        gap = numLog[i] - numLog[i-1];
        answer += (search(gap));
    }
    
    return answer;
}