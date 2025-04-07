#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string &str, string demi) {
    int start = 0;
    int end = str.find(demi);
    vector<string> v;
    while(end != string::npos) {
        v.push_back(str.substr(start, end-start));
        start = end + demi.size();
        end = str.find(demi, start);
    }
    v.push_back(str.substr(start));
    
    return v;
}

vector<string> solution(string my_string) {
    vector<string> answer;
    
    answer = split(my_string, " ");

    return answer;
}