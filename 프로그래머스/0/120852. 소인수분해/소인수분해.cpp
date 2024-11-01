#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n) {
    set<int> s;
    
    while(n>1) {
        for(int i=2; i<=n; i++) {
            if(n%i == 0) {
                n/=i;
                s.insert(i);
                break;
            }
        }
    }
    
    vector<int> answer(s.begin(), s.end());
    return answer;
}