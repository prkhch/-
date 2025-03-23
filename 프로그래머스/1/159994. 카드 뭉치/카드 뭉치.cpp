#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {

    int cd1_idx = 0;
    int cd2_idx = 0;
    int goal_idx = 0;
    
    while(1) {
        if(cd1_idx < cards1.size() && goal[goal_idx] == cards1[cd1_idx]) {
            goal_idx++;
            cd1_idx++;
        } else if(cd2_idx < cards2.size() && goal[goal_idx] == cards2[cd2_idx]) {
            goal_idx++;
            cd2_idx++;
        } else {
            break;
        }
    }
    
    if(goal_idx == goal.size()) return "Yes";
    else return "No";

}