#include <bits/stdc++.h>
using namespace std;

int A, B;

int main() {
    
    cin >> A >> B;
    
    cout << A * (B%10) << "\n";
    cout << A * ((B%100)/10) << "\n";
    cout << A * (B/100) << "\n";
    cout << A * B << "\n";
    
}