#include <bits/stdc++.h>

using namespace std;

int main() {

    int H, M;
    cin >> H >> M;

    int total = (H*60) + M;
    total -= 45;

    if(total<0) {
        total += 1440;
    }
    cout << total/60 << " " << total%60;

}