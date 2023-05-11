#include <string>
#include <vector>

using namespace std;
int cnt;
int n;
vector<int> numbers;

void run(int lv, int sum, vector<int> numbers, int target) {
    
    if(lv == n) {
        if(sum == target) {
            cnt ++;
        }
        return;
    }
    
    run(lv+1, sum+numbers[lv], numbers, target);
    run(lv+1, sum-numbers[lv], numbers, target);

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    n = numbers.size();
    
    run(0, 0, numbers, target);
    
    answer = cnt;

    return answer;
}