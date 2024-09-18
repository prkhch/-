#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    for(int i=0; i<myString.size(); i++) {
        myString[i] = myString[i] == 'A' ?  'B' : 'A';
    }  
    return myString.find(pat) == string::npos ? 0 : 1;
}