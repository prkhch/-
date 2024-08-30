#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string one = "";
    string two = "";
    for(int i : num_list) {  
        i%2 == 0 ? two+=to_string(i) : one+=to_string(i); 
    }
    return stoi(one) + stoi(two);
}