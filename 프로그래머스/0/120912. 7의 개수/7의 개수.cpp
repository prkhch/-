#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for(int n : array) {
        string str = to_string(n);
        for(char c : str) if(c == '7') answer++;
    }
    
    return answer;
}