#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> v(n, vector<int>(n));
    
    for(int i=0; i<v.size(); i++) {
        v[i][i] = 1;
    }
    
    return v;
}