#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    istringstream iss(my_string);
    
    string str;
    while(iss >> str) {
        answer.push_back(str);
    }
    
    return answer;
}