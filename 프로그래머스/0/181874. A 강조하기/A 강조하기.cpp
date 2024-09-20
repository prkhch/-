#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    
    for(char &c : myString) {
        if(c == 'a') {
            c = 'A';
        } else if('A' < c && c <= 'Z') {
            c+=32;
        }
    }
    
    return myString;
}
