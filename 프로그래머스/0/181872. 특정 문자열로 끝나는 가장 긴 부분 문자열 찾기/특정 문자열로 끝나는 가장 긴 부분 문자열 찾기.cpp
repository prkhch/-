#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    size_t pos = 0;
    while(myString.find(pat, pos) != string::npos) {
        pos = myString.find(pat, pos) + pat.length();
    }
    return myString.substr(0, pos);
}