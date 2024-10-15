#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int st;
    int ed;
    
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == 2) {
            st = i;
            break;
        }    
    }
    
    for(int i=arr.size()-1; i>=0; i--) {
        if(arr[i] == 2) {
            ed = i;
            break;
        }    
    }
    
    for(int i=st; i<=ed; i++) {
        answer.push_back(arr[i]);
    }
    
    if(answer.size() == 0) answer.push_back(-1);
    
    return answer;
}