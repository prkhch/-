#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    
    for(int n : emergency) {
        int pos = 1;
        for(int j=0; j<emergency.size(); j++ ) {
            if(n < emergency[j]) {
                pos+=1;
            }
        }
        answer.push_back(pos);
    }
    
    return answer;
}