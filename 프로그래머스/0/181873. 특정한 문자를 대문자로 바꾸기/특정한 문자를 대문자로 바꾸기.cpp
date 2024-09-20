#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    char calp = alp[0];
    
    for(char &c : my_string) {
        c = c == calp ? c-32 : c;
    }
    
    return my_string;
}