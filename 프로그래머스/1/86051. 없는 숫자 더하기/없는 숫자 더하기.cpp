#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<bool> used(10);
    
    for(int i : numbers) {
        used[i] = true;
    }
    
    for(int i=0; i<10; i++) {
        if(used[i] == false) answer += i;
    }
    
    return answer;
}