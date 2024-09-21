#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    
    size_t pos = 0, st = 0;
    
    while((pos = myString.find('x', st)) != string::npos) {
        answer.push_back(pos - st);
        st = pos+1;
    }
    
    answer.push_back(myString.length()-st);
    
    return answer;
}