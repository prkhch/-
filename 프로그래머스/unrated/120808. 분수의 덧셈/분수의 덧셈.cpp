#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int new_numer = (numer1 * denom2) + (numer2 * denom1);
    int new_denom = denom1 * denom2;
    
    for(int i=1; i<=new_numer; i++) {
        if( (new_numer % i == 0) && (new_denom % i == 0)) {
            new_numer /= i; new_denom /= i;
        }
    }
    
    for(int i=1; i<=new_denom; i++) {
        if( (new_numer % i == 0) && (new_denom % i == 0)) {
            new_numer /= i; new_denom /= i;
        }
    }
    
    answer.push_back(new_numer);
    answer.push_back(new_denom);
    
    return answer;
}