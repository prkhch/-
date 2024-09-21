#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string binomial) {
    
    stringstream ss(binomial);
    
    vector<string> v;
    string str;
    while(getline(ss, str, ' ')) {
        v.push_back(str);
    }
    
    if(v[1] == "+") {
        return stoi(v[0]) + stoi(v[2]);
    } else if(v[1] == "-") {
        return stoi(v[0]) - stoi(v[2]);
    } else {
        return stoi(v[0]) * stoi(v[2]);
    }
    
}