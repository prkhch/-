#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string one = to_string(a) + to_string(b);
    string two = to_string(b) + to_string(a);
    
    answer = stoi(one) >= stoi(two) ? stoi(one) : stoi(two);
    
    return answer;
}