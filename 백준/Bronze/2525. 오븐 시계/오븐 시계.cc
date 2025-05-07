#include <bits/stdc++.h>

using namespace std;

int A, B, C;

int main() {

    cin >> A >> B >> C;

    int total = (A * 60) + B + C;

    cout << (total / 60) % 24 << " " << total%60;

}


