#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    
    for(int i=0; i<n; i++) {
        vector<char> tmp1;
        vector<char> tmp2;
        while(arr1[i] != 0) {
            tmp1.push_back(arr1[i] % 2 ? '1' : '0');
            arr1[i]/=2;
        }
        
        while(tmp1.size()<n) tmp1.push_back('0');
        
        while(arr2[i] != 0) {
            tmp2.push_back(arr2[i] % 2 ? '1' : '0');
            arr2[i]/=2;
        }
        
        while(tmp2.size()<n) tmp2.push_back('0');
        
        string ans = "";
        for(int j=n-1; j>=0; j--) {
            if(tmp1[j] == '0' && tmp2[j] == '0') {
                ans += " ";
            } else if(tmp1[j]=='1' | tmp2[j] =='1') {
                ans += "#";
            }
        }
        answer.push_back(ans);
    }
    
    return answer;  
}