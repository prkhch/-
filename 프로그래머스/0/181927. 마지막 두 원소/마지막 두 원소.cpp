#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    
    int last_one = num_list[num_list.size()-1];
    int last_two = num_list[num_list.size()-2];
    
    if(last_one > last_two) {
        num_list.push_back(last_one - last_two);
    } else {
        num_list.push_back(last_one * 2);
    }
    
    return num_list;
}