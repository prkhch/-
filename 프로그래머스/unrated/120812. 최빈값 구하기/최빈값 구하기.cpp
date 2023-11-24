#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    int count[1000] = {};
    for(int i=0; i<array.size(); i++) {
        count[array[i]] ++;
    }
    
    int max_count = 0;
    int max_idx = 0;
    bool same = false;
    for(int i=0; i<1000; i++) {
        if(max_count < count[i]) {
            max_count = count[i];
            max_idx = i;
            same = false;
        } else if(max_count == count[i]) {
            same = true;
        }
    }
    
    if(same == false) {
        answer = max_idx;
    } else {
        answer = -1;
    }
    return answer;
}