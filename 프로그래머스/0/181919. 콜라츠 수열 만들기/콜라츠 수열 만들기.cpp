#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    while(1) {
        answer.push_back(n);
        if(n == 1) break;
        n = n % 2 == 0 ? n/2 : 3*n + 1;
    }
    
    return answer;
}