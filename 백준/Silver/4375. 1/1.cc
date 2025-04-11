#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

int n;
while (cin >> n) {
    int len = 1;
    int remainder = 1 % n;
    while (remainder != 0) {
        remainder = (remainder * 10 + 1) % n;
        len++;
    }
    cout << len << '\n';
}

}