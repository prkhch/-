#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    string star = "";
    star.reserve(n);
    
    for(int i=0; i<n; i++) {
        star+='*';
        cout << star << "\n";
    }
    
    return 0;
}