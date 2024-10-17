#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    vector<int> tmp_arr;
    
    while(tmp_arr != arr) {
        tmp_arr = arr;
        for(int& n : arr) {
            if(n >= 50 && n%2 == 0) {
                n/=2;
            } else if(n < 50 && n%2 == 1) {
                n = n*2 + 1;
            }
        }
        answer++;
    }
    
    return answer-1;
}