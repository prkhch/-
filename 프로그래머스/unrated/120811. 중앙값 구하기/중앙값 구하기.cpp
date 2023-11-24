#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> array) {
    
    sort(array.begin(), array.end());
    int array_size = array.size();
    int answer = array[array_size/2];
    
    return answer;
}