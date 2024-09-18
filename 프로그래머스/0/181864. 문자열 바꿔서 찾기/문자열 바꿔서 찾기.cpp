#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    for(char &c : myString) c = c == 'A' ? 'B' : 'A';
    return myString.find(pat) == string::npos ? 0 : 1;
}