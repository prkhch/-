#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {
    int alphabet[26] = {};
    
    for(char c : before) {
        alphabet[c-'a']++;
    }
    
    for(char c : after) {
        alphabet[c-'a']++;
    }
    
    for(int i : alphabet) {
        if(i%2 == 1) {
            return 0;
        }
    }
    
    return 1;
}