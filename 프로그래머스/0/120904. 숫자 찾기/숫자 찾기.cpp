#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    
    if((answer = to_string(num).find(to_string(k))) == string::npos)
        return -1;
    else
        return answer+1;
}