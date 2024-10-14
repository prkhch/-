#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    int answer[31] = {};
    
    for(string str : strArr)
        answer[str.length()] ++;
    
    return *max_element(answer, answer + 31);
}