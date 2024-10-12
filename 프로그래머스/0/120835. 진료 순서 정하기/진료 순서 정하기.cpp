#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> sorted = emergency;
    sort(sorted.begin(), sorted.end(), greater<>());
    
    unordered_map<int, int> rank;
    for(int i=0; i<sorted.size(); i++) {
        rank[sorted[i]] = i+1;
    }
    
    vector<int> answer;
    for(int i : emergency) {
        answer.push_back(rank[i]);
    }
    
    return answer;
}