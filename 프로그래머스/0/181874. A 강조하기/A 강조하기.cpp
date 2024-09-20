#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string myString) {
    for(char &c : myString) {
        if(c == 'a') {
            c = 'A';
        } else if (c == ' ' || c == 'A') {
            continue;
        } else if (c < 97) {
            c = c + 32;
        }
    }
    
    return myString;
}

// a = 97
// A = 65