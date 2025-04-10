#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string pt;
    cin >> pt;
    auto it = pt.find("*");
    string pre = pt.substr(0, it);
    string suf = pt.substr(it + 1);

    for(int i=0; i<N; i++) {
        string str;
        cin >> str;

        if (pre.size() + suf.size() > str.size()) {
            cout << "NE" << "\n";
        } else if(str.substr(0, pre.size()) == pre && str.substr(str.size()-suf.size()) == suf) {
            cout << "DA" << "\n";
        } else {
            cout << "NE" << "\n";
        }

    }

}
