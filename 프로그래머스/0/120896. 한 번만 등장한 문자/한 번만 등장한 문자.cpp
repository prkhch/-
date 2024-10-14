#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int alphabet[26] = {};
    
    for(char c : s) 
        alphabet[c-'a']++;
    
    for(int i=0; i<26; i++)
        if(alphabet[i] == 1)
            answer += i+'a';
     
    return answer;
}