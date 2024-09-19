#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    
    size_t pos = 0;
    
    while(rny_string.find("m") != string::npos) {
        pos = rny_string.find("m");
        rny_string.replace(pos, 1, "rn");
    }
    
    return rny_string;
}