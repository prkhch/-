#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // today
    int today_year = stoi(today.substr(0, 4) ) * 12 * 28;
    int today_month = stoi(today.substr(5, 7) ) * 28;
    int today_day = stoi( today.substr(8, 10) );
    int today_all = today_year + today_month + today_day;
    
    // terms map
    map<char, int> m;
    int terms_size = terms.size();
    for(int i=0; i<terms_size; i++) {
        char key = (terms[i].substr(0, 1))[0];
        int value = stoi( terms[i].substr(2) );
        m[key] = value;
    }
    
    // privacies
    int pri_size = privacies.size();
    for(int i=0; i<pri_size; i++) {
        int cur_year = stoi( privacies[i].substr(0, 4) ) * 12 * 28;
        int cur_month = stoi( privacies[i].substr(5, 7) ) * 28;
        int cur_day = stoi( privacies[i].substr(8, 10) );
        int cur_all = cur_year + cur_month + cur_day;
        
        if(cur_all + (m[privacies[i].substr(11, 12)[0]] * 28) <= today_all ) {
            answer.push_back(i+1);
        } else {
            continue;
        }
        
    }
    
    return answer;
}