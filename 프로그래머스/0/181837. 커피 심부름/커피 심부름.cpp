#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    
    unordered_map<string, int> m = {
        {"iceamericano", 4500},
        {"americanoice", 4500},
        {"hotamericano", 4500},
        {"americanohot", 4500},
        {"icecafelatte", 5000},
        {"cafelatteice", 5000},
        {"hotcafelatte", 5000},
        {"cafelattehot", 5000},
        {"americano", 4500},
        {"cafelatte", 5000},
        {"anything", 4500},
    };
    
    for(string s : order) {
        answer+=m[s];
    }
    
    return answer;
}