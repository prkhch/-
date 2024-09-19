#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) {
    vector<string> answer;
    
    int names_size = names.size();
    
    for(int i=0; i<names_size; i+=5) {
        answer.push_back(names[i]);
    }
    
    return answer;
}