#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> todo_list, vector<bool> finished) {
    vector<string> answer;
    
    int size = todo_list.size();
    
    for(int i=0; i<size; i++) {
        finished[i] == false ? answer.push_back(todo_list[i]) : void();
    }
    
    return answer;
}