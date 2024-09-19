#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    
    for(char &c : rsp) {
        c = c == '2' ? '0' : (c == '0' ? '5' : '2');
    }
    
    return rsp;
    
}