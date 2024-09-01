#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int sum = 0;
    int multiply = 1;
    for(int i : num_list) {
        sum += i;
        multiply *= i;
    }
    
    int answer = multiply < (sum*sum) ? 1 : 0;
    return answer;
}