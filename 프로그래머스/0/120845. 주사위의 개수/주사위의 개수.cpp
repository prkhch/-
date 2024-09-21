#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> box, int n) {
    for(int &i : box) i = i/n;
    return accumulate(box.begin(), box.end(), 1, multiplies<int>());
}