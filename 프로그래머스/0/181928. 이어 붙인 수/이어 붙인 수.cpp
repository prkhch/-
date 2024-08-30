#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string one = "";
    string two = "";
    for(int i=0; i<num_list.size(); i++) {
        if(num_list[i]%2 == 0) {
            two += to_string(num_list[i]);
        } else {
            one += to_string(num_list[i]);
        }
    }
    return stoi(one) + stoi(two);
}