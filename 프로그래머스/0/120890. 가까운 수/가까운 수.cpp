#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = array[0];
    
    for(int i : array) {
        if(abs(answer-n) > abs(i-n)) {
            answer = i;
        } else if (abs(answer-n) == abs(i-n)) {
            answer = min(answer, i);
        }
    }
    
    return answer;
}